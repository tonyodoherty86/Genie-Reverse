
/**
 *
 */

char pszDriver[] = "DISPLAY";

int system_ignore_size_messages;

int PalSetRes;

int FullPalSets;

int AniPalSets;

/**
 *
 */
TDrawSystem::TDrawSystem()
{
    this->ColorBits = 8;

	system_ignore_size_messages = 0;

	ASMSet_Shadowing(
        0x00FF00FF,
        0x00000000,
        0xFF00FF00,
        0x00000000);
}

/**
 *
 */
TDrawSystem::~TDrawSystem()
{
	DDBLTFX ddbltfx;

	if( this->PrimarySurface && this->ScreenMode == 2 )
	{
		ddbltfx.dwSize = 100;
		ddbltfx.dwFillColor = 0;

		this->PrimarySurface->Blt(
			NULL,
			NULL,
			NULL,
			DDBLT_COLORFILL|DDBLT_WAIT,
			&ddbltfx);
	}
	this->DeleteSurfaces();

	if( this->DirDraw )
	{
		if( this->DirDrawPal )
		{
			this->DirDrawPal->Release();
			this->DirDrawPal = 0;
		}
		if( this->Clipper )
		{
			this->Clipper->Release();
			this->Clipper = 0;
		}
		if( this->ChangedMode )
		{
			this->DirDraw->RestoreDisplayMode();
			this->ChangedMode = 0;
		}
		this->DirDraw->Release();
		this->DirDraw = 0;
	}
}

void TDrawSystem::CheckAvailModes(int full_screen)
{
	if( full_screen )
	{
        int ResetDraw;

		if( this->DirDraw )
		{
			ResetDraw = 1;
		}
		else
		{
			if( DirectDrawCreate(0, &this->DirDraw, 0) )
				return;

			ResetDraw = 0;
		}
		this->DirDraw->EnumDisplayModes(
			0,
			(LPDDSURFACEDESC)NULL,
			this,
			(LPDDENUMMODESCALLBACK)TDrawSystem::CheckAvailModesCallback);

		if( ResetDraw == 0 )
		{
			this->DirDraw->Release();
			this->DirDraw = 0;
		}
	}
	else
	{
		this->ModeAvail640 = 1;

		if( HDC DeviceCaps = CreateICA(pszDriver, 0, 0, 0) )
		{
			int HorzRes = GetDeviceCaps(DeviceCaps, HORZRES);
			int VertRes = GetDeviceCaps(DeviceCaps, VERTRES);

			DeleteDC(DeviceCaps);

			if( HorzRes >= 800 )
				this->ModeAvail800 = 1;
			if( HorzRes >= 1024 )
				this->ModeAvail1024 = 1;
			if( HorzRes >= 1280 )
				this->ModeAvail1280 = 1;
		}
	}
}

int TDrawSystem::CheckAvailModesCallback(DDSURFACEDESC *lpDDSurfaceDesc, void *lpContext)
{
	int result; // eax@1
	unsigned int v3; // edx@1
	unsigned int v4; // edx@2
	unsigned int v5; // edx@20

	result = 1;
	v3 = lpDDSurfaceDesc->ddpfPixelFormat.dwRGBBitCount;
	if( v3 == 8 )
	{
		v4 = lpDDSurfaceDesc->dwWidth;
		if( v4 != 640 || lpDDSurfaceDesc->dwHeight != 480 )
		{
			if( v4 != 800 || lpDDSurfaceDesc->dwHeight != 600 )
			{
				if( v4 != 1024 || lpDDSurfaceDesc->dwHeight != 768 )
				{
					if( v4 != 1280 || lpDDSurfaceDesc->dwHeight != 1024 )
					{
						if( v4 == 320 )
						{
							if( lpDDSurfaceDesc->dwHeight == 200 )
							{
								*((_DWORD *)lpContext + 23) = 1;
							}
							else if( lpDDSurfaceDesc->dwHeight == 240 )
							{
								*((_DWORD *)lpContext + 24) = 1;
							}
						}
					}
					else
					{
						*((_DWORD *)lpContext + 22) = 1;
					}
				}
				else
				{
					*((_DWORD *)lpContext + 21) = 1;
				}
			}
			else
			{
				*((_DWORD *)lpContext + 20) = 1;
			}
		}
		else
		{
			*((_DWORD *)lpContext + 19) = 1;
		}
	}
	else if( v3 == 16 )
	{
		v5 = lpDDSurfaceDesc->dwWidth;
		if( v5 != 640 || lpDDSurfaceDesc->dwHeight != 480 )
		{
			if( v5 != 800 || lpDDSurfaceDesc->dwHeight != 600 )
			{
				if( v5 != 1024 || lpDDSurfaceDesc->dwHeight != 768 )
				{
					if( v5 == 320 )
					{
						if( lpDDSurfaceDesc->dwHeight == 200 )
						{
							*((_DWORD *)lpContext + 25) = 1;
						}
						else if( lpDDSurfaceDesc->dwHeight == 240 )
						{
							*((_DWORD *)lpContext + 26) = 1;
						}
					}
				}
				else
				{
					*((_DWORD *)lpContext + 29) = 1;
				}
			}
			else
			{
				*((_DWORD *)lpContext + 28) = 1;
			}
		}
		else
		{
			*((_DWORD *)lpContext + 27) = 1;
		}
	}
	return result;
}

