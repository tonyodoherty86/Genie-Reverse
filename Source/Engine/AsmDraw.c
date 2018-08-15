
/**
 * @file    Engine\AsmDraw.c
 * @author  Yvan Burrie
 * @date    2018/08/12
 * @version 1.0
 */

#ifndef ASM_DRAW_H
    #include "AsmDraw.h"
#endif

#ifndef ASM_DRAW_C
    #define ASM_DRAW_C
#endif

/**
 *
 */
static int ASM_Fast_Count;

/**
 * @brief The current display offsets from a draw-area.
 *
 * dword_88C000 (ROR)
 *
 * AKA: DisplayOffsets
 */
static void **ASMRenderOffsets;

/**
 * dword_88C004 (ROR)
 */
static VSpan_Node **ASMLineHeadPtrs;

/**
 * dword_88C008 (ROR)
 */
static VSpan_Node **ASMLineTailPtrs;

/**
 * dword_88C014 (ROR)
 */
static int ASMCurrentRenderXOffset;

/**
 * dword_88C01C (ROR)
 */
static int ASMXlate;

/**
 * dword_88C020 (ROR)
 */
static int ASMCurrentRenderYOffset;

/**
 *
 */
static int dword_88C02C;

/**
 *
 */
static int dword_88C030;

/**
 *
 */
static int dword_88C034;

/**
 * dword_88C038 (ROR)
 */
static int ASMDrawYOffset;

/**
 * dword_88C03C (ROR)
 */
static VSpan_Node *ASMCurrentLineHead;

/**
 * dword_88C040 (ROR)
 * AKA: XformMask
 */
static int ASMColorXForm1;

static int ASMColorXForm2;

static int ASMColorXForm3;

/**
 * dword_88C044 (ROR)
 * dword_795044 (AOC)
 */
static void *ASMLocation;

/**
 * dword_88C04C (ROR)
 */
static int ASMCurrentLineHeadPx;

/**
 * dword_88C060 (ROR)
 */
static int ASMShadowing1A;

/**
 * dword_88C064 (ROR)
 */
static int ASMShadowing3A;

/**
 * dword_88C068 (ROR)
 */
static int ASMShadowing1B;

/**
 * dword_88C06C (ROR)
 */
static int ASMShadowing3B;

/**
 * dword_88C070 (ROR)
 */
static int ASMShadowing2A;

/**
 * dword_88C074 (ROR)
 */
static int ASMShadowing4A;

/**
 * dword_88C078 (ROR)
 */
static int ASMShadowing2B;

/**
 * dword_88C07C (ROR)
 */
static int ASMShadowing4B;

/**
 * dword_88C080 (ROR)
 */
static int ASMMinLine;

/**
 * dword_88C084 (ROR)
 */
static int ASMMaxLine;

/**
 * dword_88C088 (ROR)
 */
static int ASMMinSpanPx;

/**
 * dword_88C08C (ROR)
 */
static int ASMMaxSpanPx;

/**
 * dword_7950A0 (AOC)
 */
static void *dword_7950A0;

static int ASMDrawXFinish;
static int ASMDrawYFinish;

static int dword_7950AC;
static void **dword_7950B0;

static int ASMDrawXStart;

static int dword_795028;
static int dword_79500C;
static int dword_795010;

////////////////////////////////////////////////////////////////////////////////////////////////////

#define ASM_JUMP_TO_LOC asm("jmp %0" : "=r" (ASMLocation) : : ); // return ASMLocation();

void SHAPE_DRAW_PROCS( void )
{
    ASM_JUMP_TO_LOC;
};

void sub_563006( char *a1, char *a2 )
{
    *a1 = *a2;

    ASM_JUMP_TO_LOC;
};

////////////////////////////////////////////////////////////////////////////////////////////////////

