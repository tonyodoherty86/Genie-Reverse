
/**
 * @file    Engine\DrawSystem.cpp
 * @author  Yvan Burrie
 * @date    2018/08/11
 * @version 1.0
 */

#ifndef DRAW_SYSTEM_CPP
#define DRAW_SYSTEM_CPP

/**
 * @brief
 */
bool system_ignore_size_messages;

/**
 * @brief
 */
int PalSetRes;

/**
 * @brief
 */
int FullPalSets;

/**
 * @brief
 */
int AniPalSets;

TDrawSystem::TDrawSystem()
{
    this->ColorBits = 8;

    system_ignore_size_messages = false;

    ASMSet_Shadowing(
        0x00FF00FF,
        0x00000000,
        0xFF00FF00,
        0x00000000);
}

TDrawSystem::~TDrawSystem()
{
    DDBLTFX ddbltfx;

    if( this->PrimarySurface &&
        this->ScreenMode == 2 ){

        ddbltfx.dwSize      = 100;
        ddbltfx.dwFillColor = 0;

        this->PrimarySurface->Blt(
            nullptr,
            nullptr,
            nullptr,
            DDBLT_COLORFILL|DDBLT_WAIT,
            &ddbltfx);
    }
    this->DeleteSurfaces();

    if( this->DirDraw ){
        if( this->DirDrawPal ){
            this->DirDrawPal->Release();
            this->DirDrawPal = nullptr;
        }
        if( this->Clipper ){
            this->Clipper->Release();
            this->Clipper = nullptr;
        }
        if( this->ChangedMode ){
            this->DirDraw->RestoreDisplayMode();
            this->ChangedMode = false;
        }
        this->DirDraw->Release();
        this->DirDraw = nullptr;
    }
}

bool TDrawSystem::CheckAvailModes( bool full_screen )
{
    HRESULT ddres;

    if( full_screen ){

        bool ResetDraw = false;

        if( this->DirDraw ){

            ResetDraw = true;

        }else{

            ddres = DirectDrawCreate(
                nullptr,
                &this->DirDraw,
                nullptr);
            if( ddres != DD_OK ){
                return false;
            }
        }

        ddres = this->DirDraw->EnumDisplayModes(
            (DWORD)0,
            (LPDDSURFACEDESC)nullptr,
            (LPVOID)this,
            (LPDDENUMMODESCALLBACK)TDrawSystem::CheckAvailModesCallback);
        if( ddres != DD_OK ){
            return false;
        }

        if( ResetDraw == false ){
            this->DirDraw->Release();
            this->DirDraw = nullptr;
        }
    }else{

        this->ModeAvail640 = true;

        if( HDC DeviceCaps = CreateICA("DISPLAY", 0, 0, 0) ){

            int HorzRes = GetDeviceCaps(DeviceCaps, HORZRES);
            int VertRes = GetDeviceCaps(DeviceCaps, VERTRES);

            DeleteDC(DeviceCaps);

            if( VertRes ){
                if( HorzRes >= 800 ){
                    this->ModeAvail800 = true;
                }
                if( HorzRes >= 1024 ){
                    this->ModeAvail1024 = true;
                }
                if( HorzRes >= 1280 ){
                    this->ModeAvail1280 = true;
                }
                if( HorzRes >= 1366 ){
                    this->ModeAvail1366 = true;
                }
                if( HorzRes >= 1920 ){
                    this->ModeAvail1920 = true;
                }
            }
        }
    }

    return true;
}