int TDrawSystem::IsModeAvail(int wid_in, int hgt_in, int color_bits)
{
	switch( color_bits )
	{
		/* 0x08 Color-Bits */
		case 8:
			switch( wid_in )
			{
#ifdef DRAW_SYSTEM_RESOLUTION_1920
				case 1920:
					return this->ModeAvail1920;
#endif

				case 1280:
					return this->ModeAvail1280;

				case 1024:
					return this->ModeAvail1024;

				case 800:
					return this->ModeAvail800;

				case 640:
					return this->ModeAvail640;

				case 320:
					if( hgt_in == 200 )
						return this->ModeAvail320_200;

					if( hgt_in == 240 )
						return this->ModeAvail320_240;

					break;
			}
			break;

		/* 0x10 Color-Bits */
		case 16:
			switch( wid_in )
			{
				case 1024:
					return this->ModeAvail1024_16;

				case 800:
					return this->ModeAvail800_16;

				case 640:
					return this->ModeAvail640_16;

				case 320:
					if( hgt_in == 200 )
						return this->ModeAvail320_200_16;

					if( hgt_in == 240 )
						return this->ModeAvail320_240_16;

					break;
			}
			break;
	}
	return 0;
}

void TDrawSystem::Init(HINSTANCE *inst_in, HWND *wnd_in, HPALETTE *pal_in, char type_in, char mode_in, int wid_in, int hgt_in, unsigned int flags_in)
{
	unsigned int BitsPerPixel = 8;
	int index = 0;
	int v23;

    HRESULT DDResult;
	DDSURFACEDESC ddsd;
	DDBLTFX ddbltfx;
	DDCAPS ddcaps;
	PALETTEENTRY color_table[256];

	this->Wnd          = wnd_in;
	this->Pal          = pal_in;
	this->Inst         = inst_in;
	this->ScreenMode   = mode_in;
	this->ScreenWidth  = wid_in;
	this->DrawType     = type_in;
	this->ScreenHeight = hgt_in;
	this->Flags        = flags_in;

	if( type_in == 1 )
        return;

    DDResult = DirectDrawCreate(
        NULL,
        &this->DirDraw,
        NULL);
    if( DDResult != DD_OK )
    {
        this->ErrorCode = 1;
        return;
    }
    this->CheckAvailModes(1);

    if( this->ScreenMode == 1 )
    {
#ifdef DIRECT_DRAW
        DDResult = this->DirDraw->SetCooperativeLevel(
            this->Wnd,
            DDSCL_NORMAL);
        if( DDResult != DD_OK )
        {
            this->ErrorCode = 1;
            return;
        }
#endif
        memset(&ddsd, 0, sizeof(DDSURFACEDESC));
        ddsd.dwSize = sizeof(DDSURFACEDESC);

        DDResult = this->DirDraw->GetDisplayMode(&ddsd);
        if( DDResult != DD_OK )
        {
            this->ErrorCode = 1;
            return;
        }
        if( ddsd.ddpfPixelFormat.dwRGBBitCount != BitsPerPixel )
        {
            this->ErrorCode = 2;
            return;
        }
    }
    else
    {
#if ENGINE_AOC
    #define DRAW_SYSTEM_COOP_LEVEL DDSCL_FULLSCREEN|DDSCL_EXCLUSIVE|DDSCL_ALLOWREBOOT
#else
    #define DRAW_SYSTEM_COOP_LEVEL DDSCL_FULLSCREEN|DDSCL_EXCLUSIVE
#endif
#ifdef DIRECT_DRAW
        DDResult = this->DirDraw->SetCooperativeLevel(
            *this->Wnd,
            DRAW_SYSTEM_COOP_LEVEL);
        if( DDResult != DD_OK )
        {
            this->ErrorCode = 1;
            return;
        }

        DDResult = this->DirDraw->SetDisplayMode(
            this->ScreenWidth,
            this->ScreenHeight,
            this->ColorBits = BitsPerPixel);
        if( DDResult != DD_OK )
        {
            this->ErrorCode = 1;
            return;
        }
#endif
        this->ChangedMode = 1;
    }
    if( this->Pal )
    {
        GetPaletteEntries(
            *(HPALETTE*)this->Pal,
            0,
            256,
            color_table);
    }
    else
    {
        for( index = 0; index < 256; index++ )
        {
            color_table[index].peRed   = 0;
            color_table[index].peGreen = 0;
            color_table[index].peBlue  = 0;
            color_table[index].peFlags = 0;
        }
    }
    for( index = 0; index < 256; index++ )
    {
        this->palette[index].peRed   = 0;
        this->palette[index].peGreen = 0;
        this->palette[index].peBlue  = 0;
        this->palette[index].peFlags = 0;
    }
#ifdef DIRECT_DRAW
    DDResult = this->DirDraw->CreatePalette(
        DDPCAPS_8BIT|DDPCAPS_ALLOW256,
        color_table,
        &this->DirDrawPal,
        NULL);
    if( DDResult != DD_OK )
    {
        this->ErrorCode = 1;
        return;
    }
    DDResult = this->DirDrawPal->CreateSurface(
        0,
        0,
        256,
        this->palette);
#endif
    DDResult = this->DirDraw->CreateClipper(
        0,
        &this->Clipper,
        NULL);
    if( DDResult != DD_OK )
    {
        this->ErrorCode = 1;
        return;
    }
    DDResult = this->Clipper->SetHWnd(
        0,
        *this->Wnd);
    if( DDResult != DD_OK )
    {
        this->ErrorCode = 1;
        return;
    }
    this->CreateSurfaces();

    if( v23 == 0 )
    {
        this->ErrorCode = 1;
        return;
    }
    this->IsBanked = 0;
    ddcaps.dwSize = 316;

    DDResult = this->DirDraw->GetCaps(&ddcaps, 0);
    if( DDResult != DD_OK )
    {
        if( ddcaps.dwCaps & DDSCAPS_VIDEOPORT )
            this->IsBanked = 1;

        if( ddcaps.dwCaps & DDSCAPS_MIPMAP && BYTE1(ddcaps.dwCKeyCaps) & DDCKEYCAPS_DESTBLTCLRSPACE )
            this->CanSrcBlt = 1;
    }
    if( this->ScreenMode == 2 )
    {
        ddbltfx.dwSize      = 100;
        ddbltfx.dwFillColor = 0;

        this->PrimarySurface->Blt(
            NULL,
            NULL,
            NULL,
            DDBLT_COLORFILL|DDBLT_WAIT,
            &ddbltfx);
    }
}

