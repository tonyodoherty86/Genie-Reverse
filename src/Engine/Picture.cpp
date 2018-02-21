
#include "Picture.hpp"

void TPicture::TPicture(char *FileName, int res_id, int UseTrans, void *MapToPal, int ZeroIsTrans)
{
	this->Load(FileName, res_id, UseTrans, MapToPal, ZeroIsTrans);
}

void TPicture::TPicture(int infile, int UseTrans)
{
	rge_read(infile, &this->OwnMemory, 4);
	rge_read(infile, &this->Width, 4);
	rge_read(infile, &this->Height, 4);
	rge_read(infile, &this->Orien, 2);

	if( this->OwnMemory )
		this->OwnMemory = 2;

	if( this->Width > 0 && this->Height > 0 )
	{
		int stride = this->AlignedWidth();

		this->Dib = new BITMAPINFOHEADER;
		this->BitmapInfo = new BITMAPINFO256;
		this->Bits = new char[this->Height * stride];

		rge_read(infile, this->Dib, sizeof(BITMAPINFOHEADER));
		rge_read(infile, this->BitmapInfo, sizeof(BITMAPINFO256));
		rge_read(infile, this->Bits, this->Height * stride);
	}
	else
	{
		this->Dib = NULL;
		this->BitmapInfo = NULL;
		this->Bits = NULL;
	}
	this->TransInfo = NULL;

	if( UseTrans && this->Dib )
	{
		if( this->TransInfo = new TRANSINFO )
		{
			if( this->Dib->biCompression == 3 )
				DibCheckTrans(
					this->Dib,
					this->TransInfo,
					this->Dib->bmiHeader.biSize + this->Dib->bmiHeader.biPlanes);
			else
				DibCheckTrans(
					this->Dib,
					this->TransInfo,
					this->Dib->bmiHeader.biSize + this->Dib->bmiHeader.biClrUsed * 4 + this->Dib.biSize);
		}
		else
		{
			DibFree(this->Dib);
			this->Dib = NULL;
			this->BitmapInfo = NULL;
			this->OwnMemory = 0;
			this->Width = 0;
			this->Height = 0;
			this->Orien = 1;
		}
	}
}

void TPicture::~TPicture()
{
	if( this->OwnMemory )
	{
		if( this->TransInfo )
		{
			if( this->TransInfo->LineInfo && this->TransInfo->AnyTrans )
				delete this->TransInfo->LineInfo;

			delete this->TransInfo;
		}
		if( this->Dib )
		{
			if( this->OwnMemory == 2 )
				delete this->Dib;
			else
				DibFree(this->Dib);
		}
	}
}

void TPicture::Save(int outfile)
{
	rge_write(outfile, &this->OwnMemory, 4);
	rge_write(outfile, &this->Width, 4);
	rge_write(outfile, &this->Height, 4);
	rge_write(outfile, &this->Orien, 2);

	if( this->Width > 0 && this->Height > 0 )
	{
		rge_write(outfile, this->Dib, sizeof(BITMAPINFOHEADER));
		rge_write(outfile, this->BitmapInfo, sizeof(BITMAPINFO256));
		rge_write(outfile, this->Bits, this->Height * this->AlignedWidth());
	}
}

