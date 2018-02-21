
/**
 * @file    Engine\AsmDraw.h
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

/**
 *
 */
void ASMSet_Shadowing(
    int a1,
    int a2,
    int a3,
    int a4);

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
    int MaxLine);

/**
 *
 */
void ASMSet_Color_Xform(
    unsigned int a1);

/**
 *
 */
int ASMGet_Color_Xform();

/**
 *
 */
void ASMSet_Xlate_Table(
    int a1);

/**
 *
 */
int ASMGet_Xlate_Table();

/**
 *
 */
void ASMDraw_HLine(
    int x1,
    int x2,
    int y1);

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
    int DrawFlag);
