
/**
 * @file    Engine\DIB.h
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

struct BITMAPINFO256
{
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD bmiColors[256];
};

struct TRANSINFO
{
    int AnyTrans;
    int x;
    int y;
    int w;
    int h;
    struct LINEINFO *LineInfo;
};

struct LINEINFO
{
    int AllTrans;
    int MidSolid;
    int StartX;
    int EndX;
};

void DibBlt(BITMAPINFO256 *DestInfo, char *DestBits, RECT *ClipRect, int DestX, int DestY, int DestWid, int DestHgt, BITMAPINFO256 *SrcInfo, char *SrcBits, int SrcX, int SrcY, int SrcWid, int SrcHgt, int Clip, int Mirror, int Flip);

void TransDibBlt(BITMAPINFO256 *DestInfo, char *DestBits, RECT *ClipRect, int DestX, int DestY, int DestWid, int DestHgt, BITMAPINFO256 *SrcInfo, char *SrcBits, TRANSINFO *TransInfo, int SrcX, int SrcY, int SrcWid, int SrcHgt, int Clip, int Mirror, int Flip, int TransColor);

int ClipDibBlt(BITMAPINFO256 *DestInfo, RECT *ClipRect, int *DestX, int *DestY, int *DestWid, int *DestHgt, int *SrcX, int *SrcY, int *SrcWid, int *SrcHgt, int Mirror, int Flip);

void GetDibDim(BITMAPINFO256 *Info, int *TotWid, int *TotHgt, int *Orien);

int TileDibBlt(BITMAPINFO256 *DestInfo, char *DestBits, RECT *ClipRect, int DestX, int DestY, int DestWid, int DestHgt, int BlockWid, int BlockHgt, BITMAPINFO256 *SrcInfo, char *SrcBits, TRANSINFO *TransInfo, int SrcX, int SrcY, int SrcWid, int SrcHgt, int Trans, int Mirror, int Flip);

int DibCheckTrans(BITMAPINFO256 *DibInfo, TRANSINFO *TransInfo, char *DibBits);

BITMAPINFOHEADER *GetPaletteFromDib(char *FileName, int MakeIdentity);

void *ReadPalette(char *FileName, int ResourceId, int MakeIdentity);

BITMAPINFOHEADER *DibOpenFile(char *szFile);

char *ReadDibBits(char *szFile);

BITMAPINFOHEADER *DibWriteClipped(BITMAPINFOHEADER *pDIB, char *szFile, int x, int y, int w, int h);

int DibWriteFile(BITMAPINFOHEADER *pdib, char *szFile);

void *DibCreatePalette(BITMAPINFOHEADER *pdib);

BITMAPINFOHEADER *DibReadBitmapInfo(int fh);

BITMAPINFOHEADER *DibFromBitmap(void *hbm, unsigned int biStyle, unsigned int biBits, void *hpal, unsigned int wUsage);

int DibSetUsage(BITMAPINFOHEADER *pdib, void *hpal, unsigned int wUsage);

BITMAPINFOHEADER *DibDraw(void *hdc, int x, int y, int dx, int dy, BITMAPINFOHEADER *pdib, int x0, int y0, int dx0, int dy0, int rop, unsigned int wUsage);

BITMAPINFOHEADER *DibCopy(BITMAPINFOHEADER *pdib);

BITMAPINFOHEADER *DibCreate(int bits, int dx, int dy);

void DibMapToPalette(BITMAPINFOHEADER *pdib, void *hpal, int TransLogic, int ZeroIsTrans);

void xlatClut8(char *pb, unsigned int dwSize, char *xlat);

void xlatClut4(char *pb, unsigned int dwSize, char *xlat);

void xlatRle8(char *pb, unsigned int dwSize, char *xlat);

void xlatRle4(char *pb, unsigned int dwSize, char *xlat);

void memmove(char *d, char *s, int len);

void CreateIdentityPalette(void *hpal);

void *CopyPalette(void *hpal);

void DibFree(BITMAPINFOHEADER *pdib);