void TPicture::Load(char *FileName, int res_id, int UseTrans, void *MapToPal, int ZeroIsTrans)
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
	v6->TransInfo = 0;
	v6->OwnMemory = 1;
	if ( shape_file_first )
	v6->Dib = DibOpenFile(FileName);
	if ( !v6->Dib && res_id != -1 && RESFILE_Extract_to_File(0x62696E61u, res_id, temp_file_name, &temp_file) )
	{
	fclose(temp_file);
	v6->Dib = DibOpenFile(temp_file_name);
	_unlink(temp_file_name);
	}
	if ( !shape_file_first && !v6->Dib )
	v6->Dib = DibOpenFile(FileName);
	v7 = v6->Dib;
	if ( !v6->Dib )
	{
	v6->Dib = 0;
	v6->BitmapInfo = 0;
	v6->Bits = 0;
	v6->TransInfo = 0;
	goto LABEL_26;
	}
	v6->BitmapInfo = (BITMAPINFO256 *)v7;
	if ( v7->biCompression == 3 )
	v8 = (int)&v7->biPlanes + v7->biSize;
	else
	v8 = (int)v7 + 4 * v7->biClrUsed + v7->biSize;
	v6->Bits = (char *)v8;
	v6->Width = v7->biWidth;
	v9 = v7->biHeight;
	v6->Height = v9;
	if ( v9 >= 0 )
	{
	v6->Orien = -1;
	}
	else
	{
	v6->Orien = 1;
	v6->Height = -v9;
	}
	if ( MapToPal )
	DibMapToPalette(v7, MapToPal, UseTrans, ZeroIsTrans);
	if ( UseTrans )
	{
	v10 = (TRANSINFO *)malloc(0x18u);
	v6->TransInfo = v10;
	if ( v10 )
	{
		v11 = (BITMAPINFO256 *)v6->Dib;
		if ( v11->bmiHeader.biCompression == 3 )
		DibCheckTrans(v11, v10, (char *)&v11->bmiHeader.biPlanes + v11->bmiHeader.biSize);
		else
		DibCheckTrans(v11, v10, (char *)v11 + 4 * v11->bmiHeader.biClrUsed + v11->bmiHeader.biSize);
		return;
	}
	DibFree(v6->Dib);
	v6->Dib = 0;
	v6->BitmapInfo = 0;
LABEL_26:
	v6->OwnMemory = 0;
	v6->Width = 0;
	v6->Height = 0;
	v6->Orien = 1;
	}
}

void TPicture::Init(BITMAPINFO256 *FromInfo, char *FromBits, TRANSINFO *FromTrans)
{
	this->Bits = FromBits;
	this->Dib = (BITMAPINFOHEADER *)FromInfo;
	this->BitmapInfo = FromInfo;
	this->TransInfo = FromTrans;
	this->OwnMemory = 0;
	this->Width = FromInfo->bmiHeader.biWidth;
	int v4 = FromInfo->bmiHeader.biHeight;
	this->Height = v4;

	if ( v4 >= 0 )
	{
		this->Orien = -1;
	}
	else
	{
		this->Orien = 1;
		this->Height = -v4;
	}
}

char TPicture::AlignedWidth()
{
	return (LOBYTE(this->Width) + 3) & 0xFC;
}

void TPicture::Draw(TDrawArea *DrawArea, int DestX, int DestY, int Mirror, int Flip)
{
	if ( this->TransInfo )
	{
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
	}
	else
	{
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

int TPicture::Tile(TDrawArea *DrawArea, int DestX, int DestY, int DestWid, int DestHgt, int BlockWid, int BlockHgt, int SrcX, int SrcY, int SrcWid, int SrcHgt)
{
	int result = TileDibBlt(
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
		this->TransInfo != 0,
		0,
		0);

	return result;
}

char TPicture::GetPixel(int x, int y, int Mirror, int Flip)
{
	TPicture *v5; // esi@1
	signed int v6; // eax@1
	int v7; // eax@9
	char result; // al@9
	int v9; // eax@10
	int v10; // eax@12
	int v11; // eax@13

	v5 = this;
	LOBYTE(v6) = this->Orien;
	if ( Flip )
	v6 = (_BYTE)v6 != 1 ? 1 : -1;
	if ( x <= 0 || x >= this->Width || y < 0 || y >= this->Height )
	{
	result = 0;
	}
	else if ( Mirror )
	{
	if ( (_BYTE)v6 == 1 )
	{
		LOBYTE(v7) = TPicture::AlignedWidth(this);
		result = *(&v5->Bits[v5->Width - x - 1] + y * v7);
	}
	else
	{
		LOBYTE(v9) = TPicture::AlignedWidth(this);
		result = *(&v5->Bits[v5->Width - x - 1] + (v5->Height - y - 1) * v9);
	}
	}
	else if ( (_BYTE)v6 == 1 )
	{
	LOBYTE(v10) = TPicture::AlignedWidth(this);
	result = *(&v5->Bits[y * v10] + x);
	}
	else
	{
	LOBYTE(v11) = TPicture::AlignedWidth(this);
	result = *(&v5->Bits[(v5->Height - y - 1) * v11] + x);
	}
	return result;
}
