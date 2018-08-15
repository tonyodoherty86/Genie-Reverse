
/**
 * @file    Engine\AsmDraw.h
 * @author  Yvan Burrie
 * @date    2018/08/12
 * @version 1.0
 */

#ifndef ASM_DRAW_H
    #define ASM_DRAW_H
#endif

/**************************************************************************************************\
 * @brief Assigns the shadow info.
 * @return void
 */
void ASMSet_Shadowing(
    int a1,
    int a2,
    int a3,
    int a4 );

/**************************************************************************************************\
 * @brief Initiates the draw system.
 * @return void
 */
void ASMSet_Surface_Info(
    void **RenderOffsets,
    VSpan_Node **LineHeadPtrs,
    VSpan_Node **LineTailPtrs,
    int MinSpanPx,
    int MinLine,
    int MaxSpanPx,
    int MaxLine );

/**************************************************************************************************\
 * @brief Assigns the cross-form mask.
 * @param unsigned int XformMask
 * @return void
 */
void ASMSet_Color_Xform( unsigned int XformMask );

/**************************************************************************************************\
 * @brief
 * @return void
 *
 * sub_6328A0 (AOC)
 */
void ASMSet_Color_XformEx( unsigned int a1, unsigned int a2 );

/**************************************************************************************************\
 * @brief Retrieves the cross-form mask.
 * @return int
 */
int ASMGet_Color_Xform( void );

int ASMGet_Color_Xform2( void );

int ASMGet_Color_Xform3( void );

/**************************************************************************************************\
 * @brief Assigns the cross-late table.
 * @param int ColorTable
 * @return void
 */
void ASMSet_Xlate_Table( int ColorTable );

/**************************************************************************************************\
 * @brief Retrieves the cross-late table.
 * @return int
 */
int ASMGet_Xlate_Table( void );

/**************************************************************************************************\
 * @brief Draws a horizontal line.
 * @param int x1 The start of X ordinate.
 * @param int x2 The end of X ordinate.
 * @param int y1 The Y ordinate.
 * @return void
 *
 * sub_56A210 (AOC)
 */
void ASMDraw_HLine( int x1, int x2, int y1 );

/**************************************************************************************************\
 * @brief Draws the sprite from a shape.
 * @return void
 */
void ASMDraw_Sprite(
    SLhape_File_Header *ShapeBase,
    int DrawX,
    int DrawY,
    int DrawW,
    int DrawH,
    int ShapeDataOffsets,
    int ShapeLineOffsets,
    int DrawFlag );

/**************************************************************************************************/
int sub_634100( int a1 );

/**************************************************************************************************\
 * sub_6341A0 (AOC)
 */
int sub_6341A0( struct ASMDraw_Unk *Shape, int DrawX, int DrawY );

struct ASMDraw_Unk
{
    int unk1;
    int unk2;
    int unk3;
    int unk4;
};

/**************************************************************************************************/
int sub_6341E0(
    void *ShapeBase,
    int DrawX,
    int DrawY,
    int ShapeSizeX,
    int ShapeSizeY,
    int ShapeDataOffsets,
    int ShapeOutlineOffset,
    unsigned char DrawFlag );