void ASMSet_Shadowing(
    int a1,
    int a2,
    int a3,
    int a4 )
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
    void **DisplayOffsets,
    VSpan_Node **LineHeadPtrs,
    VSpan_Node **LineTailPtrs,
    int MinSpanPx,
    int MinLine,
    int MaxSpanPx,
    int MaxLine )
{
    ASMRenderOffsets = DisplayOffsets;
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
    asm("push    ebp");
    asm("mov     ebp, esp");
    asm("mov     eax, [ebp+8]");
    asm("mov     cl, al");
    asm("mov     ah, al");
    asm("bswap   eax");
    asm("mov     al, cl");
    asm("mov     ah, cl");
    asm("mov     %0, eax" : "=r" (ASMColorXForm1) : : );
    asm("pop     ebp");
    asm("ret");
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void ASMSet_Color_XformEx( unsigned int a1, unsigned int a2 )
{
    asm("a1= 8");
    asm("a2= 12");

    asm("push    ebp");

    asm("mov     ebp, esp");

    asm("mov     eax, [ebp+a1]");
    asm("mov     cl, al");
    asm("mov     ah, al");
    asm("bswap   eax");
    asm("mov     al, cl");
    asm("mov     ah, cl");
    asm("mov     %0, eax" : "=r" (ASMColorXForm2) : : );

    asm("mov     eax, [ebp+a2]");
    asm("mov     cl, al");
    asm("mov     ah, al");
    asm("bswap   eax");
    asm("mov     al, cl");
    asm("mov     ah, cl");
    asm("mov     %0, eax" : "=r" (ASMColorXForm3) : : );

    asm("pop     ebp");

    asm("ret");
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int ASMGet_Color_Xform( void )
{
    return ASMColorXForm1;
}

int ASMGet_Color_Xform2( void )
{
    return ASMColorXForm2;
}

int ASMGet_Color_Xform3( void )
{
    return ASMColorXForm3;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void ASMSet_Xlate_Table( int ColorTable )
{
    ASMXlate = ColorTable;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int ASMGet_Xlate_Table( void )
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

    VSpan_Node *LineHead = ASMLineHeadPtrs[y1];
    if( LineHead == NULL ){
        return;
    }

    ASMCurrentLineHead = ASMLineHeadPtrs[y1];

    int tempx = xmax;

    ASMDrawYOffset = xmin - xmax + 1;

    ASMLocation = &&loc_56C99A;

    ASMCurrentRenderYOffset = (int)ASMRenderOffsets[y1];

    xmax += ASMCurrentRenderYOffset;

    ASMCurrentRenderXOffset = xmax;

    while( xmin >= LineHead->StartPx ){

        if( tempx <= LineHead->EndPx ){
            if( tempx >= LineHead->StartPx &&
                xmin <= LineHead->EndPx ){

                int v8 = ASMDrawYOffset & 127;
                if( ASMDrawYOffset >= 128 ){
                    v8 |= 128;
                }
                //JUMPOUT(__CS__, off_56A700[(byte_56B300[v8] | ASMCurrentRenderXOffset & 3)]);
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
                        v11 |= 128;
                    }
                    //JUMPOUT(__CS__, off_56A700[(byte_56B300[v11] | (ASMCurrentLineHeadPx + ASMCurrentRenderXOffset) & 3)]);
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
            //EscapeDrawHLine:
            loc_56C99A:
            return;
        }
    }
}

static int dword_795034;
static int dword_795048;
static int dword_795054;

static char byte_631300;
static char byte_633B20;
static char byte_6340C0;

static int a_l_l_l_l_l_l_1;

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
    asm("push   ebp");

    asm("mov    ebp, esp");

    asm("push   ebx");
    asm("push   esi");
    asm("push   edi");

	int temp_int;

    asm("mov    eax, [ebp+0x08]");
    asm("mov    ecx, [ebp+0x10]");
    asm("xor    edx, edx");
    asm("lea    ebx, [ecx+eax-1]");
    asm("cmp    ebx, ASMMinLine");
    asm("jl     loc_6336D4");
    asm("cmp    eax, ASMMaxLine");
    asm("jg     loc_6336D4");
    asm("cmp    eax, ASMMinLine");
    asm("jge    short loc_632C04");
    asm("mov    edx, ASMMinLine");
    asm("sub    edx, eax");
    asm("xor    eax, eax");
    asm("sub    ecx, edx");
    asm("shl    edx, 2");
    asm("mov    [ebp+0x08], eax");

    loc_632C04:
    asm("cmp    ebx, ASMMaxLine");
    asm("jle    short loc_632C14");
    asm("sub    ebx, ASMMaxLine");
    asm("sub    ecx, ebx");

    loc_632C14:
    asm("mov    [ebp+0x10], ecx");
    asm("xor    ebx, ebx");
    asm("mov    ASMDrawYOffset, ebx");
    ASMDrawXStart = DrawX;// eax
	if( ASMDrawXStart > ASMMaxSpanPx ){
		goto loc_6336D4;
	}
	dword_795028 = ASMDrawXStart + DrawW - 1;// eax
	if( dword_795028 < ASMMinSpanPx ){
		goto loc_6336D4;
	}
    asm("mov    eax, [ebp+0x14]");// dword_79500C = [ebp+0x14] + [ebp+0x08] + edx;
    asm("add    eax, [ebp+0x08]");
    asm("add    eax, edx");
    asm("mov    dword_79500C, eax");
    asm("mov    eax, [ebp+0x18]");// dword_795010 = [ebp+0x18] + [ebp+0x08] + edx;
    asm("add    eax, [ebp+0x08]");
    asm("add    eax, edx");
    asm("mov    dword_795010, eax");
    asm("mov    eax, [ebp+0x1C]");
    temp_int = 0;
    asm("test   eax, 1");
    asm("jz     short loc_632C75");
    temp_int = 0x80;
    goto loc_632C91;

    loc_632C75:
    asm("mov    ebx, ASMColorXForm1");
    dword_88C030 = temp_int;
    dword_88C02C = -1;
    dword_795034 = ASMColorXForm1;

    loc_632C91:
    dword_795048 = temp_int;
    asm("test   eax, 2");
    asm("jnz    loc_6336E0");

	/* NOTE: some useless crap removed here. */
    asm("mov    eax, eax");

    loc_632CC0:
    asm("mov    eax, [ebp+0x08]");
    asm("mov    ebx, ASMDrawYOffset");
    asm("add    eax, ebx");
    asm("mov    esi, ASMLineHeadPtrs");
    asm("mov    edi, [esi+eax*4]");
    asm("or     edi, edi");
    asm("jz     loc_6336C0");
    asm("mov    ASMCurrentLineHead, edi");
    asm("mov    ecx, ASMColorXForm2");
    asm("mov    ASMColorXForm1, ecx");
    asm("test   byte ptr dword_795048, 0x80");
    asm("jz     short loc_632D22");
    asm("and    eax, 3");
    asm("mov    edx, ASMShadowing2A[eax*4]");
    asm("mov    ecx, ASMShadowing1A[eax*4]");
    asm("mov    eax, ASMColorXForm1");
    asm("mov    dword_88C030, edx");
    asm("mov    dword_88C02C, ecx");
    asm("and    eax, ecx");
    asm("or     eax, edx");
    asm("mov    dword_795034, eax");

    loc_632D22:
    asm("mov    esi, dword_795010");
    asm("xor    eax, eax");
    asm("mov    ax, [esi+ebx*4]");
    asm("mov    edx, ASMDrawXStart");
    asm("test   eax, 0x8000");
    asm("jnz    loc_6336C0");
    asm("add    edx, eax");
    asm("mov    ax, [esi+ebx*4+2]");
    asm("mov    ecx, dword_795028");
    asm("sub    ecx, eax");
    asm("mov    esi, ASMRenderOffsets");
    asm("mov    eax, [ebp+0x08]");
    asm("add    eax, ebx");
    asm("mov    eax, [esi+eax*4]");
    asm("mov    ASMCurrentRenderYOffset, eax");
    asm("add    eax, edx");
    asm("mov    ASMCurrentRenderXOffset, eax");
    asm("mov    esi, dword_79500C");
    asm("mov    eax, [esi+ebx*4]");
    asm("add    eax, [ebp+0x08]");
    asm("mov    dword_795018, eax");

    loc_632D79:
    asm("cmp    ecx, [edi+8]");
    asm("jl     loc_6336C0");
    asm("cmp    edx, [edi+12]");
    asm("jle    short loc_632D92");
    asm("mov    edi, [edi]");
    asm("or     edi, edi");
    asm("jnz    short loc_632D79");
    goto loc_6336C0;

    loc_632D92:
    asm("cmp    edx, [edi+8]");
    asm("jl     short loc_632DB7");
    asm("cmp    ecx, [edi+12]");
    asm("jg     short loc_632DB7");
	ASMLocation = &&loc_6333C0;// eax
    asm("mov    edi, ASMCurrentRenderXOffset");
    asm("mov    esi, dword_795018");
    goto loc_6333C0;

    loc_632DB7:
	ASMLocation = &&loc_632E40;// eax
    asm("mov    ASMCurrentLineHead, edi");
    asm("mov    edi, ASMCurrentRenderXOffset");
    asm("mov    esi, dword_795018");
    goto loc_632E40;

    loc_632DE0:
    asm("mov    esi, dword_795050");
    asm("mov    edi, dword_795054");
    asm("mov    ebx, ASMCurrentLineHead");
    asm("mov    ebx, [ebx]");
    asm("or     ebx, ebx");
    asm("jz     loc_6336C0");
	ASMLocation = &&loc_632E40;
    asm("xor    eax, eax");
    asm("mov    al, [esi]");
    asm("sub    edi, ASMCurrentRenderYOffset");
    asm("mov    ecx, eax");
    asm("inc    esi");
    asm("and    eax, 0x0F");
    asm("mov    ASMCurrentLineHead, ebx");
    asm("jmp    off_631400[eax*4]");

    loc_632E40:
    asm("mov    dword_795050, esi");
    asm("xor    eax, eax");
    asm("mov    dword_795054, edi");
    asm("mov    al, [esi]");
    asm("sub    edi, ASMCurrentRenderYOffset");
    asm("mov    ecx, eax");
    asm("inc    esi");
    asm("and    eax, 0x0F");
    asm("mov    ebx, ASMCurrentLineHead");
    asm("jmp    off_631400[eax*4]");

    loc_632E80:
    asm("mov    eax, ecx");
    asm("shr    eax, 4");
    asm("jmp    off_631480[eax*4]");

    loc_632EA0:
    asm("shr    ecx, 2");
    goto loc_632EAB;

    loc_632EA5:
    asm("shl    ecx, 4");
    asm("mov    cl, [esi]");
    asm("inc    esi");

    loc_632EAB:
    asm("mov    edx, edi");
    asm("add    edx, ecx");
    asm("dec    edx");

    loc_632EB0:
    asm("cmp    edx, [ebx+8]");
    asm("jl     short loc_632F12");
    asm("cmp    edi, [ebx+12]");
    asm("jg     short loc_632F21");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+8]");
    asm("jge    short loc_632ECA");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edi");
    asm("add    esi, eax");
    asm("sub    ecx, eax");

    loc_632ECA:
    asm("mov    ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+12]");
    asm("jle    short loc_632EE5");
    asm("mov    eax, edx");
    asm("sub    eax, [ebx+12]");
    asm("sub    ecx, eax");
    ASMLocation = &&loc_632DE0;

    loc_632EE5:
    asm("mov    edi, dword_795054");
    asm("xor    ebx, ebx");
    asm("add    edi, ASMCurrentLineHeadPx");
    asm("sub    bl, ch");
    asm("mov    eax, edi");
    asm("and    bl, 0x80");
    asm("and    eax, 3");
    asm("or     bl, cl");
    asm("or     al, byte ptr dword_795048");
    asm("or     al, byte_631300[ebx]");
    asm("jmp    off_630300[eax*4]");

    loc_632F12:
    asm("mov    edi, dword_795054");
    asm("add    esi, ecx");
    asm("add    edi, ecx");
    goto loc_632E40;

    loc_632F21:
    asm("mov    ebx, [ebx]");
    asm("or     ebx, ebx");
    asm("jnz    short loc_632EB0");
    goto loc_6336C0;

    loc_632F40:
    asm("shr    ecx, 2");
    asm("mov    edi, dword_795054");
    asm("add    edi, ecx");
    goto ASMLocation;

    loc_632F51:
    asm("shl    ecx, 4");
    asm("mov    edi, dword_795054");
    asm("mov    cl, [esi]");
    asm("inc    esi");
    asm("add    edi, ecx");
    goto ASMLocation;

    loc_632F80:
    asm("shr    ecx, 4");
    asm("jnz    short loc_632F88");
    asm("mov    cl, [esi]");
    asm("inc    esi");

    loc_632F88:
    asm("mov    edx, edi");
    asm("add    edx, ecx");
    asm("dec    edx");

    loc_632F8D:
    asm("cmp    edx, [ebx+8]");
    asm("jl     short loc_632FEC");
    asm("cmp    edi, [ebx+12]");
    asm("jg     short loc_632FFB");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+8]");
    asm("jge    short loc_632FA7");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edi");
    asm("add    esi, eax");
    asm("sub    ecx, eax");

    loc_632FA7:
    asm("mov    ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+12]");
    asm("jle    short loc_632FC2");
    asm("mov    eax, edx");
    asm("sub    eax, [ebx+12]");
    asm("sub    ecx, eax");
    ASMLocation = &&loc_632DE0;

    loc_632FC2:
    asm("mov    edi, dword_795054");
    asm("add    edi, ASMCurrentLineHeadPx");
    asm("mov    eax, edi");
    asm("and    eax, 3");
    asm("or     al, byte_631300[ecx]");
    asm("mov    ebx, ASMColorXForm1");
    asm("or     al, byte ptr dword_795048");
    asm("jmp    off_630B00[eax*4]");

    loc_632FEC:
    asm("mov    edi, dword_795054");
    asm("add    esi, ecx");
    asm("add    edi, ecx");
    goto loc_632E40;

    loc_632FFB:
    asm("mov    ebx, [ebx]");
    asm("or     ebx, ebx");
    asm("jnz    short loc_632F8D");
    goto loc_6336C0;

    loc_633020:
    asm("shr    ecx, 4");
    asm("jnz    short loc_633028");
    asm("mov    cl, [esi]");
    asm("inc    esi");

    loc_633028:
    asm("mov    edx, edi");
    asm("add    edx, ecx");
    asm("dec    edx");

    loc_63302D:
    asm("cmp    edx, [ebx+8]");
    asm("jl     short loc_63309C");
    asm("cmp    edi, [ebx+12]");
    asm("jg     short loc_6330AA");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+8]");
    asm("jge    short loc_633045");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edi");
    asm("sub    ecx, eax");

    loc_633045:
    asm("mov    ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+12]");
    asm("jle    short loc_633060");
    asm("mov    eax, edx");
    asm("sub    eax, [ebx+12]");
    asm("sub    ecx, eax");
	ASMLocation = &&loc_632DE0;

    loc_633060:
    asm("mov    edi, dword_795054");
    asm("mov    al, [esi]");
    asm("add    edi, ASMCurrentLineHeadPx");
    asm("mov    ah, al");
    asm("mov    ebx, edi");
    asm("shl    eax, 0x10");
    asm("and    ebx, 3");
    asm("mov    al, [esi]");
    asm("or     bl, byte_631300[ecx]");
    asm("mov    ah, al");
    asm("or     bl, byte ptr dword_795048");
    asm("and    eax, dword_88C02C");
    asm("or     eax, dword_88C030");
    asm("inc    esi");
    asm("jmp    off_630700[ebx*4]");

    loc_63309C:
    asm("mov    edi, dword_795054");
    asm("inc    esi");
    asm("add    edi, ecx");
    goto loc_632E40;

    loc_6330AA:
    asm("mov    ebx, [ebx]");
    asm("or     ebx, ebx");
    asm("jnz    loc_63302D");
    goto loc_6336C0;

    loc_6330C0:
    asm("shr    ecx, 4");
    asm("jnz    short loc_6330C8");
    asm("mov    cl, [esi]");
    asm("inc    esi");

    loc_6330C8:
    asm("mov    edx, edi");
    asm("add    edx, ecx");
    asm("dec    edx");

    loc_6330CD:
    asm("cmp    edx, [ebx+8]");
    asm("jl     short loc_63313C");
    asm("cmp    edi, [ebx+12]");
    asm("jg     short loc_63314A");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+8]");
    asm("jge    short loc_6330E5");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edi");
    asm("sub    ecx, eax");

    loc_6330E5:
    asm("mov    ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+12]");
    asm("jle    short loc_633100");
    asm("mov    eax, edx");
    asm("sub    eax, [ebx+12]");
    asm("sub    ecx, eax");
    asm("mov    ASMLocation,    offset loc_632DE0");

    loc_633100:
    asm("mov    edi, dword_795054");
    asm("mov    al, [esi]");
    asm("add    edi, ASMCurrentLineHeadPx");
    asm("mov    ah, al");
    asm("mov    ebx, edi");
    asm("shl    eax, 0x10");
    asm("and    ebx, 3");
    asm("mov    al, [esi]");
    asm("or     bl, byte_631300[ecx]");
    asm("mov    ah, al");
    asm("or     bl, byte ptr dword_795048");
    asm("inc    esi");
    asm("and    eax, dword_88C02C");
    asm("or     eax, dword_795034");
    asm("jmp    off_630700[ebx*4]");

    loc_63313C:
    asm("mov    edi, dword_795054");
    asm("inc    esi");
    asm("add    edi, ecx");
    goto loc_632E40;

    loc_63314A:
    asm("mov    ebx, [ebx]");
    asm("or     ebx, ebx");
    asm("jnz    loc_6330CD");
    goto loc_6336C0;

    loc_633160:
    asm("shr    ecx, 4");
    asm("jnz    short loc_633168");
    asm("mov    cl, [esi]");
    asm("inc    esi");

    loc_633168:
    asm("mov    edx, edi");
    asm("add    edx, ecx");
    asm("dec    edx");

    loc_63316D:
    asm("cmp    edx, [ebx+8]");
    asm("jl     short loc_6331CC");
    asm("cmp    edi, [ebx+12]");
    asm("jg     short loc_6331D9");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+8]");
    asm("jge    short loc_633185");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edi");
    asm("sub    ecx, eax");

    loc_633185:
    asm("mov    ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+12]");
    asm("jle    short loc_6331A0");
    asm("mov    eax, edx");
    asm("sub    eax, [ebx+12]");
    asm("sub    ecx, eax");
    asm("mov    ASMLocation, offset loc_632DE0");

    loc_6331A0:
    asm("mov    edi, dword_795054");
    asm("add    edi, ASMCurrentLineHeadPx");
    asm("mov    eax, edi");
    asm("and    eax, 3");
    asm("xor    edx, edx");
    asm("or     al, byte_631300[ecx]");
    asm("mov    ebx, ASMXlate");
    asm("or     al, byte ptr dword_795048");
    asm("jmp    off_630F00[eax*4]");

    loc_6331CC:
    asm("mov    edi, dword_795054");
    asm("add    edi, ecx");
    goto loc_632E40;

    loc_6331D9:
    asm("mov    ebx, [ebx]");
    asm("or     ebx, ebx");
    asm("jnz    short loc_63316D");
    goto loc_6336C0;

    loc_633200:
    asm("xor    ecx, ecx");
    asm("mov    eax, dword_795098");
    asm("mov    cl, [esi]");
    asm("mov    dword_795090, eax");
    asm("inc    esi");
    asm("mov    eax, 2");
    goto loc_63326A;

    loc_633216:
    asm("mov    eax, dword_795098");
    asm("mov    ecx, 1");
    asm("mov    dword_795090, eax");
    asm("mov    eax, 2");
    goto loc_63326A;

    loc_633240:
    asm("xor    ecx, ecx");
    asm("mov    eax, dword_795094");
    asm("mov    cl, [esi]");
    asm("mov    dword_795090, eax");
    asm("inc    esi");
    asm("mov    eax, 1");
    goto loc_63326A;

    loc_633256:
    asm("mov    eax, dword_795094");
    asm("mov    ecx, 1");
    asm("mov    dword_795090, eax");
    asm("mov    eax, 1");

    loc_63326A:
    asm("test   dword_79509C, eax");
    asm("jz     short loc_6332DF");
    asm("mov    edx, edi");
    asm("add    edx, ecx");
    asm("dec    edx");

    loc_633277:
    asm("cmp    edx, [ebx+8]");
    asm("jl     short loc_6332DF");
    asm("cmp    edi, [ebx+12]");
    asm("jg     short loc_6332EC");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+8]");
    asm("jge    short loc_63328F");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edi");
    asm("sub    ecx, eax");

    loc_63328F:
    asm("mov    ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+12]");
    asm("jle    short loc_6332AA");
    asm("mov    eax, edx");
    asm("sub    eax, [ebx+12]");
    asm("sub    ecx, eax");
    ASMLocation = &&loc_632DE0;

    loc_6332AA:
    asm("mov    edi, dword_795054");
    asm("mov    eax, dword_795090");
    asm("add    edi, ASMCurrentLineHeadPx");
    asm("and    eax, dword_88C02C");
    asm("mov    ebx, edi");
    asm("or     eax, dword_88C030");
    asm("and    ebx, 3");
    asm("or     bl, byte_631300[ecx]");
    asm("or     bl, byte ptr dword_795048");
    asm("jmp    off_630700[ebx*4]");

    loc_6332DF:
    asm("mov    edi, dword_795054");
    asm("add    edi, ecx");
    goto loc_632E40;

    loc_6332EC:
    asm("mov    ebx, [ebx]");
    asm("or     ebx, ebx");
    asm("jnz    short loc_633277");
    goto loc_6336C0;

    loc_633300:
    asm("call   sub_634100");
    asm("add    edi, ecx");
    goto loc_632E40;

    loc_633320:
    asm("mov    eax, ASMColorXForm2");
    asm("mov    ASMColorXForm1, eax");
    asm("int    3");
    asm("and    eax, dword_88C02C");
    asm("or     edx, dword_88C030");
    asm("mov    dword_795034, eax");
    goto loc_632E40;

    loc_633360:
    asm("mov    eax, ASMColorXForm3");
    asm("mov    ASMColorXForm1, eax");
    asm("int    3");
    asm("and    eax, dword_88C02C");
    asm("or     edx, dword_88C030");
    asm("mov    dword_795034, eax");
    goto loc_632E40;

    /* TODO */
    asm("byte_6333A0    db 0xCC");
    goto loc_632E40;

    loc_6333C0:
    asm("xor    eax, eax");
    asm("mov    al, [esi]");
    asm("mov    ecx, eax");
    asm("and    eax, 0x0F");
    asm("inc    esi");
    asm("jmp    off_631440[eax*4]");

    loc_6333E0:
    asm("mov    eax, ecx");
    asm("shr    eax, 4");
    asm("jmp    off_6314C0[eax*4]");

    loc_633400:
    asm("shr    ecx, 2");
    asm("mov    eax, edi");
    asm("and    eax, 3");
    asm("or     al, byte_631300[ecx]");
    asm("or     al, byte ptr dword_795048");
    asm("jmp    off_630300[eax*4]");

    loc_633420:
    asm("shl    ecx, 4");
    asm("xor    ebx, ebx");
    asm("mov    cl, [esi]");
    asm("sub    bl, ch");
    asm("mov    eax, edi");
    asm("and    bl, 0x80");
    asm("and    eax, 3");
    asm("or     bl, cl");
    asm("or     al, byte ptr dword_795048");
    asm("or     al, byte_631300[ebx]");
    asm("inc    esi");
    asm("jmp    off_630300[eax*4]");

    loc_633460:
    asm("shr    ecx, 2");
    asm("add    edi, ecx");
    goto ASMLocation;

    loc_63346B:
    asm("shl    ecx, 4");
    asm("mov    cl, [esi]");
    asm("inc    esi");
    asm("add    edi, ecx");
    goto ASMLocation;

    loc_633480:
    asm("shr    ecx, 4");
    asm("jnz    short loc_633488");
    asm("mov    cl, [esi]");
    asm("inc    esi");

    loc_633488:
    asm("mov    eax, edi");
    asm("and    eax, 3");
    asm("or     al, byte_631300[ecx]");
    asm("mov    ebx, ASMColorXForm1");
    asm("or     al, byte ptr dword_795048");
    asm("jmp    off_630B00[eax*4]");

    loc_6334C0:
    asm("shr    ecx, 4");
    asm("jnz    short loc_6334C8");
    asm("mov    cl, [esi]");
    asm("inc    esi");

    loc_6334C8:
    asm("mov    al, [esi]");
    asm("mov    ebx, edi");
    asm("mov    ah, al");
    asm("and    ebx, 3");
    asm("shl    eax, 0x10");
    asm("or     bl, byte_631300[ecx]");
    asm("mov    al, [esi]");
    asm("or     bl, byte ptr dword_795048");
    asm("inc    esi");
    asm("mov    ah, al");
    asm("and    eax, dword_88C02C");
    asm("or     eax, dword_88C030");
    asm("jmp    off_630700[ebx*4]");

    loc_633500:
    asm("shr    ecx, 4");
    asm("jnz    short loc_633508");
    asm("mov    cl, [esi]");
    asm("inc    esi");

    loc_633508:
    asm("mov    al, [esi]");
    asm("mov    ebx, edi");
    asm("mov    ah, al");
    asm("and    ebx, 3");
    asm("shl    eax, 0x10");
    asm("or     bl, byte_631300[ecx]");
    asm("mov    al, [esi]");
    asm("or     bl, byte ptr dword_795048");
    asm("inc    esi");
    asm("mov    ah, al");
    asm("and    eax, dword_88C02C");
    asm("or     eax, dword_795034");
    asm("jmp    off_630700[ebx*4]");

    loc_633540:
    asm("shr    ecx, 4");
    asm("jnz    short loc_633548");
    asm("mov    cl, [esi]");
    asm("inc    esi");

    loc_633548:
    asm("mov    eax, edi");
    asm("and    eax, 3");
    asm("or     al, byte_631300[ecx]");
    asm("mov    ebx, ASMXlate");
    asm("or     al, byte ptr dword_795048");
    asm("xor    edx, edx");
    asm("jmp    off_630F00[eax*4]");

    loc_633580:
    asm("xor    ecx, ecx");
    asm("mov    eax, dword_795098");
    asm("mov    cl, [esi]");
    asm("mov    dword_795090, eax");
    asm("inc    esi");
    asm("mov    eax, 2");
    goto loc_6335EA;

    loc_633596:
    asm("mov    eax, dword_795098");
    asm("mov    ecx, 1");
    asm("mov    dword_795090, eax");
    asm("mov    eax, 2");
    goto loc_6335EA;

    loc_6335C0:
    asm("xor    ecx, ecx");
    asm("mov    eax, dword_795094");
    asm("mov    cl, [esi]");
    asm("mov    dword_795090, eax");
    asm("inc    esi");
    asm("mov    eax, 1");
    goto loc_6335EA;

    loc_6335D6:
    asm("mov    eax, dword_795094");
    asm("mov    ecx, 1");
    asm("mov    dword_795090, eax");
    asm("mov    eax, 1");

    loc_6335EA:
    asm("test   dword_79509C, eax");
    asm("jz     short loc_63361B");
    asm("mov    eax, dword_795090");
    asm("mov    ebx, edi");
    asm("and    eax, dword_88C02C");
    asm("and    ebx, 3");
    asm("or     eax, dword_88C030");
    asm("or     bl, byte_631300[ecx]");
    asm("or     bl, byte ptr dword_795048");
    asm("jmp    off_630700[ebx*4]");

    loc_63361B:
    asm("add    edi, ecx");
    goto ASMLocation;

    loc_633640:
    asm("call   sub_634100");
    asm("add    edi, ecx");
    goto loc_6333C0;

    loc_633660:
    asm("mov    eax, ASMColorXForm2");
    asm("mov    ASMColorXForm1, eax");
    asm("and    eax, dword_88C02C");
    asm("or     edx, dword_88C030");
    asm("mov    dword_795034, eax");
    goto loc_6333C0;

    loc_633680:
    asm("mov    eax, ASMColorXForm3");
    asm("mov    ASMColorXForm1, eax");
    asm("and    eax, dword_88C02C");
    asm("or     edx, dword_88C030");
    asm("mov    dword_795034, eax");
    goto loc_6333C0;

    /* TODO */
    asm("byte_6336A0    db 0xCC");
    goto loc_632E40;

    /* TODO */
    asm("byte_6336A6    db 0xCC");
    goto ASMLocation;

    loc_6336C0:
    asm("mov    eax, ASMDrawYOffset");
    asm("inc    eax");
    asm("mov    ASMDrawYOffset, eax");
    asm("cmp    eax, [ebp+0x10]");
    asm("jl     loc_632CC0");

    loc_6336D4:
    asm("pop    edi");
    asm("pop    esi");
    asm("pop    ebx");
    asm("pop    ebp");

    /* TODO */
    asm("ret");

    loc_6336E0:
    asm("mov    eax, [ebp+0x08]");
    asm("mov    ebx, ASMDrawYOffset");
    asm("add    eax, ebx");
    asm("mov    esi, ASMLineTailPtrs");
    asm("mov    edi, [esi+eax*4]");
    asm("or     edi, edi");
    asm("jz     loc_6340E0");
    asm("mov    ASMCurrentLineHead, edi");
    asm("mov    ecx, ASMColorXForm2");
    asm("mov    ASMColorXForm1, ecx");
    asm("test   byte ptr dword_795048, 0x80");
    asm("jz     short loc_633742");
    asm("and    eax, 3");
    asm("mov    edx, ASMShadowing2A[eax*4]");
    asm("mov    ecx, ASMShadowing1A[eax*4]");
    asm("mov    eax, ASMColorXForm1");
    asm("mov    dword_88C030, edx");
    asm("mov    dword_88C02C, ecx");
    asm("and    eax, ecx");
    asm("or     eax, edx");
    asm("mov    dword_795034, eax");

    loc_633742:
    asm("mov    esi, dword_795010");
    asm("xor    eax, eax");
    asm("mov    ax, [esi+ebx*4+2]");
    asm("mov    edx, ASMDrawXStart");
    asm("test   eax, 0x8000");
    asm("jnz    loc_6340E0");
    asm("add    edx, eax");
    asm("mov    ax, [esi+ebx*4]");
    asm("mov    ecx, dword_795028");
    asm("sub    ecx, eax");
    asm("mov    esi, ASMRenderOffsets");
    asm("mov    eax, [ebp+0x08]");
    asm("add    eax, ebx");
    asm("mov    eax, [esi+eax*4]");
    asm("mov    ASMCurrentRenderYOffset, eax");
    asm("add    eax, ecx");
    asm("mov    ASMCurrentRenderXOffset, eax");
    asm("mov    esi, dword_79500C");
    asm("mov    eax, [esi+ebx*4]");
    asm("add    eax, [ebp+0x08]");
    asm("mov    dword_795018, eax");

    loc_633799:
    asm("cmp    edx, [edi+12]");
    asm("jg     loc_6340E0");
    asm("cmp    ecx, [edi+8]");
    asm("jge    short loc_6337B3");
    asm("mov    edi, [edi+4]");
    asm("or     edi, edi");
    asm("jnz    short loc_633799");
    goto loc_6340E0;

    loc_6337B3:
    asm("cmp    edx, [edi+8]");
    asm("jl     short loc_6337D5");
    asm("cmp    ecx, [edi+12]");
    asm("jg     short loc_6337D5");
    asm("mov    eax, offset loc_633800");
    asm("mov    ASMLocation,    eax");
    asm("mov    edi, ASMCurrentRenderXOffset");
    asm("mov    esi, dword_795018");
    goto loc_633800;

    loc_6337D5:
    asm("mov    eax, offset loc_633BA0");
    asm("mov    ASMLocation,    eax");
    asm("mov    ASMCurrentLineHead, edi");
    asm("mov    edi, ASMCurrentRenderXOffset");
    asm("mov    esi, dword_795018");
    goto loc_633BA0;

    loc_633800:
    asm("xor    eax, eax");
    asm("mov    al, [esi]");
    asm("mov    ecx, eax");
    asm("and    eax, 0x0F");
    asm("inc    esi");
    asm("jmp    off_631540[eax*4]");

    loc_633820:
    asm("mov    eax, ecx");
    asm("shr    eax, 4");
    asm("jmp    off_6315C0[eax*4]");

    loc_633840:
    asm("shr    ecx, 2");
    asm("mov    eax, edi");
    asm("and    eax, 3");
    asm("or     al, byte_631300[ecx]");
    asm("or     al, byte ptr dword_795048");
    asm("jmp    off_631600[eax*4]");

    loc_633860:
    asm("shl    ecx, 4");
    asm("xor    ebx, ebx");
    asm("mov    cl, [esi]");
    asm("sub    bl, ch");
    asm("mov    eax, edi");
    asm("and    bl, 0x80");
    asm("and    eax, 3");
    asm("or     bl, cl");
    asm("or     al, byte ptr dword_795048");
    asm("or     al, byte_631300[ebx]");
    asm("inc    esi");
    asm("jmp    off_631600[eax*4]");

    loc_6338A0:
    asm("shr    ecx, 2");
    asm("sub    edi, ecx");
    goto ASMLocation;

    loc_6338AB:
    asm("shl    ecx, 4");
    asm("mov    cl, [esi]");
    asm("inc    esi");
    asm("sub    edi, ecx");
    goto ASMLocation;

    loc_6338C0:
    asm("shr    ecx, 4");
    asm("jnz    short loc_6338C8");
    asm("mov    cl, [esi]");
    asm("inc    esi");

    loc_6338C8:
    asm("mov    eax, edi");
    asm("and    eax, 3");
    asm("or     al, byte_631300[ecx]");
    asm("mov    ebx, ASMColorXForm1");
    asm("or     al, byte ptr dword_795048");
    asm("jmp    off_631E00[eax*4]");

    loc_633900:
    asm("shr    ecx, 4");
    asm("jnz    short loc_633908");
    asm("mov    cl, [esi]");
    asm("inc    esi");

    loc_633908:
    asm("mov    al, [esi]");
    asm("mov    ebx, edi");
    asm("mov    ah, al");
    asm("and    ebx, 3");
    asm("shl    eax, 0x10");
    asm("or     bl, byte_631300[ecx]");
    asm("mov    al, [esi]");
    asm("or     bl, byte ptr dword_795048");
    asm("inc    esi");
    asm("mov    ah, al");
    asm("and    eax, dword_88C02C");
    asm("or     eax, dword_88C030");
    asm("jmp    off_631A00[ebx*4]");

    loc_633940:
    asm("shr    ecx, 4");
    asm("jnz    short loc_633948");
    asm("mov    cl, [esi]");
    asm("inc    esi");

    loc_633948:
    asm("mov    al, [esi]");
    asm("mov    ebx, edi");
    asm("mov    ah, al");
    asm("and    ebx, 3");
    asm("shl    eax, 0x10");
    asm("or     bl, byte_631300[ecx]");
    asm("mov    al, [esi]");
    asm("or     bl, byte ptr dword_795048");
    asm("inc    esi");
    asm("mov    ah, al");
    asm("and    eax, dword_88C02C");
    asm("or     eax, dword_795034");
    asm("jmp    off_631A00[ebx*4]");

    loc_633980:
    asm("shr    ecx, 4");
    asm("jnz    short loc_633988");
    asm("mov    cl, [esi]");
    asm("inc    esi");

    loc_633988:
    asm("mov    eax, edi");
    asm("and    eax, 3");
    asm("or     al, byte_631300[ecx]");
    asm("mov    ebx, ASMXlate");
    asm("or     al, byte ptr dword_795048");
    asm("xor    edx, edx");
    asm("jmp    off_632200[eax*4]");

    loc_6339C0:
    asm("xor    ecx, ecx");
    asm("mov    eax, dword_795098");
    asm("mov    cl, [esi]");
    asm("mov    dword_795090, eax");
    asm("inc    esi");
    asm("mov    eax, 2");
    goto loc_633A2A;

    loc_6339D6:
    asm("mov    eax, dword_795098");
    asm("mov    ecx, 1");
    asm("mov    dword_795090, eax");
    asm("mov    eax, 2");
    goto loc_633A2A;

    loc_633A00:
    asm("xor    ecx, ecx");
    asm("mov    eax, dword_795094");
    asm("mov    cl, [esi]");
    asm("mov    dword_795090, eax");
    asm("inc    esi");
    asm("mov    eax, 1");
    goto loc_633A2A;

    loc_633A16:
    asm("mov    eax, dword_795094");
    asm("mov    ecx, 1");
    asm("mov    dword_795090, eax");
    asm("mov    eax, 1");

    loc_633A2A:
    asm("test    dword_79509C, eax");
    asm("jz     short loc_633A5B");
    asm("mov    eax, dword_795090");
    asm("mov    ebx, edi");
    asm("and    eax, dword_88C02C");
    asm("and    ebx, 3");
    asm("or     eax, dword_88C030");
    asm("or     bl, byte_631300[ecx]");
    asm("or     bl, byte ptr dword_795048");
    asm("jmp    off_631A00[ebx*4]");

    loc_633A5B:
    asm("sub    edi, ecx");
    goto ASMLocation;

    loc_633A80:
    asm("call   sub_634100");
    asm("sub    edi, ecx");
    goto loc_633800;

    loc_633AA0:
    asm("mov    eax, ASMColorXForm2");
    asm("mov    ASMColorXForm1, eax");
    asm("int    3");
    asm("and    eax, dword_88C02C");
    asm("or     edx, dword_88C030");
    asm("mov    dword_795034, eax");
    goto loc_633800;

    loc_633AE0:
    asm("mov    eax, ASMColorXForm3");
    asm("mov    ASMColorXForm1, eax");
    asm("int    3");
    asm("and    eax, dword_88C02C");
    asm("or     edx, dword_88C030");
    asm("mov    dword_795034, eax");
    goto loc_633800;

    /* TODO */
    byte_633B20 = 0xCC;
    goto loc_632E40;

    /* TODO */
    a_l_l_l_l_l_l_1 = '.̀.̀.̀.̀.̀.̀.̀.̀̀˵PPy';

    asm("mov    edi, dword_795054");
    asm("mov    ebx, ASMCurrentLineHead");
    asm("mov    ebx, [ebx+4]");
    asm("or     ebx, ebx");
    asm("jz     loc_6340E0");
    ASMLocation = &&loc_633BA0;
    asm("xor    eax, eax");
    asm("mov    al, [esi]");
    asm("sub    edi, ASMCurrentRenderYOffset");
    asm("mov    ecx, eax");
    asm("inc    esi");
    asm("and    eax, 0x0F");
    asm("mov    ASMCurrentLineHead, ebx");
    asm("jmp    off_631500[eax*4]");

    loc_633BA0:
    asm("mov    dword_795050, esi");
    asm("xor    eax, eax");
    asm("mov    dword_795054, edi");
    asm("mov    al, [esi]");
    asm("sub    edi, ASMCurrentRenderYOffset");
    asm("mov    ecx, eax");
    asm("inc    esi");
    asm("and    eax, 0x0F");
    asm("mov    ebx, ASMCurrentLineHead");
    asm("jmp    off_631500[eax*4]");

    loc_633BE0:
    asm("mov    eax, ecx");
    asm("shr    eax, 4");
    asm("jmp    off_631580[eax*4]");

    loc_633C00:
    asm("shr    ecx, 2");
    goto loc_633C0B;

    loc_633C05:
    asm("shl    ecx, 4");
    asm("mov    cl, [esi]");
    asm("inc    esi");

    loc_633C0B:
    asm("mov    edx, edi");
    asm("sub    edx, ecx");
    asm("inc    edx");

    loc_633C10:
    asm("cmp    edx, [ebx+12]");
    asm("jg     short loc_633C72");
    asm("cmp    edi, [ebx+8]");
    asm("jl     short loc_633C81");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+12]");
    asm("jle    short loc_633C2A");
    asm("mov    eax, edi");
    asm("sub    eax, [ebx+12]");
    asm("add    esi, eax");
    asm("sub    ecx, eax");

    loc_633C2A:
    asm("mov    ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+8]");
    asm("jge    short loc_633C45");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edx");
    asm("sub    ecx, eax");
    asm("mov    ASMLocation,    (offset    a_l_l_l_l_l_l_1+1Ah)");

    loc_633C45:
    asm("mov    edi, dword_795054");
    asm("xor    ebx, ebx");
    asm("sub    edi, ASMCurrentLineHeadPx");
    asm("sub    bl, ch");
    asm("mov    eax, edi");
    asm("and    bl, 0x80");
    asm("and    eax, 3");
    asm("or     bl, cl");
    asm("or     al, byte ptr dword_795048");
    asm("or     al, byte_631300[ebx]");
    asm("jmp    off_631600[eax*4]");

    loc_633C72:
    asm("mov    edi, dword_795054");
    asm("add    esi, ecx");
    asm("sub    edi, ecx");
    goto loc_633BA0;

    loc_633C81:
    asm("mov    ebx, [ebx+4]");
    asm("or    ebx, ebx");
    asm("jnz    short loc_633C10");
    goto loc_6340E0;

    loc_633CA0:
    asm("shr    ecx, 2");
    asm("mov    edi, dword_795054");
    asm("sub    edi, ecx");
    goto ASMLocation;

    loc_633CB1:
    asm("shl    ecx, 4");
    asm("mov    edi, dword_795054");
    asm("mov    cl, [esi]");
    asm("inc    esi");
    asm("sub    edi, ecx");
    goto ASMLocation;

    loc_633CE0:
    asm("shr    ecx, 4");
    asm("jnz    short loc_633CE8");
    asm("mov    cl, [esi]");
    asm("inc    esi");

    loc_633CE8:
    asm("mov    edx, edi");
    asm("sub    edx, ecx");
    asm("inc    edx");

    loc_633CED:
    asm("cmp    edx, [ebx+12]");
    asm("jg    short loc_633D4C");
    asm("cmp    edi, [ebx+8]");
    asm("jl    short loc_633D5B");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+12]");
    asm("jle    short loc_633D07");
    asm("mov    eax, edi");
    asm("sub    eax, [ebx+12]");
    asm("add    esi, eax");
    asm("sub    ecx, eax");

    loc_633D07:
    asm("mov    ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+8]");
    asm("jge    short loc_633D22");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edx");
    asm("sub    ecx, eax");
    asm("mov    ASMLocation,    (offset    a_l_l_l_l_l_l_1+1Ah)");

    loc_633D22:
    asm("mov    edi, dword_795054");
    asm("sub    edi, ASMCurrentLineHeadPx");
    asm("mov    eax, edi");
    asm("and    eax, 3");
    asm("or    al, byte_631300[ecx]");
    asm("mov    ebx, ASMColorXForm1");
    asm("or    al, byte ptr dword_795048");
    asm("jmp    off_631E00[eax*4]");

    loc_633D4C:
    asm("mov    edi, dword_795054");
    asm("add    esi, ecx");
    asm("sub    edi, ecx");
    goto loc_633BA0;

    loc_633D5B:
    asm("mov    ebx, [ebx+4]");
    asm("or    ebx, ebx");
    asm("jnz    short loc_633CED");
    goto loc_6340E0;

    loc_633D80:
    asm("shr    ecx, 4");
    asm("jnz    short loc_633D88");
    asm("mov    cl, [esi]");
    asm("inc    esi");

    loc_633D88:
    asm("mov    edx, edi");
    asm("sub    edx, ecx");
    asm("inc    edx");

    loc_633D8D:
    asm("cmp    edx, [ebx+12]");
    asm("jg    short loc_633DFC");
    asm("cmp    edi, [ebx+8]");
    asm("jl    short loc_633E0A");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+12]");
    asm("jle    short loc_633DA5");
    asm("mov    eax, edi");
    asm("sub    eax, [ebx+12]");
    asm("sub    ecx, eax");

    loc_633DA5:
    asm("mov    ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+8]");
    asm("jge    short loc_633DC0");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edx");
    asm("sub    ecx, eax");
	ASMLocation = a_l_l_l_l_l_l_1 + 0x1A;

    loc_633DC0:
    asm("mov    edi, dword_795054");
    asm("mov    al, [esi]");
    asm("sub    edi, ASMCurrentLineHeadPx");
    asm("mov    ah, al");
    asm("mov    ebx, edi");
    asm("shl    eax, 0x10");
    asm("and    ebx, 3");
    asm("mov    al, [esi]");
    asm("or     bl, byte_631300[ecx]");
    asm("mov    ah, al");
    asm("or     bl, byte ptr dword_795048");
    asm("and    eax, dword_88C02C");
    asm("or     eax, dword_88C030");
    asm("inc    esi");
    asm("jmp    off_631A00[ebx*4]");

    loc_633DFC:
    asm("mov    edi, dword_795054");
    asm("inc    esi");
    asm("sub    edi, ecx");
    goto loc_633BA0;

    loc_633E0A:
    asm("mov    ebx, [ebx+4]");
    asm("or     ebx, ebx");
    asm("jnz    loc_633D8D");
    goto loc_6340E0;

    loc_633E20:
    asm("shr    ecx, 4");
    asm("jnz    short loc_633E28");
    asm("mov    cl, [esi]");
    asm("inc    esi");

    loc_633E28:
    asm("mov    edx, edi");
    asm("sub    edx, ecx");
    asm("inc    edx");

    loc_633E2D:
    asm("cmp    edx, [ebx+12]");
    asm("jg     short loc_633E9C");
    asm("cmp    edi, [ebx+8]");
    asm("jl     short loc_633EAA");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+12]");
    asm("jle    short loc_633E45");
    asm("mov    eax, edi");
    asm("sub    eax, [ebx+12]");
    asm("sub    ecx, eax");

    loc_633E45:
    asm("mov    ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+8]");
    asm("jge    short loc_633E60");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edx");
    asm("sub    ecx, eax");
    asm("mov    ASMLocation,    (offset    a_l_l_l_l_l_l_1+1Ah)");

    loc_633E60:
    asm("mov    edi, dword_795054");
    asm("mov    al, [esi]");
    asm("sub    edi, ASMCurrentLineHeadPx");
    asm("mov    ah, al");
    asm("mov    ebx, edi");
    asm("shl    eax, 0x10");
    asm("and    ebx, 3");
    asm("mov    al, [esi]");
    asm("or     bl, byte_631300[ecx]");
    asm("mov    ah, al");
    asm("or     bl, byte ptr dword_795048");
    asm("inc    esi");
    asm("and    eax, dword_88C02C");
    asm("or     eax, dword_795034");
    asm("jmp    off_631A00[ebx*4]");

    loc_633E9C:
    asm("mov    edi, dword_795054");
    asm("inc    esi");
    asm("sub    edi, ecx");
    goto loc_633BA0;

    loc_633EAA:
    asm("mov    ebx, [ebx+4]");
    asm("or     ebx, ebx");
    asm("jnz    loc_633E2D");
    goto loc_6340E0;

    loc_633EC0:
    asm("shr    ecx, 4");
    asm("jnz    short loc_633EC8");
    asm("mov    cl, [esi]");
    asm("inc    esi");

    loc_633EC8:
    asm("mov    edx, edi");
    asm("sub    edx, ecx");
    asm("inc    edx");

    loc_633ECD:
    asm("cmp    edx, [ebx+12]");
    asm("jg     short loc_633F2C");
    asm("cmp    edi, [ebx+8]");
    asm("jl     short loc_633F39");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+12]");
    asm("jle    short loc_633EE5");
    asm("mov    eax, edi");
    asm("sub    eax, [ebx+12]");
    asm("sub    ecx, eax");

    loc_633EE5:
    asm("mov    ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+8]");
    asm("jge    short loc_633F00");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edx");
    asm("sub    ecx, eax");
    asm("mov    ASMLocation,    (offset    a_l_l_l_l_l_l_1+1Ah)");

    loc_633F00:
    asm("mov    edi, dword_795054");
    asm("sub    edi, ASMCurrentLineHeadPx");
    asm("mov    eax, edi");
    asm("and    eax, 3");
    asm("or     al, byte_631300[ecx]");
    asm("mov    ebx, ASMXlate");
    asm("or     al, byte ptr dword_795048");
    asm("xor    edx, edx");
    asm("jmp    off_632200[eax*4]");

    loc_633F2C:
    asm("mov    edi, dword_795054");
    asm("sub    edi, ecx");
    goto loc_633BA0;

    loc_633F39:
    asm("mov    ebx, [ebx+4]");
    asm("or     ebx, ebx");
    asm("jnz    short loc_633ECD");
    goto loc_6340E0;

    loc_633F60:
    asm("xor    ecx, ecx");
    asm("mov    eax, dword_795098");
    asm("mov    cl, [esi]");
    asm("mov    dword_795090, eax");
    asm("inc    esi");
    asm("mov    eax, 2");
    goto loc_633FCA;

    loc_633F76:
    asm("mov    eax, dword_795098");
    asm("mov    ecx, 1");
    asm("mov    dword_795090, eax");
    asm("mov    eax, 2");
    goto loc_633FCA;

    loc_633FA0:
    asm("xor    ecx, ecx");
    asm("mov    eax, dword_795094");
    asm("mov    cl, [esi]");
    asm("mov    dword_795090, eax");
    asm("inc    esi");
    asm("mov    eax, 1");
    goto loc_633FCA;

    loc_633FB6:
    asm("mov    eax, dword_795094");
    asm("mov    ecx, 1");
    asm("mov    dword_795090, eax");
    asm("mov    eax, 1");

    loc_633FCA:
    asm("test   dword_79509C, eax");
    asm("jz     short loc_63403F");
    asm("mov    edx, edi");
    asm("sub    edx, ecx");
    asm("inc    edx");

    loc_633FD7:
    asm("cmp    edx, [ebx+12]");
    asm("jg     short loc_63403F");
    asm("cmp    edi, [ebx+8]");
    asm("jl     short loc_63404C");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+12]");
    asm("jle    short loc_633FEF");
    asm("mov    eax, edi");
    asm("sub    eax, [ebx+12]");
    asm("sub    ecx, eax");

    loc_633FEF:
    asm("mov    ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+8]");
    asm("jge    short loc_63400A");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edx");
    asm("sub    ecx, eax");
    asm("mov    ASMLocation,    (offset    a_l_l_l_l_l_l_1+1Ah)");

    loc_63400A:
    asm("mov    edi, dword_795054");
    asm("mov    eax, dword_795090");
    asm("sub    edi, ASMCurrentLineHeadPx");
    asm("and    eax, dword_88C02C");
    asm("mov    ebx, edi");
    asm("or     eax, dword_88C030");
    asm("and    ebx, 3");
    asm("or     bl, byte_631300[ecx]");
    asm("or     bl, byte ptr dword_795048");
    asm("jmp    off_631A00[ebx*4]");

    loc_63403F:
    asm("mov    edi, dword_795054");
    asm("sub    edi, ecx");
    goto loc_633BA0;

    loc_63404C:
    asm("mov    ebx, [ebx+4]");
    asm("or     ebx, ebx");
    asm("jnz    short loc_633FD7");
    goto loc_6340E0;

    loc_634060:
    asm("call   sub_634100");
    asm("sub    edi, ecx");
    goto loc_633BA0;

    loc_634080:
	ASMColorXForm1 = ASMColorXForm2;// eax
    asm("and    eax, dword_88C02C");
    asm("or     edx, dword_88C030");
    dword_795034 = ASMColorXForm1;
    goto loc_633800;

    loc_6340A0:
	ASMColorXForm1 = ASMColorXForm3;// eax
    asm("and    eax, dword_88C02C");
    asm("or     edx, dword_88C030");
    dword_795034 = ASMColorXForm1;
    goto loc_633800;

    /* TODO: wth is this? */
    byte_6340C0 = 0xCC;

    goto loc_632E40;

    loc_6340E0:
    if( ++ASMDrawYOffset < DrawX ){
		goto loc_6336E0;
	}

    asm("pop    edi");
    asm("pop    esi");
    asm("pop    ebx");
    asm("pop    ebp");

    asm("ret");
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int sub_6341A0( ASMDraw_Unk *Shape, int DrawX, int DrawY )
{
    dword_7950A0 = Shape;

    ASMDrawXFinish = DrawX;
    ASMDrawYFinish = DrawY;

    dword_7950AC = Shape->unk2 + DrawY - 1;
    dword_7950B0 = Shape->unk4;
}