bool TDrawSystem::SetDisplaySize(int wid_in, int hgt_in, int color_bits)
{
	DDBLTFX ddbltfx;

	if( this->DrawType   == 2 &&
        this->ScreenMode == 2 )
	{
		system_ignore_size_messages = 1;

		ddbltfx.dwSize      = 100;
		ddbltfx.dwFillColor = 0;

		this->PrimarySurface->Blt(
			NULL,
			NULL,
			NULL,
			DDBLT_COLORFILL|DDBLT_WAIT,
			&ddbltfx);

		int save_wid = this->ScreenWidth;
		int save_hgt = this->ScreenHeight;

		this->ScreenWidth  = wid_in;
		this->ScreenHeight = hgt_in;

		int DisplayChanged = this->DirDraw->SetDisplayMode(
            wid_in,
            hgt_in,
            color_bits);

		system_ignore_size_messages = 0;

		if( DisplayChanged )
		{
			this->ScreenWidth  = save_wid;
			this->ScreenHeight = save_hgt;

			return false;
		}
		else
		{
			this->ColorBits   = color_bits;
			this->ChangedMode = 1;

			if( this->PrimarySurface )
			{
				this->PrimarySurface->Release();
				this->PrimarySurface = 0;
			}

			this->CreateSurfaces();

			if( this->DrawArea )
            {
				this->DrawArea->SetSize(
					this->ScreenWidth,
					this->ScreenHeight,
					0);
            }

			SendMessageA(
				*this->Wnd,
				5u,/* TODO */
				0,
				(unsigned __int16)wid_in | (hgt_in << 16));

			return true;
		}
	}
	else
	{
		return false;
	}
}

