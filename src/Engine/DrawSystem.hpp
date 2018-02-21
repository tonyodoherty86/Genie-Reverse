
/**
 * @file    Engine\DrawSystem.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

class TDrawSystem
{
public:

	HINSTANCE *Inst;
	HWND *Wnd;
	HPALETTE *Pal;

	class TDrawArea *DrawArea;
	class TDrawArea *PrimaryArea;
	struct DrawAreaNode *DrawAreaList;

	IDirectDraw *DirDraw;
	IDirectDrawSurface *PrimarySurface;
	IDirectDrawClipper *Clipper;
	IDirectDrawPalette *DirDrawPal;

	unsigned int Flags;

	int ScreenWidth;
	int ScreenHeight;
	int ColorBits;
	int ErrorCode;
	int ChangedMode;
	int IsBanked;
	int CanSrcBlt;
	int Restored;

	int ModeAvail640;
	int ModeAvail800;
	int ModeAvail1024;
	int ModeAvail1280;
	int ModeAvail320_200;
	int ModeAvail320_240;
	int ModeAvail320_200_16;
	int ModeAvail320_240_16;
	int ModeAvail640_16;
	int ModeAvail800_16;
	int ModeAvail1024_16;

	PALETTEENTRY palette[256];

	char DrawType;
	char ScreenMode;

	TDrawSystem();

	~TDrawSystem();

	void CheckAvailModes(int full_screen);

	static int CheckAvailModesCallback(DDSURFACEDESC *lpDDSurfaceDesc, void *lpContext);

	int IsModeAvail(int wid_in, int hgt_in, int color_bits);

	void Init(HINSTANCE *inst_in, HWND *wnd_in, HPALETTE *pal_in, char type_in, char mode_in, int wid_in, int hgt_in, unsigned int flags_in);

	bool SetDisplaySize(int wid_in, int hgt_in, int color_bits);

	void ClearPrimarySurface();
	char CheckSurfaces();
	void ClearRestored();
	void DeleteSurfaces();
	void CreateSurfaces();

	LRESULT HandleSize(HWND *hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	LRESULT HandlePaletteChanged(HWND *hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	LRESULT HandleQueryNewPalette(HWND *hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	void Paint(RECT *rect);

	static int GetIsLostErrorNum(int ddrval);
	static int GetRestoreErrorNum(int ddrval);
	static int GetSetDispModeErrorNum(int ddrval);
	static int GetLockErrorNum(int ddrval);
	static int GetDCErrorNum(int ddrval);
	static int GetBlitErrorNum(int ddrval);
	static int GetCreateErrorNum(int ddrval);
	static int GetColorKeyErrorNum(int ddrval);

	void SetPalette(HPALETTE *pal_in);
	void ModifyPalette(int start_entry, int num_entries, PALETTEENTRY *pal_entries);
};