int TDrawSystem::CheckAvailModesCallback( DDSURFACEDESC *lpDDSurfaceDesc, TDrawSystem *lpContext )
{
    unsigned int v4;
    unsigned int v5;

    if( lpDDSurfaceDesc->ddpfPixelFormat.dwRGBBitCount == 8 ){

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
                                *((int *)lpContext + 23) = 1;
                            }
                            else if( lpDDSurfaceDesc->dwHeight == 240 )
                            {
                                *((int *)lpContext + 24) = 1;
                            }
                        }
                    }
                    else
                    {
                        *((int *)lpContext + 22) = 1;
                    }
                }
                else
                {
                    *((int *)lpContext + 21) = 1;
                }
            }
            else
            {
                *((int *)lpContext + 20) = 1;
            }
        }
        else
        {
            *((int *)lpContext + 19) = 1;
        }
    }
    else if( lpDDSurfaceDesc->ddpfPixelFormat.dwRGBBitCount == 16 )
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
                            *((int *)lpContext + 25) = 1;
                        }
                        else if( lpDDSurfaceDesc->dwHeight == 240 )
                        {
                            *((int *)lpContext + 26) = 1;
                        }
                    }
                }
                else
                {
                    *((int *)lpContext + 29) = 1;
                }
            }
            else
            {
                *((int *)lpContext + 28) = 1;
            }
        }
        else
        {
            *((int *)lpContext + 27) = 1;
        }
    }

    return DDENUMRET_OK;
}

bool TDrawSystem::IsModeAvail( int wid_in, int hgt_in, int color_bits )
{
    switch( color_bits ){

    case 8: switch( wid_in ){

        case 1920:
            return this->ModeAvail1920;

        case 1366:
            return this->ModeAvail1366;

        case 1280:
            return this->ModeAvail1280;

        case 1024:
            return this->ModeAvail1024;

        case 800:
            return this->ModeAvail800;

        case 640:
            return this->ModeAvail640;

        case 320:
            switch( hgt_in ){

            case 200:
                return this->ModeAvail320_200;

            case 240:
                return this->ModeAvail320_240;
            }
            break;
    }
    break;

    case 16: switch( wid_in ){

        case 1920:
            return this->ModeAvail1920_16;

        case 1366:
            return this->ModeAvail1366_16;

        case 1280:
            return this->ModeAvail1280_16;

        case 1024:
            return this->ModeAvail1024_16;

        case 800:
            return this->ModeAvail800_16;

        case 640:
            return this->ModeAvail640_16;

        case 320:
            switch( hgt_in ){

            case 200:
                return this->ModeAvail320_200_16;

            case 240:
                return this->ModeAvail320_240_16;
            }
            break;
        }
        break;
    }

    return false;
}

/**
 *
 */