void TDrawSystem::ClearPrimarySurface()
{
	DDBLTFX ddbltfx;

	if( this->PrimarySurface &&
        this->ScreenMode == 2 )
	{
		ddbltfx.dwSize = 100;
		ddbltfx.dwFillColor = 0;

		this->PrimarySurface->Blt(
			NULL,
			NULL,
			NULL,
			DDBLT_COLORFILL|DDBLT_WAIT,
			&ddbltfx);
	}
}

char TDrawSystem::CheckSurfaces()
{
	char v5;
	DrawAreaNode *v11;
	HRESULT DDResult;
	DDSURFACEDESC ddsd;
	DDBLTFX ddbltfx;

	if( this->DrawType != 2 )
		return 0;

	if( this->PrimarySurface &&
        this->DrawArea &&
        this->DrawArea->DrawSurface)
	{
        v5 = 0;
        DDResult = this->PrimarySurface->IsLost();
        if( DDResult )
        {
            TDrawSystem::GetIsLostErrorNum(DDResult);

            memset(&ddsd, 0, sizeof(DDSURFACEDESC));
            ddsd.dwSize = sizeof(DDSURFACEDESC);

            DDResult = this->DirDraw->GetDisplayMode(&ddsd);
            if( !DDResult && (
                    ddsd.dwWidth  != (unsigned int)this->ScreenWidth ||
                    ddsd.dwHeight != (unsigned int)this->ScreenHeight ||
                    ddsd.ddpfPixelFormat.dwRGBBitCount != 8) )
            {
                return 1;
            }
            DDResult = this->PrimarySurface->Restore();
            if( DDResult )
            {
                TDrawSystem::GetRestoreErrorNum(DDResult);
                return 3;
            }
            this->Restored = 1;

            v5 = 2;

            ddbltfx.dwSize      = 100;
            ddbltfx.dwFillColor = 0;

            DDResult = this->PrimarySurface->Blt(
                NULL,
                NULL,
                NULL,
                DDBLT_COLORFILL|DDBLT_WAIT,
                &ddbltfx);
        }
        v11 = this->DrawAreaList;
        if( !v11 )
            return v5;
        while( v11->DrawArea == this->PrimaryArea ||
               v11->DrawArea->CheckSurface() != 3 )
        {
            v11 = v11->NextNode;
            if( !v11 )
                return v5;
        }
	}
	return 3;
}

void TDrawSystem::ClearRestored()
{
	for ( this->Restored = 0; this->DrawAreaList; this->DrawAreaList = this->DrawAreaList->NextNode )
	{
		this->DrawAreaList->DrawArea->Restored = 0;
	}
}

void TDrawSystem::DeleteSurfaces()
{
	if( this->DrawArea )
		delete this->DrawArea;

	if( this->PrimarySurface )
	{
		if( this->PrimaryArea )
			delete this->PrimaryArea;

		this->PrimaryArea = 0;
		this->PrimarySurface->Release();
		this->PrimarySurface = 0;
	}
}

