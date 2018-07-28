
/**
 * @file    Engine\RGE\Picture.cpp
 * @author  Yvan Burrie
 * @date    2018/07/04
 * @version 1.0
 */

TPicture::TPicture(
    char *FileName,
    int res_id,
    bool UseTrans,
    HPALETTE *MapToPal,
    bool ZeroIsTrans)
{
    this->Load(
        FileName,
        res_id,
        UseTrans,
        MapToPal,
        ZeroIsTrans);
}

TPicture::TPicture(
    int infile,
    bool UseTrans)
{
    rge_read(infile, &this->OwnMemory, 4);
    rge_read(infile, &this->Width, 4);
    rge_read(infile, &this->Height, 4);
    rge_read(infile, &this->Orien, 2);

    if( this->OwnMemory ){
        this->OwnMemory = 2;
    }
    if( this->Width  > 0 &&
        this->Height > 0 ){

        int AlignedWidth = this->AlignedWidth();

        this->Dib        = new BITMAPINFOHEADER;
        this->BitmapInfo = new BITMAPINFO256;
        this->Bits       = new char[this->Height * AlignedWidth];

        rge_read(infile, this->Dib, sizeof(BITMAPINFOHEADER));
        rge_read(infile, this->BitmapInfo, sizeof(BITMAPINFO256));
        rge_read(infile, this->Bits, this->Height * AlignedWidth);
    }else{
        this->Dib        = nullptr;
        this->BitmapInfo = nullptr;
        this->Bits       = nullptr;
    }
    this->TransInfo = nullptr;

    if( UseTrans && this->Dib ){
        if( this->TransInfo = new TRANSINFO ){
            if( this->Dib->biCompression == 3 ){
                DibCheckTrans(
                    this->BitmapInfo,
                    this->TransInfo,
                    (char *)this->BitmapInfo->bmiHeader.biSize + this->BitmapInfo->bmiHeader.biPlanes);
            }else{
                DibCheckTrans(
                    this->BitmapInfo,
                    this->TransInfo,
                    (char *)this->BitmapInfo->bmiHeader.biSize + this->BitmapInfo->bmiHeader.biClrUsed * 4 + this->BitmapInfo->bmiHeader.biSize);
            }
        }else{
            DibFree(this->Dib);

            this->Dib        = nullptr;
            this->BitmapInfo = nullptr;
            this->OwnMemory  = 0;
            this->Width      = 0;
            this->Height     = 0;
            this->Orien      = 1;
        }
    }
}

TPicture::~TPicture()
{
    if( this->OwnMemory != 0 ){
        if( this->TransInfo ){
            if( this->TransInfo->LineInfo &&
                this->TransInfo->AnyTrans ){
                delete this->TransInfo->LineInfo;
            }
            delete this->TransInfo;
        }
        if( this->Dib ){
            if( this->OwnMemory == 2 ){
                delete this->Dib;
            }else{
                DibFree(this->Dib);
            }
        }
    }
}

void TPicture::Save(
    int outfile)
{
    rge_write(outfile, &this->OwnMemory, 4);
    rge_write(outfile, &this->Width, 4);
    rge_write(outfile, &this->Height, 4);
    rge_write(outfile, &this->Orien, 2);

    if( this->Width  > 0 &&
        this->Height > 0 ){

        rge_write(outfile, this->Dib, sizeof(BITMAPINFOHEADER));
        rge_write(outfile, this->BitmapInfo, sizeof(BITMAPINFO256));
        rge_write(outfile, this->Bits, this->Height * this->AlignedWidth());
    }
}