void TDrawSystem::Init(
    HINSTANCE *inst_in,
    HWND *wnd_in,
    HPALETTE *pal_in,
    char type_in,
    char mode_in,
    int wid_in,
    int hgt_in,
    unsigned int flags_in )
{
    this->Wnd          = wnd_in;
    this->Pal          = pal_in;
    this->Inst         = inst_in;
    this->ScreenMode   = mode_in;
    this->ScreenWidth  = wid_in;
    this->DrawType     = type_in;
    this->ScreenHeight = hgt_in;
    this->Flags        = flags_in;

    if( type_in == 1 ){
        return;
    }

    HRESULT ddres;

    ddres = DirectDrawCreate(
        nullptr,
        &this->DirDraw,
        nullptr);
    if( ddres != DD_OK ){
        this->ErrorCode = 1;
        return;
    }

    this->CheckAvailModes(true);

    if( this->ScreenMode == 1 ){
        ddres = this->DirDraw->SetCooperativeLevel(
            *this->Wnd,
            DDSCL_NORMAL);
        if( ddres != DD_OK ){
            this->ErrorCode = 1;
            return;
        }
        DDSURFACEDESC ddsd;
        memset(&ddsd, 0, sizeof(DDSURFACEDESC));
        ddsd.dwSize = sizeof(DDSURFACEDESC);

        ddres = this->DirDraw->GetDisplayMode(&ddsd);
        if( ddres != DD_OK ){
            this->ErrorCode = 1;
            return;
        }
        if( ddsd.ddpfPixelFormat.dwRGBBitCount != 8 ){
            this->ErrorCode = 2;
            return;
        }
    }else{
#if ENGINE_AOC
    #define DRAW_SYSTEM_COOP_LEVEL DDSCL_FULLSCREEN|DDSCL_EXCLUSIVE|DDSCL_ALLOWREBOOT
#else
    #define DRAW_SYSTEM_COOP_LEVEL DDSCL_FULLSCREEN|DDSCL_EXCLUSIVE
#endif
        ddres = this->DirDraw->SetCooperativeLevel(
            *this->Wnd,
            DRAW_SYSTEM_COOP_LEVEL);
        if( ddres != DD_OK ){
            this->ErrorCode = 1;
            return;
        }

        ddres = this->DirDraw->SetDisplayMode(
            this->ScreenWidth,
            this->ScreenHeight,
            this->ColorBits = 8);
        if( ddres != DD_OK ){
            this->ErrorCode = 1;
            return;
        }

        this->ChangedMode = true;
    }

    PALETTEENTRY color_table[256];
    int index = 0;
    if( this->Pal ){
        GetPaletteEntries(
            *this->Pal,
            0,
            256,
            color_table);
    }else{
        for( index = 0; index < 256; index++ ){
            color_table[index].peRed   = 0;
            color_table[index].peGreen = 0;
            color_table[index].peBlue  = 0;
            color_table[index].peFlags = 0;
        }
    }

    for( index = 0; index < 256; index++ ){
        this->palette[index].peRed   = 0;
        this->palette[index].peGreen = 0;
        this->palette[index].peBlue  = 0;
        this->palette[index].peFlags = 0;
    }

    ddres = this->DirDraw->CreatePalette(
        DDPCAPS_8BIT|DDPCAPS_ALLOW256,
        color_table,
        &this->DirDrawPal,
        nullptr);
    if( ddres != DD_OK ){
        this->ErrorCode = 1;
        return;
    }

    ddres = this->DirDrawPal->SetEntries(
        0,
        0,
        256,
        this->palette);

    ddres = this->DirDraw->CreateClipper(
        0,
        &this->Clipper,
        nullptr);
    if( ddres != DD_OK ){
        this->ErrorCode = 1;
        return;
    }

    ddres = this->Clipper->SetHWnd(
        0,
        *this->Wnd);
    if( ddres != DD_OK ){
        this->ErrorCode = 1;
        return;
    }

    this->CreateSurfaces();

    this->IsBanked = false;

    DDCAPS ddcaps;
    ddcaps.dwSize = 316;
    ddres = this->DirDraw->GetCaps(&ddcaps, 0);
    if( ddres != DD_OK ){
        if( ddcaps.dwCaps & DDSCAPS_VIDEOPORT ){
            this->IsBanked = true;
        }
        if( ddcaps.dwCaps & DDSCAPS_MIPMAP &&
            BYTE1(ddcaps.dwCKeyCaps) & DDCKEYCAPS_DESTBLTCLRSPACE ){
            this->CanSrcBlt = true;
        }
    }

    if( this->ScreenMode == 2 ){

        DDBLTFX ddbltfx;
        ddbltfx.dwSize      = 100;
        ddbltfx.dwFillColor = 0;

        this->PrimarySurface->Blt(
            nullptr,
            nullptr,
            nullptr,
            DDBLT_COLORFILL|DDBLT_WAIT,
            &ddbltfx);
    }
}