void TDrawSystem::CreateSurfaces()
{
    HRESULT DDResult;
	RECT wnd_rect;
	DDSURFACEDESC ddsd;
	DDBLTFX ddbltfx;

	if( this->DrawType != 2 )
	{
        LABEL_18:
		if( !this->DrawArea )
		{
			this->DrawArea = new TDrawArea("Back Buffer", 0);

			if( this->ScreenMode == 1 )
			{
				GetClientRect(*this->Wnd, &wnd_rect);
				this->DrawArea->Init(this, wnd_rect.right, wnd_rect.bottom, 0, 0);
			}
			else
			{
				this->DrawArea->Init(this, this->ScreenWidth, this->ScreenHeight, 0, 0);
			}
		}
		return;
	}
	if( this->PrimarySurface )
		goto LABEL_29;

	memset(&ddsd, 0, sizeof(DDSURFACEDESC));
	ddsd.dwSize = sizeof(DDSURFACEDESC);
	ddsd.dwFlags = 1;
	ddsd.ddsCaps.dwCaps = 512;

	DDResult = this->DirDraw->CreateSurface(
        &ddsd,
        &this->PrimarySurface,
        NULL);
	if( DDResult != DD_OK )
	{
        return;
	}
    if( this->ScreenMode == 2 )
    {
        ddbltfx.dwSize = 100;
        ddbltfx.dwFillColor = 0;

        this->PrimarySurface->Blt(
            NULL,
            NULL,
            NULL,
            DDBLT_COLORFILL|DDBLT_WAIT,
            &ddbltfx);
    }
    if( (this->ColorBits != 8 ||
        this->PrimarySurface->SetPalette(this->DirDrawPal) == DD_OK) &&
        this->PrimarySurface->SetClipper(this->Clipper)    == DD_OK )
    {
        LABEL_29:
        if( !this->PrimaryArea )
        {
            this->PrimaryArea = new TDrawArea("Primary Surface", 0);

            if( this->ScreenMode == 1 )
            {
                GetClientRect(*this->Wnd, &wnd_rect);

                if( !this->PrimaryArea->Init(this, wnd_rect.right, wnd_rect.bottom, 0, 1) )
                {
                    return;
                }
            }
            else if( !this->PrimaryArea->Init(this, this->ScreenWidth, this->ScreenHeight, 0, 1) )
            {
                return;
            }
        }
        goto LABEL_18;
    }
}

bool TDrawSystem::HandleSize(HWND *hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	RECT wnd_rect;

	if( this->DrawArea )
	{
		if( this->DrawType == 1 ||
            this->ScreenMode == 1 )
		{
			GetClientRect(*this->Wnd, &wnd_rect);

			this->ScreenWidth  = wnd_rect.right;
			this->ScreenHeight = wnd_rect.bottom;
		}
		if( this->PrimaryArea )
        {
			this->PrimaryArea->SetSize(this->ScreenWidth, this->ScreenHeight, 0);
        }
		this->DrawArea->SetSize(this->ScreenWidth, this->ScreenHeight, 0);
	}
	return true;
}

bool TDrawSystem::HandlePaletteChanged(HWND *hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if( hwnd != this->Wnd )
    {
		this->HandleQueryNewPalette(hwnd, msg, wParam, lParam);
    }
    return true;
}

bool TDrawSystem::HandleQueryNewPalette(HWND *hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    char v8;
	HDC v6;

	if( !this->Pal || (this->DrawType != 1 && this->ScreenMode != 1) )
		goto RetFalseModifyPalette;

	v6 = GetDC(*this->Wnd);

	if( this->Pal )
		SelectPalette(v6, *this->Pal, 0);

	v8 = RealizePalette(v6);
	ReleaseDC(*this->Wnd, v6);

	if( v8 )
	{
		InvalidateRect(*this->Wnd, 0, 0);
		return true;
	}
	else
	{
		RetFalseModifyPalette:
		this->ModifyPalette(0, 256, this->palette);
		return false;
	}
}