void TPicture::Load(
    char *FileName,
    int res_id,
    bool UseTrans,
    HPALETTE *MapToPal,
    bool ZeroIsTrans)
{
    TPicture *v6; // esi@1
    tagBITMAPINFOHEADER *v7; // eax@10
    int v8; // ecx@12
    int v9; // ecx@14
    TRANSINFO *v10; // eax@20
    BITMAPINFO256 *v11; // esi@21
    _iobuf *temp_file; // [sp+Ch] [bp-108h]@5
    char temp_file_name[260]; // [sp+10h] [bp-104h]@5

    v6 = this;
    debug_timeGetTime();
    this->TransInfo = 0;
    this->OwnMemory = 1;
    if( shape_file_first )
    this->Dib = DibOpenFile(FileName);
    if( !this->Dib && res_id != -1 && RESFILE_Extract_to_File("anib", res_id, temp_file_name, &temp_file) )
    {
        fclose(temp_file);
        this->Dib = DibOpenFile(temp_file_name);
        unlink(temp_file_name);
    }
    if( !shape_file_first && !this->Dib )
        this->Dib = DibOpenFile(FileName);
    v7 = this->Dib;
    if( !this->Dib )
    {
        this->Dib = 0;
        this->BitmapInfo = 0;
        this->Bits = 0;
        this->TransInfo = 0;
        goto LABEL_26;
    }
    this->BitmapInfo = (BITMAPINFO256 *)v7;
    if( v7->biCompression == 3 )
        v8 = (int)&v7->biPlanes + v7->biSize;
    else
        v8 = (int)v7 + 4 * v7->biClrUsed + v7->biSize;
    this->Bits = (char *)v8;
    this->Width = v7->biWidth;
    v9 = v7->biHeight;
    this->Height = v9;
    if( v9 >= 0 )
    {
        this->Orien = -1;
    }
    else
    {
        this->Orien = 1;
        this->Height = -v9;
    }
    if( MapToPal )
        DibMapToPalette(v7, MapToPal, UseTrans, ZeroIsTrans);
    if( UseTrans )
    {
        if( this->TransInfo = new TRANSINFO ){
            v11 = (BITMAPINFO256 *)this->Dib;
            if( v11->bmiHeader.biCompression == 3 )
                DibCheckTrans(v11, this->TransInfo, (char *)&v11->bmiHeader.biPlanes + v11->bmiHeader.biSize);
            else
                DibCheckTrans(v11, this->TransInfo, (char *)v11 + 4 * v11->bmiHeader.biClrUsed + v11->bmiHeader.biSize);
            return;
        }
        DibFree(this->Dib);
        this->Dib = 0;
        this->BitmapInfo = 0;
        LABEL_26:
        this->OwnMemory = 0;
        this->Width = 0;
        this->Height = 0;
        this->Orien = 1;
    }
}

void TPicture::Init(
    BITMAPINFO256 *FromInfo,
    char *FromBits,
    TRANSINFO *FromTrans)
{
    this->Bits       = FromBits;
    this->Dib        = (BITMAPINFOHEADER *)FromInfo;
    this->BitmapInfo = FromInfo;
    this->TransInfo  = FromTrans;
    this->OwnMemory  = 0;
    this->Width      = FromInfo->bmiHeader.biWidth;
    this->Height     = FromInfo->bmiHeader.biHeight;

    if( this->Height >= 0 ){
        this->Orien = -1;
    }else{
        this->Orien = 1;
        this->Height *= -1;
    }
}

int TPicture::AlignedWidth()
{
    return (this->Width + 3) & 0xFC;
}

void TPicture::Draw(
    TDrawArea *DrawArea,
    int DestX, int DestY,
    bool Mirror,
    bool Flip)
{
    if( this->TransInfo ){
        TransDibBlt(
            DrawArea->BitmapInfo,
            DrawArea->Bits,
            &DrawArea->ClipRect,
            DestX,
            DestY,
            this->Width,
            this->Height,
            this->BitmapInfo,
            this->Bits,
            this->TransInfo,
            0,
            0,
            this->Width,
            this->Height,
            1,
            Mirror,
            Flip,
            0);
    }else{
        DibBlt(
            DrawArea->BitmapInfo,
            DrawArea->Bits,
            &DrawArea->ClipRect,
            DestX,
            DestY,
            this->Width,
            this->Height,
            this->BitmapInfo,
            this->Bits,
            0,
            0,
            this->Width,
            this->Height,
            1,
            Mirror,
            Flip);
    }
}

int TPicture::Tile(
    TDrawArea *DrawArea,
    int DestX,    int DestY,
    int DestWid,  int DestHgt,
    int BlockWid, int BlockHgt,
    int SrcX,     int SrcY,
    int SrcWid,   int SrcHgt)
{
    return TileDibBlt(
        DrawArea->BitmapInfo,
        DrawArea->Bits,
        &DrawArea->ClipRect,
        DestX,
        DestY,
        DestWid,
        DestHgt,
        BlockWid,
        BlockHgt,
        this->BitmapInfo,
        this->Bits,
        this->TransInfo,
        SrcX,
        SrcY,
        SrcWid,
        SrcHgt,
        this->TransInfo != nullptr,
        false,
        false);
}

char TPicture::GetPixel(
    int x, int y,
    bool Mirror,
    bool Flip)
{
    int AlignedWidth = this->AlignedWidth();

    int v6 = this->Orien;
    if( Flip ){
        v6 = v6 != 1 ? 1 : -1;
    }
    if( x <= 0 || x >= this->Width || y < 0 || y >= this->Height ){
        return 0;
    }else if( Mirror ){
        if( v6 == 1 ){
            return *(&this->Bits[this->Width - x - 1] + y * AlignedWidth);
        }else{
            return *(&this->Bits[this->Width - x - 1] + (this->Height - y - 1) * AlignedWidth);
        }
    }else if( v6 == 1 ){
        return *(&this->Bits[y * AlignedWidth] + x);
    }else{
        return *(&this->Bits[(this->Height - y - 1) * AlignedWidth] + x);
    }
}