bool TDrawSystem::SetDisplaySize( int wid_in, int hgt_in, int color_bits )
{

    if( this->DrawType == 2 &&
        this->ScreenMode == 2 ){

        system_ignore_size_messages = true;

        DDBLTFX ddbltfx;
        ddbltfx.dwSize      = 100;
        ddbltfx.dwFillColor = 0;

        this->PrimarySurface->Blt(
            nullptr,
            nullptr,
            nullptr,
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

        system_ignore_size_messages = false;

        if( DisplayChanged ){

            this->ScreenWidth  = save_wid;
            this->ScreenHeight = save_hgt;

            return false;
        }else{

            this->ColorBits   = color_bits;
            this->ChangedMode = true;

            if( this->PrimarySurface ){
                this->PrimarySurface->Release();
                this->PrimarySurface = nullptr;
            }

            this->CreateSurfaces();

            if( this->DrawArea ){
                this->DrawArea->SetSize(
                    this->ScreenWidth,
                    this->ScreenHeight,
                    0);
            }

            SendMessageA(
                *this->Wnd,
                5u,/* TODO */
                0,
                (unsigned short)wid_in | (hgt_in << 16));

            return true;
        }
    }else{
        return false;
    }
}

void TDrawSystem::ClearPrimarySurface()
{
    if( this->PrimarySurface &&
        this->ScreenMode == 2 ){

        DDBLTFX ddbltfx;
        ddbltfx.dwSize = 100;
        ddbltfx.dwFillColor = 0;

        this->PrimarySurface->Blt(
            nullptr,
            nullptr,
            nullptr,
            DDBLT_COLORFILL|DDBLT_WAIT,
            &ddbltfx);
    }
}

char TDrawSystem::CheckSurfaces()
{
    HRESULT ddres;

    if( this->DrawType != 2 )
        return 0;

    if( this->PrimarySurface &&
        this->DrawArea &&
        this->DrawArea->DrawSurface)
    {
        char v5 = 0;
        ddres = this->PrimarySurface->IsLost();
        if( ddres )
        {
            TDrawSystem::GetIsLostErrorNum(ddres);

            DDSURFACEDESC ddsd;
            memset(&ddsd, 0, sizeof(DDSURFACEDESC));
            ddsd.dwSize = sizeof(DDSURFACEDESC);

            ddres = this->DirDraw->GetDisplayMode(&ddsd);
            if( !ddres && (
                    ddsd.dwWidth  != (unsigned int)this->ScreenWidth ||
                    ddsd.dwHeight != (unsigned int)this->ScreenHeight ||
                    ddsd.ddpfPixelFormat.dwRGBBitCount != 8) )
            {
                return 1;
            }
            ddres = this->PrimarySurface->Restore();
            if( ddres )
            {
                TDrawSystem::GetRestoreErrorNum(ddres);
                return 3;
            }

            this->Restored = true;

            v5 = 2;

            DDBLTFX ddbltfx;
            ddbltfx.dwSize      = 100;
            ddbltfx.dwFillColor = 0;

            ddres = this->PrimarySurface->Blt(
                nullptr,
                nullptr,
                nullptr,
                DDBLT_COLORFILL|DDBLT_WAIT,
                &ddbltfx);
        }
        DrawAreaNode *v11 = this->DrawAreaList;
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
    for(
        this->Restored = false;
        this->DrawAreaList;
        this->DrawAreaList = this->DrawAreaList->NextNode ){

        this->DrawAreaList->DrawArea->Restored = false;
    }
}

void TDrawSystem::DeleteSurfaces()
{
    if( this->DrawArea ){
        delete this->DrawArea;
    }
    if( this->PrimarySurface ){
        if( this->PrimaryArea ){
            delete this->PrimaryArea;
        }
        this->PrimaryArea = nullptr;

        this->PrimarySurface->Release();
        this->PrimarySurface = nullptr;
    }
}

void TDrawSystem::CreateSurfaces()
{
    HRESULT ddres;
    RECT wnd_rect;

    if( this->DrawType != 2 ){

        SetupBackBufferArea:
        if( this->DrawArea == nullptr ){

            this->DrawArea = new TDrawArea("Back Buffer", 0);

            if( this->ScreenMode == 1 ){
                GetClientRect(*this->Wnd, &wnd_rect);
                this->DrawArea->Init(this, wnd_rect.right, wnd_rect.bottom, 0, 0);
            }else{
                this->DrawArea->Init(this, this->ScreenWidth, this->ScreenHeight, 0, 0);
            }
        }
        return;
    }

    if( this->PrimarySurface ){
        goto SetupPrimaryArea;
    }

    DDSURFACEDESC ddsd;
    memset(&ddsd, 0, sizeof(DDSURFACEDESC));
    ddsd.dwSize = sizeof(DDSURFACEDESC);
    ddsd.dwFlags = 1;
    ddsd.ddsCaps.dwCaps = 512;

    ddres = this->DirDraw->CreateSurface(
        &ddsd,
        &this->PrimarySurface,
        nullptr);
    if( ddres != DD_OK ){
        return;
    }

    if( this->ScreenMode == 2 ){

        DDBLTFX ddbltfx;
        ddbltfx.dwSize = 100;
        ddbltfx.dwFillColor = 0;

        this->PrimarySurface->Blt(
            nullptr,
            nullptr,
            nullptr,
            DDBLT_COLORFILL|DDBLT_WAIT,
            &ddbltfx);
    }

    if( (this->ColorBits != 8 ||
        this->PrimarySurface->SetPalette(this->DirDrawPal) == DD_OK) &&
        this->PrimarySurface->SetClipper(this->Clipper)    == DD_OK ){

        SetupPrimaryArea:
        if( this->PrimaryArea == nullptr ){

            this->PrimaryArea = new TDrawArea("Primary Surface", 0);

            if( this->ScreenMode == 1 ){

                GetClientRect(*this->Wnd, &wnd_rect);

                if( this->PrimaryArea->Init(this, wnd_rect.right, wnd_rect.bottom, 0, 1) == nullptr ){
                    return;
                }
            }else if( this->PrimaryArea->Init(this, this->ScreenWidth, this->ScreenHeight, 0, 1) == nullptr ){
                return;
            }
        }
        goto SetupBackBufferArea;
    }
}

bool TDrawSystem::HandleSize( HWND *hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    if( this->DrawArea ){
        if( this->DrawType == 1 ||
            this->ScreenMode == 1 ){

            RECT wnd_rect;
            GetClientRect(*this->Wnd, &wnd_rect);

            this->ScreenWidth  = wnd_rect.right;
            this->ScreenHeight = wnd_rect.bottom;
        }
        if( this->PrimaryArea ){
            this->PrimaryArea->SetSize(this->ScreenWidth, this->ScreenHeight, 0);
        }
        this->DrawArea->SetSize(this->ScreenWidth, this->ScreenHeight, 0);
    }

    return true;
}

bool TDrawSystem::HandlePaletteChanged( HWND *hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    if( this->Wnd != hWnd ){
        this->HandleQueryNewPalette(hWnd, msg, wParam, lParam);
    }

    return true;
}

bool TDrawSystem::HandleQueryNewPalette( HWND *hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    if( this->Pal == nullptr || (this->DrawType != 1 && this->ScreenMode != 1) ){
        ReturnFalseModifyPalette:
        this->ModifyPalette(0, 256, this->palette);
        return false;
    }

    HDC hDC = GetDC(*this->Wnd);
    if( this->Pal ){
        SelectPalette(hDC, *this->Pal, 0);
    }

    UINT num_pal_entries = RealizePalette(hDC);
    ReleaseDC(*this->Wnd, hDC);
    if( num_pal_entries &&
        num_pal_entries != GDI_ERROR ){

        InvalidateRect(*this->Wnd, nullptr, false);
        return true;
    }

    goto ReturnFalseModifyPalette;
}

void TDrawSystem::Paint( RECT *rect )
{
    RECT r1, r2;

    if( this->DrawType != 1 &&
        this->PrimarySurface &&
        this->DrawArea &&
        this->DrawArea->DrawSurface ){

        if( this->ScreenMode == 1 ){

            GetClientRect(*this->Wnd, &r1);

            r2.top    = r1.top;
            r2.right  = r1.right;
            r2.left   = r1.left;
            r2.bottom = r1.bottom;

            ClientToScreen(*this->Wnd, (LPPOINT)&r2.left);
            ClientToScreen(*this->Wnd, (LPPOINT)&r2.right);

        }else{

            int rect_screen_w = this->ScreenWidth;
            int rect_screen_h = this->ScreenHeight;

            r1.left   = 0;
            r1.top    = 0;
            r1.right  = rect_screen_w;
            r1.bottom = rect_screen_h;

            r2.left   = 0;
            r2.top    = 0;
            r2.right  = rect_screen_w;
            r2.bottom = rect_screen_h;
        }

        if( rect ){

            int v7 = rect->left;
            if( rect->left < 0 ){
                v7 = 0;
            }
            r1.left = rect->left;

            int v8 = rect->top;
            if( v8 < 0 ){
                v8 = 0;
            }
            r1.top = v8;

            unsigned int v9 = rect->right;
            if( v9 >= this->ScreenWidth ){
                v9 = this->ScreenWidth - 1;
            }

            unsigned int v10 = rect->bottom;
            if( v10 >= this->ScreenHeight ){
                v10 = this->ScreenHeight - 1;
            }

            r2.left += v7;
            int v15 = v9 + r2.left - v7;
            int v16 = v10 + v8 + r2.top - v8;

            r1.right  = v9 + 1;
            r1.bottom = v10 + 1;

            r2.top += v8;
            r2.right  = v15 + 1;
            r2.bottom = v16 + 1;
        }

        this->PrimarySurface->Blt(
            &r2,
            this->DrawArea->DrawSurface,
            &r1,
            DDBLT_WAIT,
            nullptr);
    }
}

int TDrawSystem::GetIsLostErrorNum( int ddrval )
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

int TDrawSystem::GetRestoreErrorNum( int ddrval )
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

int TDrawSystem::GetSetDispModeErrorNum( int ddrval )
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

int TDrawSystem::GetLockErrorNum( int ddrval )
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

int TDrawSystem::GetDCErrorNum( int ddrval )
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

int TDrawSystem::GetBlitErrorNum( int ddrval )
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

int TDrawSystem::GetCreateErrorNum( int ddrval )
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

int TDrawSystem::GetColorKeyErrorNum( int ddrval )
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

void TDrawSystem::SetPalette( HPALETTE *pal_in )
{
    PALETTEENTRY color_table[256];

    if( (this->Pal = pal_in) ){

        GetPaletteEntries(*pal_in, 0, 256, color_table);

    }else{

        for( UINT i = 0; i < 256; i++ ){
            color_table[i].peRed   = 0x00;
            color_table[i].peGreen = 0x00;
            color_table[i].peBlue  = 0x00;
            color_table[i].peFlags = 0x00;
        }
    }

    UINT j = 0;
    color_table[j].peRed   = 0x00;
    color_table[j].peGreen = 0x00;
    color_table[j].peBlue  = 0x00;
    color_table[j].peFlags = 0x00;

    UINT k = 256;
    color_table[k].peRed   = 0xFF;
    color_table[k].peGreen = 0xFF;
    color_table[k].peBlue  = 0xFF;
    color_table[k].peFlags = 0x00;

    this->ModifyPalette(0, 256, color_table);
}

void TDrawSystem::ModifyPalette( int start_entry, int num_entries, PALETTEENTRY *pal_entries )
{
    PalSetRes = -99;

    if( num_entries == 256 ){
        FullPalSets++;
    }

    if( start_entry < (num_entries + start_entry) ){

        int j = start_entry;
        do{
            this->palette[j].peRed   = pal_entries[j - start_entry].peRed;
            this->palette[j].peGreen = pal_entries[j - start_entry].peGreen;
            this->palette[j].peBlue  = pal_entries[j - start_entry].peBlue;
            this->palette[j].peFlags = pal_entries[j - start_entry].peFlags;
        }while( ++j < num_entries );
    }

    if( this->DrawType != 1 &&
        this->DirDrawPal ){

        if( num_entries == 7 ){
            AniPalSets++;
        }

        this->DirDrawPal->SetEntries(
            0,
            start_entry,
            num_entries,
            pal_entries);
    }
}

#endif // DRAW_SYSTEM_CPP