void TDrawSystem::Paint(RECT *rect)
{
	RECT r2;
	RECT r1;

	if( this->DrawType != 1 &&
		this->PrimarySurface &&
		this->DrawArea &&
		this->DrawArea->DrawSurface )
	{
		if( this->ScreenMode == 1 )
		{
			GetClientRect(*this->Wnd, &r1);

			r2.top    = r1.top;
			r2.right  = r1.right;
			r2.left   = r1.left;
			r2.bottom = r1.bottom;

			ClientToScreen(*this->Wnd, (LPPOINT)&r2.left);
			ClientToScreen(*this->Wnd, (LPPOINT)&r2.right);
		}
		else
		{
			int v5 = this->ScreenWidth;
			int v6 = this->ScreenHeight;

			r1.left   = 0;
			r1.top    = 0;
			r1.right  = v5;
			r1.bottom = v6;

			r2.left   = 0;
			r2.top    = 0;
			r2.right  = v5;
			r2.bottom = v6;
		}
		if( rect )
		{
			int v7 = rect->left;
			if( v7 < 0 )
				r1.left = 0;
			r1.left = v7;

			int v8 = rect->top;
			if( v8 < 0 )
                v8 = 0;
			r1.top = v8;

			int v9 = rect->right;
			if( v9 >= this->ScreenWidth )
				v9 = this->ScreenWidth - 1;

			int v10 = rect->bottom;
			if( v10 >= this->ScreenHeight )
				v10 = this->ScreenHeight - 1;

			r2.left += v7;
			int v15 = v9 + r2.left - v7;
			int v16 = v10 + v8 + r2.top - v8;
			r2.top += v8;

			r1.right  = v9 + 1;
			r1.bottom = v10 + 1;

			r2.right  = v15 + 1;
			r2.bottom = v16 + 1;
		}
		this->PrimarySurface->Blt(
			&r2,
			this->DrawArea->DrawSurface,
			&r1,
			DDBLT_PRESENTATION,
			NULL);
	}
}

int TDrawSystem::GetIsLostErrorNum(int ddrval)
{
	if( ddrval <= -2005532542 )
	{
		if( ddrval == -2005532542 )
			return 1700;
		if( ddrval == -2147024809 )
			return 1701;
		return 1799;
	}
	if( ddrval == -2005532222 )
	{
		return 1702;
	}
	else
	{
		if( ddrval )
			return 1799;
		return 0;
	}
}

int TDrawSystem::GetRestoreErrorNum(int ddrval)
{
	if( ddrval <= -2147467259 )
	{
		if( ddrval == -2147467259 )
			return 1800;
		if( ddrval == -2147467263 )
			return 1807;
		return 1899;
	}
	if( ddrval <= -2147024809 )
	{
		if( ddrval == -2147024809 )
			return 1804;
		if( ddrval == -2147024882 )
			return 1806;
		return 1899;
	}
	if( ddrval <= -2005532542 )
	{
		if( ddrval == -2005532542 )
			return 1803;
		if( ddrval == -2005532577 )
			return 1802;
		return 1899;
	}
	if( ddrval <= -2005532085 )
	{
		if( ddrval == -2005532085 )
			return 1808;
		if( ddrval == -2005532447 )
			return 1805;
		return 1899;
	}
	if( ddrval == -2005532084 )
	{
		return 1801;
	}
	else
	{
		if( ddrval )
			return 1899;
		return 0;
	}
}

int TDrawSystem::GetSetDispModeErrorNum(int ddrval)
{
	if( ddrval <= -2147467259 )
	{
		if( ddrval == -2147467259 )
			return 1900;
		if( ddrval == -2147467263 )
			return 1907;
		return 1999;
	}
	if( ddrval <= -2005532552 )
	{
		if( ddrval == -2005532552 )
			return 1901;
		if( ddrval == -2147024809 )
			return 1903;
		return 1999;
	}
	if( ddrval <= -2005532512 )
	{
		if( ddrval == -2005532512 )
			return 1904;
		if( ddrval == -2005532542 )
			return 1902;
		return 1999;
	}
	if( ddrval <= -2005532242 )
	{
		if( ddrval == -2005532242 )
			return 1906;
		if( ddrval == -2005532447 )
			return 1905;
		return 1999;
	}
	if( ddrval == -2005532132 )
	{
		return 1909;
	}
	else if( ddrval == -2005532082 )
	{
		return 1908;
	}
	else
	{
		if( ddrval )
			return 1999;
		return 0;
	}
}