int sub_6341E0(
    void *ShapeBase,
    int DrawX,
    int DrawY,
    int ShapeSizeX,
    int ShapeSizeY,
    int ShapeDataOffsets,
    int ShapeOutlineOffset,
    unsigned char DrawFlag )
{
    /*
    int result; // eax@1
    int v9; // ecx@1
    int v10; // edx@1
    int v11; // ebx@1
    VSpan_Node *v12; // edi@14
    int v13; // edx@15
    int v14; // ecx@15
    int v15; // eax@17
    int v16; // ebx@19
    int v17; // edi@26
    _BYTE *v18; // esi@26
    unsigned int v19; // ecx@27
    VSpan_Node *v20; // ebx@27
    int v21; // ecx@28
    int v22; // ecx@29
    signed int v23; // ecx@31
    int v24; // edx@35
    int v25; // eax@37
    int v26; // eax@40
    int v27; // eax@45
    VSpan_Node *v28; // edi@56
    int v29; // edx@57
    int v30; // ecx@57
    int v31; // eax@59
    int v32; // ebx@61
    int v33; // edi@68
    _BYTE *v34; // esi@68
    unsigned int v35; // ecx@69
    VSpan_Node *v36; // ebx@69
    int v37; // ecx@70
    int v38; // ecx@71
    signed int v39; // ecx@73
    int v40; // edx@77
    int v41; // eax@79
    int v42; // eax@82
    int v43; // eax@87
    int ShapeSizeYa; // [sp+24h] [bp+18h]@9

    result = DrawY;
    v9 = ShapeSizeY;
    v10 = 0;
    v11 = ShapeSizeY + DrawY - 1;
    if ( v11 >= ASMMinLine && DrawY <= ASMMaxLine && v11 >= ASMDrawYFinish && DrawY <= dword_7950AC )
    {
        if ( DrawY < ASMMinLine )
        {
            v9 = ShapeSizeY - (ASMMinLine - DrawY);
            v10 = 4 * (ASMMinLine - DrawY);
            DrawY = 0;
        }
        if ( v11 > ASMMaxLine )
            v9 -= v11 - ASMMaxLine;
        ShapeSizeYa = v9;
        ASMDrawYOffset = 0;
        result = DrawX;
        ASMDrawXStart = DrawX;
        if ( DrawX <= ASMMaxSpanPx )
        {
            result = ShapeSizeX + DrawX - 1;
            dword_795028 = result;
            if ( result >= ASMMinSpanPx )
            {
                dword_79500C = v10 + ShapeBase + ShapeDataOffsets;
                dword_795010 = v10 + ShapeBase + ShapeOutlineOffset;
                if ( DrawFlag & 2 )
                {
                    do
                    {
                        result = ASMDrawYOffset + DrawY;
                        if ( ASMDrawYOffset + DrawY >= ASMDrawYFinish )
                        {
                            if ( result > dword_7950AC )
                                return result;
                            v28 = (dword_7950B0[result - ASMDrawYFinish + 1] - 8);
                            ASMCurrentLineHead = (dword_7950B0[result - ASMDrawYFinish + 1] - 8);
                            HIWORD(result) = 0;
                            if ( !(dword_795010[ASMDrawYOffset] + 2) & 0x8000) )
                            {
                                LOWORD(result) = dword_795010[ASMDrawYOffset] + 2;
                                v29 = result + ASMDrawXStart;
                                LOWORD(result) = dword_795010[ASMDrawYOffset];
                                v30 = dword_795028 - result;
                                ASMCurrentRenderYOffset = ASMRenderOffsets[ASMDrawYOffset + DrawY];
                                ASMCurrentRenderXOffset = dword_795028 - result + ASMCurrentRenderYOffset;
                                dword_795018 = ShapeBase + *(dword_79500C + 4 * ASMDrawYOffset);
                                while ( !(v28->Next & 0x80000000) )
                                {
                                    v31 = v28->Next + ASMDrawXFinish;
                                    if ( v31 < ASMMinSpanPx )
                                        v31 = ASMMinSpanPx;
                                    v32 = v28->Prev + ASMDrawXFinish;
                                    if ( v32 < ASMMinSpanPx )
                                        break;
                                    if ( v31 <= ASMMaxSpanPx )
                                    {
                                        if ( v32 > ASMMaxSpanPx )
                                            v32 = ASMMaxSpanPx;
                                        if ( v29 > v32 )
                                            break;
                                        if ( v30 >= v31 )
                                        {
                                            ASMLocation = &loc_6347A0;
                                            ASMCurrentLineHead = v28;
                                            v33 = ASMCurrentRenderXOffset;
                                            v34 = dword_795018;
LABEL_69:
                                            while ( 2 )
                                            {
                                                dword_795050 = v34;
                                                dword_795054 = v33;
                                                v33 -= ASMCurrentRenderYOffset;
                                                v35 = *v34++;
                                                v36 = ASMCurrentLineHead;
                                                switch ( v35 & 0xF )
                                                {
                                                    case 0u:
                                                    case 1u:
                                                    case 2u:
                                                    case 3u:
                                                    case 4u:
                                                    case 5u:
                                                    case 6u:
                                                    case 7u:
                                                    case 8u:
                                                    case 9u:
                                                    case 0xAu:
                                                    case 0xBu:
                                                    case 0xCu:
                                                    case 0xDu:
LABEL_70:
                                                        sub_634100(--v34);
                                                        v33 = dword_795054 - v37;
                                                        continue;
                                                    case 0xEu:
                                                        switch ( v35 >> 4 )
                                                        {
                                                            case 0u:
                                                                sub_634100(v34);
                                                                v33 = dword_795054 - v38;
                                                                continue;
                                                            case 1u:
                                                                continue;
                                                            case 2u:
                                                            case 3u:
                                                            case 8u:
                                                                goto LABEL_70;
                                                            case 4u:
                                                                v39 = 1;
                                                                dword_795090 = dword_795094;
                                                                break;
                                                            case 5u:
                                                                v39 = *v34;
                                                                dword_795090 = dword_795094;
                                                                ++v34;
                                                                break;
                                                            case 6u:
                                                                v39 = 1;
                                                                dword_795090 = dword_795098;
                                                                break;
                                                            case 7u:
                                                                v39 = *v34;
                                                                dword_795090 = dword_795098;
                                                                ++v34;
                                                                break;
                                                        }
                                                        v40 = v33 - v39 + 1;
                                                        break;
                                                    case 0xFu:
                                                        goto LABEL_94;
                                                }
                                                break;
                                            }
                                            while ( !(v36->Next & 0x4C4B400) )
                                            {
                                                v41 = v36->Next + ASMDrawXFinish;
                                                if ( v41 < ASMMinSpanPx )
                                                    v41 = ASMMinSpanPx;
                                                if ( v41 <= ASMMaxSpanPx )
                                                {
                                                    dword_7950B4 = v41;
                                                    v42 = v36->Prev + ASMDrawXFinish;
                                                    if ( v42 < ASMMinSpanPx )
                                                        goto LABEL_94;
                                                    if ( v42 > ASMMaxSpanPx )
                                                        v42 = ASMMaxSpanPx;
                                                    dword_7950B8 = v42;
                                                    if ( v40 > v42 )
                                                    {
                                                        v33 = dword_795054 - v39;
                                                        goto LABEL_69;
                                                    }
                                                    if ( v33 >= dword_7950B4 )
                                                    {
                                                        v43 = 0;
                                                        if ( v33 > dword_7950B8 )
                                                        {
                                                            v43 = v33 - dword_7950B8;
                                                            v39 -= v33 - dword_7950B8;
                                                        }
                                                        ASMCurrentLineHeadPx = v43;
                                                        if ( v40 < dword_7950B4 )
                                                        {
                                                            v39 -= dword_7950B4 - v40;
                                                            ASMLocation = "‹5PPy";
                                                        }
                                                        JUMPOUT(
                                                            __CS__,
                                                            *(&off_631A00 + (byte_631300[v39] | (dword_795054 - ASMCurrentLineHeadPx) & 3)));
                                                    }
                                                }
                                                v36 = (v36 - 8);
                                            }
                                            break;
                                        }
                                    }
                                    v28 = (v28 - 8);
                                }
                            }
                        }
LABEL_94:
                        result = ASMDrawYOffset + 1;
                        ASMDrawYOffset = result;
                    }
                    while ( result < ShapeSizeYa );
                }
                else
                {
                    do
                    {
                        result = ASMDrawYOffset + DrawY;
                        if ( ASMDrawYOffset + DrawY >= ASMDrawYFinish )
                        {
                            if ( result > dword_7950AC )
                                return result;
                            v12 = (*(dword_7950B0[result - ASMDrawYFinish]) + 8);
                            ASMCurrentLineHead = (*(dword_7950B0[result - ASMDrawYFinish]) + 8);
                            HIWORD(result) = 0;
                            if ( !(dword_795010[ASMDrawYOffset] & 0x8000) )
                            {
                                LOWORD(result) = dword_795010[ASMDrawYOffset];
                                v13 = result + ASMDrawXStart;
                                LOWORD(result) = dword_795010[ASMDrawYOffset] + 2;
                                v14 = dword_795028 - result;
                                ASMCurrentRenderYOffset = ASMRenderOffsets[ASMDrawYOffset + DrawY];
                                ASMCurrentRenderXOffset = v13 + ASMCurrentRenderYOffset;
                                dword_795018 = dword_79500C[ASMDrawYOffset] + ShapeBase;
                                while ( !(v12->Next & 0x80000000) )
                                {
                                    v15 = v12->Next + ASMDrawXFinish;
                                    if ( v15 < ASMMinSpanPx )
                                        v15 = ASMMinSpanPx;
                                    v16 = v12->Prev + ASMDrawXFinish;
                                    if ( v16 >= ASMMinSpanPx )
                                    {
                                        if ( v15 > ASMMaxSpanPx )
                                            break;
                                        if ( v16 > ASMMaxSpanPx )
                                            v16 = ASMMaxSpanPx;
                                        if ( v14 < v15 )
                                            break;
                                        if ( v13 <= v16 )
                                        {
                                            ASMLocation = &loc_634440;
                                            ASMCurrentLineHead = v12;
                                            v17 = ASMCurrentRenderXOffset;
                                            v18 = dword_795018;
LABEL_27:
                                            while ( 2 )
                                            {
                                                dword_795050 = v18;
                                                dword_795054 = v17;
                                                v17 -= ASMCurrentRenderYOffset;
                                                v19 = *v18++;
                                                v20 = ASMCurrentLineHead;
                                                switch ( v19 & 0xF )
                                                {
                                                    case 0u:
                                                    case 1u:
                                                    case 2u:
                                                    case 3u:
                                                    case 4u:
                                                    case 5u:
                                                    case 6u:
                                                    case 7u:
                                                    case 8u:
                                                    case 9u:
                                                    case 0xAu:
                                                    case 0xBu:
                                                    case 0xCu:
                                                    case 0xDu:
LABEL_28:
                                                        sub_634100(--v18);
                                                        v17 = v21 + dword_795054;
                                                        continue;
                                                    case 0xEu:
                                                        switch ( v19 >> 4 )
                                                        {
                                                            case 0u:
                                                                continue;
                                                            case 1u:
                                                                sub_634100(v18);
                                                                v17 = v22 + dword_795054;
                                                                continue;
                                                            case 2u:
                                                            case 3u:
                                                            case 8u:
                                                                goto LABEL_28;
                                                            case 4u:
                                                                v23 = 1;
                                                                dword_795090 = dword_795094;
                                                                break;
                                                            case 5u:
                                                                v23 = *v18;
                                                                dword_795090 = dword_795094;
                                                                ++v18;
                                                                break;
                                                            case 6u:
                                                                v23 = 1;
                                                                dword_795090 = dword_795098;
                                                                break;
                                                            case 7u:
                                                                v23 = *v18;
                                                                dword_795090 = dword_795098;
                                                                ++v18;
                                                                break;
                                                        }
                                                        v24 = v23 + v17 - 1;
                                                        break;
                                                    case 0xFu:
                                                        goto LABEL_52;
                                                }
                                                break;
                                            }
                                            while ( !(v20->Next & 0x4C4B400) )
                                            {
                                                v25 = v20->Next + ASMDrawXFinish;
                                                if ( v25 < ASMMinSpanPx )
                                                    v25 = ASMMinSpanPx;
                                                if ( v25 > ASMMaxSpanPx )
                                                    break;
                                                dword_7950B4 = v25;
                                                v26 = v20->Prev + ASMDrawXFinish;
                                                if ( v26 >= ASMMinSpanPx )
                                                {
                                                    if ( v26 > ASMMaxSpanPx )
                                                        v26 = ASMMaxSpanPx;
                                                    dword_7950B8 = v26;
                                                    if ( v24 < dword_7950B4 )
                                                    {
                                                        v17 = v23 + dword_795054;
                                                        goto LABEL_27;
                                                    }
                                                    if ( v17 <= dword_7950B8 )
                                                    {
                                                        v27 = 0;
                                                        if ( v17 < dword_7950B4 )
                                                        {
                                                            v27 = dword_7950B4 - v17;
                                                            v23 -= dword_7950B4 - v17;
                                                        }
                                                        ASMCurrentLineHeadPx = v27;
                                                        if ( v24 > dword_7950B8 )
                                                        {
                                                            v23 -= v24 - dword_7950B8;
                                                            ASMLocation = "‹5PPy";
                                                        }
                                                        JUMPOUT(__CS__, off_630700[(byte_631300[v23] | (ASMCurrentLineHeadPx + dword_795054) & 3)]);
                                                    }
                                                }
                                                v20 = (v20 + 8);
                                            }
                                            break;
                                        }
                                    }
                                    v12 = (v12 + 8);
                                }
                            }
                        }
LABEL_52:
                        result = ASMDrawYOffset + 1;
                        ASMDrawYOffset = result;
                    }
                    while ( result < ShapeSizeYa );
                }
            }
        }
    }
    return result;
    */
}
