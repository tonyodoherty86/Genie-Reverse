
int dword_88C000 = 0;
int dword_88C004 = 0;
int dword_88C008 = 0;
int dword_88C014 = 0;
int dword_88C01C = 0;
int dword_88C020 = 0;
int dword_88C02C = 0;
int dword_88C030 = 0;
int dword_88C034 = 0;
int dword_88C038 = 0;
int dword_88C03C = 0;
int dword_88C040 = 0;
//int (*dword_88C044)(void) = NULL;
int dword_88C04C = 0;
int dword_88C060 = 0;
int dword_88C064 = 0;
int dword_88C068 = 0;
int dword_88C06C = 0;
int dword_88C070 = 0;
int dword_88C074 = 0;
int dword_88C078 = 0;
int dword_88C07C = 0;
int dword_88C080 = 0;
int dword_88C084 = 0;
int dword_88C088 = 0;
int dword_88C08C = 0;

/**
 *
 */
void ASMSet_Shadowing(
    int a1,
    int a2,
    int a3,
    int a4)
{
    dword_88C060 = a1;
    dword_88C068 = a1;
    dword_88C070 = a2;
    dword_88C078 = a2;

    dword_88C064 = a3;
    dword_88C06C = a3;
    dword_88C074 = a4;
    dword_88C07C = a4;
}

/**
 *
 */
void ASMSet_Surface_Info(
    int RenderOffsets,
    int LineHeadPtrs,
    int LineTailPtrs,
    int MinSpanPx,
    int MinLine,
    int MaxSpanPx,
    int MaxLine)
{
    dword_88C000 = RenderOffsets;

    dword_88C004 = LineHeadPtrs;
    dword_88C008 = LineTailPtrs;

    dword_88C080 = MinLine;
    dword_88C084 = MaxLine;
    dword_88C088 = MinSpanPx;
    dword_88C08C = MaxSpanPx;
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
    asm("mov     ds:dword_88C040, eax");
    asm("pop     ebp");
    asm("retn");
    */
}

/**
 *
 */
int ASMGet_Color_Xform()
{
    return (unsigned char)dword_88C040;
}

/**
 *
 */
void ASMSet_Xlate_Table(int a1)
{
    /*
    asm("push    ebp");
    asm("mov     ebp, esp");
    asm("mov     eax, [ebp+arg_0]");
    asm("mov     ds:dword_88C01C, eax");
    asm("pop     ebp");
    asm("retn");
    */
}

/**
 *
 */
int ASMGet_Xlate_Table()
{
    return dword_88C01C;
}

/**
 *
 */
void ASMDraw_HLine(int x1, int x2, int y1)
{
    /* TODO */
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