int TDrawSystem::GetLockErrorNum(int ddrval)
{
	if( ddrval <= -2147024882 )
	{
		if( ddrval == -2147024882 )
			return 2006;
		if( ddrval == -2147467259 )
			return 2000;
		return 2099;
	}
	if( ddrval <= -2005532542 )
	{
		if( ddrval == -2005532542 )
			return 2001;
		if( ddrval == -2147024809 )
			return 2002;
		return 2099;
	}
	if( ddrval <= -2005532242 )
	{
		if( ddrval == -2005532242 )
			return 2003;
		if( ddrval == -2005532522 )
			return 2008;
		return 2099;
	}
	if( ddrval <= -2005532132 )
	{
		if( ddrval == -2005532132 )
			return 2005;
		if( ddrval == -2005532222 )
			return 2004;
		return 2099;
	}
	if( ddrval == -2005532088 )
	{
		return 2007;
	}
	else
	{
		if( ddrval )
			return 2099;
		return 0;
	}
}

int TDrawSystem::GetDCErrorNum(int ddrval)
{
	if( ddrval <= -2147467259 )
	{
		if( ddrval == -2147467259 )
			return 2100;
		if( ddrval == -2147467263 )
			return 2106;
		return 2199;
	}
	if( ddrval <= -2005532542 )
	{
		if( ddrval == -2005532542 )
			return 2102;
		if( ddrval == -2147024809 )
			return 2103;
		return 2199;
	}
	if( ddrval <= -2005532132 )
	{
		if( ddrval == -2005532132 )
			return 2107;
		if( ddrval == -2005532222 )
			return 2105;
		return 2199;
	}
	if( ddrval == -2005532080 )
	{
		return 2104;
	}
	else if( ddrval == -2005532052 )
	{
		return 2101;
	}
	else
	{
		if( ddrval )
			return 2199;
		return 0;
	}
}

int TDrawSystem::GetBlitErrorNum(int ddrval)
{
	if( ddrval <= -2147467259 )
	{
		if( ddrval == -2147467259 )
			return 2200;
		if( ddrval == -2147467263 )
			return 2211;
		return 2299;
	}
	if( ddrval <= -2005532562 )
	{
		if( ddrval == -2005532562 )
			return 2204;
		if( ddrval == -2147024809 )
			return 2202;
		return 2299;
	}
	if( ddrval <= -2005532522 )
	{
		if( ddrval == -2005532522 )
			return 2205;
		if( ddrval == -2005532542 )
			return 2201;
		return 2299;
	}
	if( ddrval <= -2005532467 )
	{
		if( ddrval == -2005532467 )
			return 2208;
		if( ddrval == -2005532492 )
			return 2206;
		return 2299;
	}
	if( ddrval <= -2005532392 )
	{
		if( ddrval == -2005532392 )
			return 2213;
		if( ddrval == -2005532422 )
			return 2212;
		return 2299;
	}
	if( ddrval <= -2005532362 )
	{
		if( ddrval == -2005532362 )
			return 2215;
		if( ddrval == -2005532382 )
			return 2214;
		return 2299;
	}
	if( ddrval <= -2005532242 )
	{
		if( ddrval == -2005532242 )
			return 2216;
		if( ddrval == -2005532332 )
			return 2203;
		return 2299;
	}
	if( ddrval <= -2005532097 )
	{
		if( ddrval == -2005532097 )
			return 2207;
		if( ddrval == -2005532222 )
			return 2210;
		return 2299;
	}
	if( ddrval == -2005532096 )
	{
		return 2209;
	}
	else
	{
		if( ddrval )
			return 2299;
		return 0;
	}
}

