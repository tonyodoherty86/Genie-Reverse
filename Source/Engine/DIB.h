#pragma once

/**
 * @file    Engine\DIB.h
 * @author  Yvan Burrie
 * @date    2018/08/21
 * @version 1.0
 */

#include "IDA.h"

/**
 *
 */
struct PAL_TABLE
{
    int index;

    char red, green, blue, reserved;
};

/**
 *
 */
struct BITMAPINFO256
{
    BITMAPINFOHEADER bmiHeader;

    RGBQUAD bmiColors[256];
};

/**
 *
 */
struct LINEINFO
{
    int AllTrans;

    int MidSolid;

    int StartX, EndX;
};

/**
 *
 */
struct TRANSINFO
{
    int AnyTrans;

    int x, y, w, h;

    LINEINFO *LineInfo;
};

/**
 *
 */
void DibBlt(
    BITMAPINFO256 *DestInfo,
    char *DestBits,
    RECT *ClipRect,
    int DestX,
    int DestY,
    int DestWid,
    int DestHgt,
    BITMAPINFO256 *SrcInfo,
    char *SrcBits,
    int SrcX,
    int SrcY,
    int SrcWid,
    int SrcHgt,
    int Clip,
    bool Mirror,
    bool Flip );

/**
 *
 */
void TransDibBlt(
    BITMAPINFO256 *DestInfo,
    char *DestBits,
    RECT *ClipRect,
    int DestX,
    int DestY,
    int DestWid,
    int DestHgt,
    BITMAPINFO256 *SrcInfo,
    char *SrcBits,
    TRANSINFO *TransInfo,
    int SrcX,
    int SrcY,
    int SrcWid,
    int SrcHgt,
    int Clip,
    bool Mirror,
    bool Flip,
    int TransColor );

/**
 *
 */
int ClipDibBlt(
    BITMAPINFO256 *DestInfo,
    RECT *ClipRect,
    int *DestX,
    int *DestY,
    int *DestWid,
    int *DestHgt,
    int *SrcX,
    int *SrcY,
    int *SrcWid,
    int *SrcHgt,
    bool Mirror,
    bool Flip );

/**
 *
 */
void GetDibDim(
    BITMAPINFO256 *Info,
    int *TotWid,
    int *TotHgt,
    int *Orien );

/**
 *
 */
int TileDibBlt(
    BITMAPINFO256 *DestInfo,
    char *DestBits,
    RECT *ClipRect,
    int DestX,
    int DestY,
    int DestWid,
    int DestHgt,
    int BlockWid,
    int BlockHgt,
    BITMAPINFO256 *SrcInfo,
    char *SrcBits,
    TRANSINFO *TransInfo,
    int SrcX,
    int SrcY,
    int SrcWid,
    int SrcHgt,
    int Trans,
    bool Mirror,
    bool Flip );

/**
 *
 */
int DibCheckTrans( BITMAPINFO256 *DibInfo, TRANSINFO *TransInfo, char *DibBits );

/**
 *
 */
HPALETTE *GetPaletteFromDib( char *FileName, int MakeIdentity );

/**
 *
 */
HPALETTE *ReadPalette( char *FileName, int ResourceId, int MakeIdentity );

/**
 *
 */
BITMAPINFOHEADER *DibOpenFile( char *szFile );

/**
 *
 */
char *ReadDibBits( char *szFile );

/**
 *
 */
BITMAPINFOHEADER *DibWriteClipped(
    BITMAPINFOHEADER *pDIB,
    TCHAR *szFile,
    int x,
    int y,
    int w,
    int h );

/**
 *
 */
int DibWriteFile( BITMAPINFOHEADER *pdib, TCHAR *szFile );

/**
 *
 */
HPALETTE *DibCreatePalette( BITMAPINFOHEADER *pdib );

/**
 * Will read a file in DIB format and return a global HANDLE to its BITMAPINFO.
 * This function will work with both "old" and "new" bitmap formats, but will always return a "new" BITMAPINFO.
 */
BITMAPINFOHEADER *DibReadBitmapInfo( HFILE fh );

/**
 * @brief Calculates the palette size in bytes. If the info. block
 *        is of the BITMAPCOREHEADER type, the number of colors is
 *        multiplied by 3 to give the palette size, otherwise the
 *        number of colors is multiplied by 4.
 * @return Palette size in number of bytes.
 */
WORD PaletteSize( VOID FAR * pv );

/**
 * @brief Creates a global memory block in DIB format that represents the Device-dependent bitmap (DDB) passed in.
 * @return A handle to the DIB.
 */
BITMAPINFOHEADER *DibFromBitmap(
    HBITMAP *hbm,
    DWORD biStyle,
    WORD biBits,
    HPALETTE *hPal,
    UINT wUsage );

/**
 * @brief Modifies the color table of the passed DIB for use with the wUsage parameter specifed.
 * @param pdib A PDIB structure as input.
 * @param hpal An HPALETTE structure as input.
 * @return Returns true on success, or false if the PDIB is invalid.
 *
 * If wUsage is DIB_PAL_COLORS the DIB color table is set to 0-256.
 * If wUsage is DIB_RGB_COLORS the DIB color table is set to the RGB values in the passed palette.
 */
BOOL DibSetUsage( BITMAPINFOHEADER pdib, HPALETTE hpal, UINT wUsage );
//BOOL DibSetUsage( BITMAPINFOHEADER *pdib, HPALETTE *hpal, UINT wUsage = DIB_RGB_COLORS );

/**
 *
 */
BITMAPINFOHEADER *DibDraw(
    HDC *hdc,
    int x,
    int y,
    int dx,
    int dy,
    BITMAPINFOHEADER *pdib,
    int x0,
    int y0,
    int dx0,
    int dy0,
    int rop,
    unsigned int wUsage );

/**
 *
 */
BITMAPINFOHEADER *DibCopy( BITMAPINFOHEADER *pdib );

/**
 *
 */
BITMAPINFOHEADER *DibCreate( int bits, int dx, int dy );

/**
 * Map the colors of the DIB, using GetNearestPaletteIndex, to the colors of the given palette.
 */
void DibMapToPalette(
    BITMAPINFOHEADER *pdib,
    HPALETTE *hpal,
    int TransLogic,
    int ZeroIsTrans );

/**
 *
 */
void xlatClut8( BYTE FAR *pb, DWORD dwSize, BYTE FAR *xlat );

/**
 *
 */
void xlatClut4( BYTE FAR *pb, DWORD dwSize, BYTE FAR *xlat );

/**
 *
 */
void xlatRle8( BYTE FAR *pb, DWORD dwSize, BYTE FAR *xlat );

/**
 *
 */
void xlatRle4( BYTE FAR *pb, DWORD dwSize, BYTE FAR *xlat );

/**
 *
 */
void memmove( char *d, char *s, int len );

/**
 *
 */
void CreateIdentityPalette( HPALETTE *hpal );

/**
 * @brief Copies a GDI palette.
 * @return Returns the copied DDI palette.
 */
HPALETTE CopyPalette( HPALETTE srcpal );

/**
 *
 */
void DibFree( BITMAPINFOHEADER *pdib );

/**
 *
 */
void DibFree( BITMAPINFOHEADER pdib );
