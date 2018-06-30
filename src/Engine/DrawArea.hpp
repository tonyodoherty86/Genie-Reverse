
/**
 * @file    Engine\DrawArea.hpp
 * @author  Yvan Burrie
 * @date    2018/02/21
 * @version 1.0
 */

class TDrawArea
{
public:

	TDrawSystem *DrawSystem;

	HWND *Wnd;

	char *Bits;

	BITMAPINFO256 *BitmapInfo;

	HGDIOBJ *Bitmap,
	        *OldBitmap;

	int Width,
	    Height;
	int Pitch;
	int Orien = 1;

	RECT ClipRect;

	HDC *DrawDc;
	IDirectDrawSurface *DrawSurface;
	DDSURFACEDESC SurfaceDesc;

	struct DrawAreaNode *Node;

	char *Name;

	char *LastBits;
	int LastPitch;

	void **DisplayOffsets;
	void **CurDisplayOffsets;
	void **FloatOffsets;

	class RGE_Color_Table *shadow_color_table;

	TSpan_List_Manager *SpanList;
	TSpan_List_Manager *CurSpanList;

	int Float_X_Delta,
        Float_Y_Delta;

	int DisplayOffsetsSz;
	int FloatOffsetsSz;

	int SystemMemOnly;
	int UsingVidMem;
	int UseTrans;
	int IsPrimarySurface;
	int Restored;
	int ExtendedLines;

	char TransColor = -1;

	TDrawArea(const char *SurfaceName, int ForceSystemMem);

	~TDrawArea();

	DrawAreaNode *Init(TDrawSystem *draw_system_in, int wid_in, int hgt_in, int Extend, int isPrimary_in);

	char CheckSurface();

	char *Lock(char *caller_name, int wait);
	void Unlock(char *caller_name);

	HDC *GetDc(char *caller_name);
	void ReleaseDc(char *caller_name);

	void SetSize(int wid_in, int hgt_in, int ExtendSurface);

	void Clear(tagRECT *rect, int color);
	void PtrClear(tagRECT *rect, int color);

	void SetAccessOffsets();
	void SetFloatOffsets(int X_Delta, int Y_Delta);
	void SetInfo();

	int AlignedWidth();
	void SetClipRect(RECT *rect);
	void SetClipRect(int x1, int y1, int x2, int y2);

	void Copy(TDrawArea *dest_area, int dest_x, int dest_y, RECT *src_rect, int allow_trans);
	void PtrCopy(TDrawArea *dest_area, int dest_x, int dest_y, RECT *src_rect);
	void PtrSpanCopy(TDrawArea *dest_area, int dest_x, int dest_y, RECT *src_rect, char **SpanListPtrs);
	void PtrSurfaceCopy(TDrawArea *dest_area, int dest_x, int dest_y, RECT *src_rect, int SourceLock, int DestLock);
	void OverlayMemCopy(RECT *src_rect, RECT *dest_rect, int xDelta, int yDelta, int xOffset, int YOffset);

	void SetTrans(int use_trans_in, char trans_color_in);
	void SetOverlayTrans(int use_trans_in, char trans_color_in);

	void SetPixel(int x, int y, char color);
	static void DrawLine(int x1, int y1, int x2, int y2, char color);
	void DrawRect(int x1, int y1, int x2, int y2, char color);
	void DrawRect(RECT *rect, char color);
	void DrawHorzLine(int x, int y, int len, char color);
	void DrawVertLine(int x, int y, int len, char color);
	void FillRect(int x1, int y1, int x2, int y2, char color);

	void DrawBevel(int x1, int y1, int x2, int y2, char c1, char c2);
	void DrawBevel2(int x1, int y1, int x2, int y2, char c1, char c2, char c3, char c4);
	void DrawBevel3(int x1, int y1, int x2, int y2, char c1, char c2, char c3, char c4, char c5, char c6);
	void DrawBevel21(int x1, int y1, int x2, int y2, char c1, char c2, char c3, char c4);
	void DrawBevel32(int x1, int y1, int x2, int y2, char c1, char c2, char c3, char c4, char c5, char c6);

	void SetShadowTable(class RGE_Color_Table *color_table_in);

	void DrawShadowBox(int x1, int y1, int x2, int y2);

	void GetPalette(PALETTEENTRY *palette1);
	void SetPalette(PALETTEENTRY *palette1);

	void take_snapshot(char *filespec, int *index_no);
};

struct DrawAreaNode
{
	TDrawArea *DrawArea;

	DrawAreaNode *PrevNode,
	             *NextNode;
};