int TDrawSystem::GetCreateErrorNum(int ddrval)
{
	if( ddrval <= -2147024882 )
	{
		if( ddrval == -2147024882 )
			return 2312;
		if( ddrval == -2147467259 )
			return 2300;
		return 2399;
	}
	if( ddrval <= -2005532577 )
	{
		if( ddrval == -2005532577 )
			return 2315;
		if( ddrval == -2147024809 )
			return 2302;
		return 2399;
	}
	if( ddrval <= -2005532542 )
	{
		if( ddrval == -2005532542 )
			return 2301;
		if( ddrval == -2005532572 )
			return 2306;
		return 2399;
	}
	if( ddrval <= -2005532492 )
	{
		if( ddrval == -2005532492 )
			return 2308;
		if( ddrval == -2005532527 )
			return 2307;
		return 2399;
	}
	if( ddrval <= -2005532447 )
	{
		if( ddrval == -2005532447 )
			return 2311;
		if( ddrval == -2005532460 )
			return 2305;
		return 2399;
	}
	if( ddrval <= -2005532332 )
	{
		if( ddrval == -2005532332 )
			return 2310;
		if( ddrval == -2005532442 )
			return 2309;
		return 2399;
	}
	if( ddrval <= -2005532109 )
	{
		if( ddrval == -2005532109 )
			return 2304;
		if( ddrval == -2005532292 )
			return 2303;
		return 2399;
	}
	if( ddrval == -2005532108 )
	{
		return 2313;
	}
	else if( ddrval == -2005532107 )
	{
		return 2314;
	}
	else
	{
		if( ddrval )
			return 2399;
		return 0;
	}
}

int TDrawSystem::GetColorKeyErrorNum(int ddrval)
{
	if( ddrval <= -2147467259 )
	{
		if( ddrval == -2147467259 )
			return 2400;
		if( ddrval == -2147467263 )
			return 2407;
		return 2499;
	}
	if( ddrval <= -2005532542 )
	{
		if( ddrval == -2005532542 )
			return 2401;
		if( ddrval == -2147024809 )
			return 2402;
		return 2499;
	}
	if( ddrval <= -2005532222 )
	{
		if( ddrval == -2005532222 )
			return 2406;
		if( ddrval == -2005532412 )
			return 2404;
		return 2499;
	}
	if( ddrval <= -2005532092 )
	{
		if( ddrval == -2005532092 )
			return 2405;
		if( ddrval == -2005532132 )
			return 2408;
		return 2499;
	}
	if( ddrval == -2005532080 )
	{
		return 2403;
	}
	else
	{
		if( ddrval )
			return 2499;
		return 0;
	}
}

void TDrawSystem::SetPalette(HPALETTE *pal_in)
{
	PALETTEENTRY color_table[256];

	if( this->Pal = pal_in )
	{
		GetPaletteEntries(
			*pal_in,
			0x0000,
			0x0100,
			color_table);
	}
	else
	{
		for ( int i = 0; i < 256; i++ )
		{
			color_table[i].peRed = 0;
			color_table[i].peGreen = 0;
			color_table[i].peBlue = 0;
			color_table[i].peFlags = 0;
		}
	}

	color_table[0x0000].peRed   = 0;
	color_table[0x0000].peGreen = 0;
	color_table[0x0000].peBlue  = 0;
	color_table[0x0000].peFlags = 0;

	color_table[0x00FF].peRed   = -1;
	color_table[0x00FF].peGreen = -1;
	color_table[0x00FF].peBlue  = -1;
	color_table[0x00FF].peFlags = 0;

	this->ModifyPalette(0x0000, 0x0100, color_table);
}

void TDrawSystem::ModifyPalette(int start_entry, int num_entries, PALETTEENTRY *pal_entries)
{
	PalSetRes = -99;

	if( num_entries == 256 )
		FullPalSets++;

	if( start_entry < num_entries + start_entry )
	{
		char *v6 = (char*)&this->palette[start_entry];
		int v7 = start_entry;
		int i = num_entries;
		do
		{
			v6 += 4;
			*((PALETTEENTRY *)v6 - 1) = *(PALETTEENTRY *)((char *)pal_entries)[++v7 - start_entry];
		}
		while( --i );
	}
	if( this->DrawType != 1 &&
        this->DirDrawPal )
	{
		if( num_entries == 7 )
			AniPalSets++;

		this->DirDrawPal->SetEntries(
			0,
			start_entry,
			num_entries,
			pal_entries);
	}
}
