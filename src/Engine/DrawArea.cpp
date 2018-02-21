
int err;
int ddrval;

void TDrawArea::TDrawArea(const char *SurfaceName, int ForceSystemMem)
{
	this->SystemMemOnly = ForceSystemMem;

	memset(&this->SurfaceDesc, 0, sizeof(DDSURFACEDESC));

	this->BitmapInfo = new BITMAPINFO256;

	size_t nameLen = strlen(SurfaceName);
	if( nameLen > 0 )
	{
		char *newName = new char[++nameLen];
		this->Name = newName;
		strcpy(newName, SurfaceName);
	}
	else
	{
		this->Name = NULL;
	}
}

void TDrawArea::~TDrawArea()
{
	if( this->Node )
	{
		if( this->DrawSystem && this->Node == this->DrawSystem->DrawAreaList )
			this->DrawSystem->DrawAreaList = this->Node->NextNode;

		if( this->Node->PrevNode )
			this->Node->PrevNode->NextNode = this->Node->NextNode;

		if( this->Node->NextNode )
			this->Node->NextNode->PrevNode = this->Node->PrevNode;

		delete this->Node;
	}
	if( this->DrawSystem && this->DrawSystem->DrawType == 1 )
	{
		if( this->DrawDc )
		{
			if( this->Bitmap )
			{
				if( this->OldBitmap )
                {
                    this->DrawDc->SelectObject(this->OldBitmap);
                }
				this->Bitmap->DeleteObject();
			}
			this->DrawDc->DeleteDC();
		}
	}
	else
	{
		if( this->DrawSurface && !this->IsPrimarySurface )
		{
			this->DrawSurface->Release((IUnknown *)this->DrawSurface);
			this->DrawSurface = 0;
		}
	}
	if( this->BitmapInfo )
		delete this->BitmapInfo;

	if( this->DisplayOffsets )
		delete this->DisplayOffsets;

	if( this->FloatOffsets )
		delete this->FloatOffsets;

	if( this->SpanList )
		delete this->SpanList;

	if( this->Name )
		delete this->Name;
}

DrawAreaNode *TDrawArea::Init(TDrawSystem *draw_system_in, int wid_in, int hgt_in, int Extend, int isPrimary_in)
{
    DrawAreaNode *v9;
	DrawAreaNode *i;

	this->DrawSystem = draw_system_in;
	this->IsPrimarySurface = isPrimary_in;

	if( !draw_system_in )
		goto LABEL_14;

	this->Wnd = draw_system_in->Wnd;
	if( this->Node == NULL )
	{
		this->Node = new DrawAreaNode;
		if( this->Node == NULL )
			return this->Node;
		this->Node->DrawArea = this;
		this->Node->PrevNode = 0;
		this->Node->NextNode = 0;
		if( v9 = this->DrawSystem->DrawAreaList )
		{
			for ( i = v9->NextNode; i; i = i->NextNode )
				v9 = i;
			v9->NextNode = this->Node;
			this->Node->PrevNode = v9;
		}
		else
		{
			this->DrawSystem->DrawAreaList = this->Node;
		}
	}
	if( this->DrawSystem->DrawType == 1 )
	{
		return NULL;
	}
	else
	{
        LABEL_14:
		this->SetSize(wid_in, hgt_in, Extend);
		return (DrawAreaNode *)1;
	}
}

char TDrawArea::CheckSurface()
{
	TDrawArea *v1; // esi@1
	IDirectDrawSurface *v2; // eax@3
	char result; // al@4
	int v4; // eax@5
	TDrawSystem *v5; // ecx@6
	TDrawSystem *v6; // eax@6
	int v7; // eax@11
	int v8; // edi@11
	int v9; // ST10_4@14
	int v10; // ST0C_4@14
	TDrawSystem *v11; // ecx@16
	IUnknownVtbl *v12; // edx@17
	IDirectDrawSurface *v13; // ST00_4@17
	DDSURFACEDESC ddsd; // [sp+8h] [bp-D0h]@6
	DDBLTFX ddbltfx; // [sp+74h] [bp-64h]@17

	v1 = this;
	if( !this->DrawSystem || this->DrawSystem->DrawType != 2 )
		goto LABEL_21;
	v2 = this->DrawSurface;
	if( !v2 )
		return 3;
	v4 = ((int (__stdcall *)(IDirectDrawSurface *))v2->vfptr[8].QueryInterface)(this->DrawSurface);
	if( v4 )
	{
		v5 = this->DrawSystem;
		TDrawSystem::GetIsLostErrorNum(v4);
		memset(&ddsd, 0, 0x6Cu);
		v6 = this->DrawSystem;
		ddsd.dwSize = 108;
		if( ((int (__stdcall *)(IDirectDraw *, DDSURFACEDESC *))v6->DirDraw->vfptr[4].QueryInterface)(v6->DirDraw, &ddsd)
			|| ddsd.dwWidth == this->DrawSystem->ScreenWidth
			&& ddsd.dwHeight == this->DrawSystem->ScreenHeight
			&& ddsd.ddpfPixelFormat.dwRGBBitCount == 8 )
		{
			v7 = ((int (__stdcall *)(IDirectDrawSurface *))this->DrawSurface->vfptr[9].QueryInterface)(this->DrawSurface);
			v8 = v7;
			if( v7 )
			{
				if( (v7 == -2005532085 || v7 == -2147024882)
					&& (this->DrawSurface->vfptr->Release((IUnknown *)this->DrawSurface),
							this->Height,
							this->Width,
							this->DrawSurface = 0,
							this->SetSize(this->Width, this->Height, 0),
							this->DrawSurface) )
				{
					result = 2;
				}
				else
				{
					v11 = this->DrawSystem;
					TDrawSystem::GetRestoreErrorNum(v8);
					result = 3;
				}
			}
			else
			{
				v12 = this->DrawSurface->vfptr;
				v13 = this->DrawSurface;
				ddbltfx.dwSize = 100;
				ddbltfx.dwFillColor = 0;
				((void (__stdcall *)(IDirectDrawSurface *, _DWORD, _DWORD, _DWORD, signed int, DDBLTFX *))v12[1].Release)(
					v13,
					0,
					0,
					0,
					16778240,
					&ddbltfx);
				this->Restored = 1;
				result = 2;
			}
		}
		else
		{
			result = 1;
		}
	}
	else
	{
LABEL_21:
		result = 0;
	}
	return result;
}

char *TDrawArea::Lock(char *caller_name, int wait)
{
	if( this->DrawSystem && this->DrawSystem->DrawType == 1 )
		return this->Bits;

	if( !this->DrawSurface )
		return 0;

	if( !this->Bits )
	{
		if( this->DrawDc )
			return 0;

		if( ((int (__stdcall *)(IDirectDrawSurface *, _DWORD, int, _DWORD, _DWORD))this->DrawSurface->vfptr[8].AddRef)(
			this->DrawSurface,
			0,
			(int)&this->SurfaceDesc,
			wait != 0,
			0) )
		{
			return 0;
		}
		this->Bits = (char *)this->SurfaceDesc.lpSurface;

		this->SetInfo();

		if( this->Bits != this->LastBits )
			this->SetAccessOffsets();

		return this->Bits;
	}
	return this->Bits;
}

void TDrawArea::Unlock(char *caller_name)
{
	if( !this->DrawSystem || this->DrawSystem->DrawType != 1 && this->DrawSurface && this->Bits )
	{
		((void (__stdcall *)(IDirectDrawSurface *, char *))this->DrawSurface->vfptr[10].Release)(this->DrawSurface, this->Bits);

		this->Bits = 0;
	}
}

void * TDrawArea::GetDc(char *caller_name)
{
	void *result;
	void **v4;

	if( this->DrawSystem && this->DrawSystem->DrawType == 1 )
	{
		result = this->DrawDc;
	}
	else
	{
		if( this->DrawSurface )
		{
			result = this->DrawDc;
			v4 = &this->DrawDc;
			if( !result )
			{
				if( this->Bits )
				{
					result = 0;
				}
				else
				{
					((void (__stdcall *)(IDirectDrawSurface *, void **))this->DrawSurface->vfptr[5].Release)(this->DrawSurface, &this->DrawDc);
					result = *v4;
				}
			}
		}
		else
		{
			result = 0;
		}
	}
	return result;
}

void TDrawArea::ReleaseDc(char *caller_name)
{
	if( this->DrawSystem == NULL ||
        this->DrawSystem->DrawType != 1 &&
        this->DrawSurface &&
        this->DrawDc )
	{
	    this->DrawSurface->ReleaseDC(this->DrawDc);

		this->DrawDc = 0;
	}
}

void TDrawArea::SetSize(int wid_in, int hgt_in, int ExtendSurface)
{
	TDrawArea *v4; // esi@1
	TDrawSystem *v5; // eax@1
	int v6; // ebx@5
	signed int v7; // ebp@5
	int v8; // ebx@14
	BITMAPINFO256 *v9; // edx@16
	int v10; // eax@19
	IDirectDrawSurface *v11; // eax@20
	char *v12; // edi@20
	TDrawSystem *v13; // eax@22
	int v14; // ecx@24
	unsigned int v15; // edx@26
	int *v16; // ST10_4@27
	int v17; // edx@27
	int v18; // eax@27
	int *v19; // edi@28
	int v20; // eax@28
	TDrawSystem *v21; // ecx@29
	TSpan_List_Manager *v22; // edi@34
	TSpan_List_Manager *v23; // eax@36
	int v24; // edi@36
	TSpan_List_Manager *v25; // eax@37
	int v26; // ebx@40
	DDSURFACEDESC ddsd; // [sp+14h] [bp-DCh]@22
	DDBLTFX ddbltfx; // [sp+80h] [bp-70h]@28
	int v29; // [sp+ECh] [bp-4h]@36

	v4 = this;
	v5 = this->DrawSystem;
	if( !this->DrawSystem || v5->DrawType == 1 || !v5 || !v5->DirDraw )
	{
		v7 = hgt_in;
LABEL_33:
		v6 = wid_in;
		goto LABEL_34;
	}
	v6 = wid_in;
	v7 = hgt_in;
	if( wid_in && hgt_in && (wid_in != this->Width || hgt_in != this->Height || !this->DrawSurface) )
	{
		if( wid_in < 1 )
			wid_in = 1;
		if( hgt_in < 1 )
			v7 = 1;
		v8 = v7 + 10;
		if( !ExtendSurface )
			v8 = v7;
		v9 = this->BitmapInfo;
		this->ExtendedLines = ExtendSurface;
		v9->bmiHeader.biWidth = wid_in;
		if( this->Orien == 1 )
			this->BitmapInfo->bmiHeader.biHeight = -v8;
		else
			this->BitmapInfo->bmiHeader.biHeight = v8;
		this->Width = wid_in;
		v10 = this->IsPrimarySurface;
		this->Height = v7;
		if( v10 )
		{
			this->DrawSurface = this->DrawSystem->PrimarySurface;
		}
		else
		{
			v11 = this->DrawSurface;
			v12 = (char *)&this->DrawSurface;
			if( v11 )
			{
				v11->vfptr->Release((IUnknown *)this->DrawSurface);
				*(_DWORD *)v12 = 0;
				memset(&v4->SurfaceDesc, 0, 0x6Cu);
				v4->Pitch = 0;
				v4->UsingVidMem = 0;
			}
			memset(&ddsd, 0, 0x6Cu);
			v13 = v4->DrawSystem;
			ddsd.dwSize = 108;
			ddsd.dwFlags = 7;
			if( v13->Flags & 1 || ExtendSurface || (v14 = v4->SystemMemOnly, ddsd.ddsCaps.dwCaps = 64, v14) )
				ddsd.ddsCaps.dwCaps = 2112;
			v15 = v4->Width;
			ddsd.dwHeight = v8;
			ddsd.dwWidth = v15;
			if( !((int (__stdcall *)(IDirectDraw *, DDSURFACEDESC *, int, _DWORD))v13->DirDraw->vfptr[2].QueryInterface)(
							v13->DirDraw,
							&ddsd,
							(int)&v4->DrawSurface,
							0) )
			{
				v16 = *(int **)v12;
				v17 = **(_DWORD **)v12;
				v4->SurfaceDesc.dwSize = 108;
				v18 = (*(int (__stdcall **)(int *, int))(v17 + 88))(v16, (int)&v4->SurfaceDesc);
				if( v18 )
				{
					v21 = v4->DrawSystem;
					TDrawSystem::GetCreateErrorNum(v18);
				}
				else
				{
					TDrawArea::SetInfo(v4);
					TDrawArea::SetAccessOffsets(v4);
					v19 = *(int **)v12;
					v20 = *v19;
					ddbltfx.dwSize = 100;
					ddbltfx.dwFillColor = 0;
					(*(void (__stdcall **)(int *, _DWORD, _DWORD, _DWORD, signed int, DDBLTFX *))(v20 + 20))(
						v19,
						0,
						0,
						0,
						16778240,
						&ddbltfx);
				}
			}
		}
		TDrawArea::SetClipRect(v4, 0);
		TDrawArea::Clear(v4, 0, 0);
		goto LABEL_33;
	}
LABEL_34:
	v22 = v4->SpanList;
	if( v22 )
	{
		TSpan_List_Manager::~TSpan_List_Manager(v4->SpanList);
		operator delete(v22);
	}
	v23 = (TSpan_List_Manager *)operator new(0x68u);
	v24 = 0;
	v29 = 0;
	if( v23 )
		TSpan_List_Manager::TSpan_List_Manager(v23, v6, v7);
	else
		v25 = 0;
	v29 = -1;
	v4->SpanList = v25;
	if( v7 > 0 )
	{
		v26 = v6 - 1;
		do
			TSpan_List_Manager::AddSpan(v4->SpanList, 0, v26, v24++);
		while ( v24 < v7 );
	}
	v4->CurSpanList = v4->SpanList;
}

void TDrawArea::Clear(RECT *rect, int color)
{
	char *v13;
	int v14;
	int v15;

	RECT dest;

	DDBLTFX ddbltfx;

	if( DDSys_CanColorFill )
	{
		if( this->DrawSystem && this->DrawSystem->DrawType == 1 )
		{
			if( this->Bits )
			{
				if( rect )
				{
					int v4 = rect->left;
					int v5 = rect->top;
					int v6 = rect->right;
					int v7 = rect->bottom;

					if( rect->left >= 0 )
					{
						if( v4 >= this->Width )
							v4 = this->Width - 1;
					}
					else
					{
						v4 = 0;
					}
					if( v5 >= 0 )
					{
						if( v5 >= this->Height )
							v5 = this->Height - 1;
					}
					else
					{
						v5 = 0;
					}
					if( v6 >= 0 )
					{
						if( v6 >= this->Width )
							v6 = this->Width - 1;
					}
					else
					{
						v6 = 0;
					}
					if( v7 >= 0 )
					{
						if( v7 >= this->Height )
							v7 = this->Height - 1;
					}
					else
					{
						v7 = 0;
					}
					if( v6 > v4 && v7 > v5 )
					{
						int wid = v6 - v4 + 1;
						if( this->Orien == 1 )
						{
							v13 = &this->Bits[v4] + this->Pitch * v5;
							v14 = this->Pitch;
						}
						else
						{
							v15 = this->Pitch;
							v13 = &this->Bits[v4] + v15 * (this->Height - v5 - 1);
							v14 = -v15;
						}
						if( v5 <= v7 )
						{
							int v16 = v7 - v5 + 1;
							do
							{
								memset(v13, color, wid);
								v13 += v14;
							}
							while ( --v16 );
						}
					}
				}
				else
				{
					memset(this->Bits, color, this->Pitch * this->Height);
				}
			}
		}
		else
		{
			if( this->DrawSurface )
			{
				ddbltfx.dwSize = 100;
				ddbltfx.dwFillColor = color;

				if( rect )
				{
					dest.left = rect->left;
					dest.top = rect->top;
					dest.right = rect->right + 1;
					dest.bottom = rect->bottom + 1;

					((void (__stdcall *)(IDirectDrawSurface *, RECT *, _DWORD, _DWORD, signed int, DDBLTFX *))this->DrawSurface->vfptr[1].Release)(
						this->DrawSurface,
						&dest,
						0,
						0,
						0x01000400,
						&ddbltfx);
				}
				else
				{
					((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->DrawSurface->vfptr[1].Release)(
						this->DrawSurface,
						0,
						0,
						0,
						0x01000400,
						&ddbltfx);
				}
			}
		}
	}
	else
	{
		this->PtrClear(rect, color);
	}
}

void TDrawArea::PtrClear(RECT *rect, int color)
{
	void **SrcP;

	int nWidth;
	int nLines;

	int v4;
	int v5;
	int v6;
	int v7;
	int x1;
	int y1;

	if( rect )
	{
		v4 = rect->left;
		v5 = rect->top;
		v6 = rect->right;
		v7 = rect->bottom;
		x1 = rect->left;
		y1 = rect->top;
	}
	else
	{
		v6 = this->Width;
		v7 = this->Height;
		v4 = 0;
		v5 = 0;
		x1 = 0;
		y1 = 0;
	}
	if( v6 >= 0 && v4 <= v6 && v4 < this->Width && v7 >= 0 && v5 <= v7 && v5 < this->Height )
	{
		if( v4 < 0 )
		{
			v4 = 0;
			x1 = 0;
		}
		if( v6 >= this->Width )
			v6 = this->Width - 1;

		if( v5 < 0 )
		{
			v5 = 0;
			y1 = 0;
		}
		if( v7 >= this->Height )
			v7 = this->Height - 1;

		nLines = v7 - v5 + 1;
		nWidth = v6 - v4 + 1;

		if( !this->DrawSystem || this->DrawSystem->DrawType != 2 || this->Lock(aPtrclear, 1) )
		{
			void **v10 = this->CurDisplayOffsets;
			SrcP = this->CurDisplayOffsets;
			LOBYTE(v10) = color;
			BYTE1(v10) = color;
			int v11 = (_DWORD)v10 << 0x10;
			LOBYTE(v11) = color;
			BYTE1(v11) = color;
			do
			{
				char *v12 = (char *)SrcP[y1++] + x1;
				int v13 = ((_BYTE)nWidth - (_BYTE)v12 - (_BYTE)nWidth) & 0x03;
				int v14 = nWidth - v13;
				if( nWidth > v13 )
				{
					memset(v12, v11, v13);
					char *v15 = &v12[v13];
					v14 &= 0x03;
					unsigned int v16 = (unsigned int)(nWidth - v13) >> 2;
					memset32(v15, v11, v16);
					v12 = &v15[4 * v16];
					v13 = 0;
				}
				memset(v12, color, v14 + v13);
			}
			while ( --nLines );

			if( this->DrawSystem && this->DrawSystem->DrawType == 2 )
				this->Unlock(aPtrclear);
		}
	}
}

void TDrawArea::SetAccessOffsets()
{
	TDrawArea *v1; // esi@1
	size_t v2; // edi@1
	void **v3; // eax@4
	int v4; // edx@7
	int v5; // eax@7
	int v6; // edx@7
	int v7; // ecx@8
	int i; // ecx@13

	v1 = this;
	v2 = 4 * this->Height;
	if( v2 != this->DisplayOffsetsSz )
	{
		if( this->DisplayOffsets )
			free(this->DisplayOffsets);
		v3 = (void **)malloc(v2);
		v1->DisplayOffsets = v3;
		v1->DisplayOffsetsSz = v2;
		v1->CurDisplayOffsets = v3;
	}
	if( v1->Orien == 1 || v1->ExtendedLines )
	{
		v7 = v1->ExtendedLines;
		if( v7 )
			v5 = (int)&v1->Bits[5 * v1->Pitch];
		else
			v5 = (int)v1->Bits;
		v6 = v1->Pitch;
		if( v7 )
			v6 = v1->Width;
	}
	else
	{
		v4 = v1->Pitch;
		v5 = (int)&v1->Bits[v4 * (v1->Height - 1)];
		v6 = -v4;
	}
	for ( i = 0; i < v1->Height; ++i )
	{
		v1->DisplayOffsets[i] = (void *)v5;
		v5 += v6;
	}
	if( v1->FloatOffsets )
		TDrawArea::SetFloatOffsets(v1, v1->Float_X_Delta, v1->Float_Y_Delta);
	v1->LastBits = v1->Bits;
}

void TDrawArea::SetFloatOffsets(int X_Delta, int Y_Delta)
{
	TDrawArea *v3; // esi@1
	size_t v4; // ebx@1
	int v5; // edx@9
	int v6; // eax@9
	int v7; // ecx@10
	int v8; // ecx@10
	void **v9; // edx@13

	v3 = this;
	v4 = 4 * this->Height;
	if( v4 && this->ExtendedLines && X_Delta >= 0 && Y_Delta >= 0 )
	{
		if( v4 != this->FloatOffsetsSz )
		{
			if( this->FloatOffsets )
				free(this->FloatOffsets);
			v3->FloatOffsets = (void **)malloc(v4);
			v3->FloatOffsetsSz = v4;
		}
		v5 = 0;
		v6 = Y_Delta;
		if( v3->Height > 0 )
		{
			do
			{
				v7 = (int)v3->DisplayOffsets[v6++] + X_Delta;
				v3->FloatOffsets[v5] = (void *)v7;
				v8 = v3->Height;
				if( v6 >= v8 )
					v6 = 0;
				++v5;
			}
			while ( v5 < v8 );
		}
		v9 = v3->FloatOffsets;
		v3->Float_X_Delta = X_Delta;
		v3->Float_Y_Delta = Y_Delta;
		v3->CurDisplayOffsets = v9;
	}
}

void TDrawArea::SetInfo()
{
	this->Pitch = this->SurfaceDesc.lPitch;

	this->BitmapInfo->bmiHeader.biWidth = this->Pitch;

	unsigned int v3 = this->SurfaceDesc.ddsCaps.dwCaps;

	if( BYTE1(v3) & 8 )
		this->UsingVidMem = 0;
	else
		this->UsingVidMem = 1;
}

int TDrawArea::AlignedWidth()
{
	return this->Pitch;
}

void TDrawArea::SetClipRect(RECT *rect)
{
	int v2; // eax@2
	int v3; // edx@4
	int v4; // edx@6
	int v5; // eax@8
	int v6; // edx@10
	int v7; // eax@12
	int v8; // edx@14
	int v9; // eax@16
	int v10; // eax@18
	int v11; // edx@18
	int v12; // eax@20
	int v13; // edx@20
	int v14; // edx@22
	int v15; // eax@22

	if( rect )
	{
		this->ClipRect = *rect;
		v2 = this->ClipRect.left;
		if( v2 >= 0 )
		{
			v3 = this->Width - 1;
			if( v2 > v3 )
				this->ClipRect.left = v3;
		}
		else
		{
			this->ClipRect.left = 0;
		}
		v4 = this->ClipRect.right;
		if( v4 >= 0 )
		{
			v5 = this->Width - 1;
			if( v4 > v5 )
				this->ClipRect.right = v5;
		}
		else
		{
			this->ClipRect.right = 0;
		}
		v6 = this->ClipRect.top;
		if( v6 >= 0 )
		{
			v7 = this->Height - 1;
			if( v6 > v7 )
				this->ClipRect.top = v7;
		}
		else
		{
			this->ClipRect.top = 0;
		}
		v8 = this->ClipRect.bottom;
		if( v8 >= 0 )
		{
			v9 = this->Height - 1;
			if( v8 > v9 )
				this->ClipRect.bottom = v9;
		}
		else
		{
			this->ClipRect.bottom = 0;
		}
		v10 = this->ClipRect.right;
		v11 = this->ClipRect.left;
		if( v10 < v11 )
		{
			this->ClipRect.right = v11;
			this->ClipRect.left = v10;
		}
		v12 = this->ClipRect.bottom;
		v13 = this->ClipRect.top;
		if( v12 < v13 )
		{
			this->ClipRect.bottom = v13;
			this->ClipRect.top = v12;
		}
	}
	else
	{
		v14 = this->Width - 1;
		v15 = this->Height - 1;
		this->ClipRect.left = 0;
		this->ClipRect.top = 0;
		this->ClipRect.right = v14;
		this->ClipRect.bottom = v15;
	}
	TDrawArea::SetClipRect(this, this->ClipRect.left, this->ClipRect.top, this->ClipRect.right, this->ClipRect.bottom);
}

void TDrawArea::SetClipRect(int x1, int y1, int x2, int y2)
{
	TDrawArea *v5; // esi@1
	TSpan_List_Manager *v6; // edi@1
	TSpan_List_Manager *v7; // eax@7
	TSpan_List_Manager *v8; // eax@8
	int i; // edi@11

	v5 = this;
	v6 = this->SpanList;
	this->ClipRect.left = x1;
	this->ClipRect.top = y1;
	this->ClipRect.right = x2;
	this->ClipRect.bottom = y2;
	if( v6 && this->Height != v6->Num_Lines )
	{
		if( v6 )
		{
			TSpan_List_Manager::~TSpan_List_Manager(v6);
			operator delete(v6);
		}
		v5->SpanList = 0;
	}
	if( !v5->SpanList )
	{
		v7 = (TSpan_List_Manager *)operator new(0x68u);
		if( v7 )
			TSpan_List_Manager::TSpan_List_Manager(v7, v5->Width, v5->Height);
		else
			v8 = 0;
		v5->SpanList = v8;
	}
	TSpan_List_Manager::ResetAll(v5->SpanList);
	TSpan_List_Manager::SetSpanRegions(
		v5->SpanList,
		v5->ClipRect.left,
		v5->ClipRect.top,
		v5->ClipRect.right,
		v5->ClipRect.bottom);
	for ( i = v5->ClipRect.top; i <= v5->ClipRect.bottom; ++i )
		TSpan_List_Manager::AddSpan(v5->SpanList, v5->ClipRect.left, v5->ClipRect.right, i);
	v5->CurSpanList = v5->SpanList;
}

void TDrawArea::Copy(TDrawArea *dest_area, int dest_x, int dest_y, RECT *src_rect, int allow_trans)
{
	TDrawArea *v6; // esi@1
	int v7; // ebp@1
	int v8; // ecx@7
	int v9; // eax@7
	int v10; // edi@7
	int v11; // edx@9
	int v12; // edx@11
	int v13; // ecx@21
	int v14; // edx@21
	int v15; // edi@21
	int v16; // eax@21
	int v17; // ecx@21
	int v18; // eax@23
	int v19; // eax@25
	int v20; // ecx@27
	int v21; // ebx@27
	int v22; // eax@28
	int v23; // edi@28
	int v24; // ecx@30
	int v25; // ebp@30
	int v26; // eax@31
	int v27; // edx@31
	int v28; // eax@33
	int v29; // eax@34
	int v30; // eax@35
	int v31; // eax@36
	int v32; // ecx@37
	int v33; // eax@38
	int v34; // ecx@39
	int v35; // eax@40
	int v36; // eax@47
	int v37; // ecx@49
	TDrawSystem *v38; // ecx@50
	RECT src_rect2; // [sp+10h] [bp-20h]@21
	RECT dest_rect2; // [sp+20h] [bp-10h]@23

	v6 = this;
	v7 = 0;
	if( this->DrawSystem && this->DrawSystem->DrawType == 1 )
	{
		if( this->Bits && dest_area && dest_area->Bits )
		{
			if( src_rect )
			{
				v10 = src_rect->left;
				v7 = src_rect->top;
				v8 = src_rect->right - src_rect->left + 1;
				v9 = src_rect->bottom - src_rect->top + 1;
			}
			else
			{
				v8 = this->Width;
				v9 = v6->Height;
				v10 = 0;
			}
			v11 = v6->Width;
			if( v8 + v10 > v11 )
				v8 = v11 - v10;
			v12 = v6->Height;
			if( v9 + v7 > v12 )
				v9 = v12 - v7;
			if( v6->UseTrans && allow_trans )
			{
				TransDibBlt(
					dest_area->BitmapInfo,
					dest_area->Bits,
					&dest_area->ClipRect,
					dest_x,
					dest_y,
					v8,
					v9,
					v6->BitmapInfo,
					v6->Bits,
					0,
					v10,
					v7,
					v8,
					v9,
					1,
					0,
					0,
					v6->TransColor);
				err = 0;
			}
			else
			{
				DibBlt(
					dest_area->BitmapInfo,
					dest_area->Bits,
					&dest_area->ClipRect,
					dest_x,
					dest_y,
					v8,
					v9,
					v6->BitmapInfo,
					v6->Bits,
					v10,
					v7,
					v8,
					v9,
					1,
					0,
					0);
				err = 0;
			}
		}
	}
	else if( this->DrawSurface && dest_area && dest_area->DrawSurface )
	{
		if( src_rect )
		{
			v14 = src_rect->left;
			v15 = src_rect->top;
			v16 = src_rect->right;
			v17 = src_rect->bottom;
			src_rect2.left = src_rect->left;
			src_rect2.top = v15;
		}
		else
		{
			v13 = this->Height;
			v14 = 0;
			v15 = 0;
			v16 = v6->Width - 1;
			src_rect2.left = 0;
			src_rect2.top = 0;
			v17 = v13 - 1;
		}
		src_rect2.bottom = v17 + 1;
		src_rect2.right = v16 + 1;
		SetRect(&dest_rect2, dest_x, dest_y, dest_x + v16 + 1 - v14, dest_y + v17 + 1 - v15);
		v18 = src_rect2.left;
		if( src_rect2.left < 0 )
		{
			src_rect2.left = 0;
			dest_rect2.left -= v18;
		}
		v19 = src_rect2.top;
		if( src_rect2.top < 0 )
		{
			src_rect2.top = 0;
			dest_rect2.top -= v19;
		}
		v20 = v6->Width;
		v21 = src_rect2.right;
		if( src_rect2.right <= v20 )
		{
			v23 = dest_rect2.right;
		}
		else
		{
			v22 = src_rect2.right - v20;
			v21 = src_rect2.right - (src_rect2.right - v20);
			v23 = dest_rect2.right - (src_rect2.right - v20);
			src_rect2.right -= src_rect2.right - v20;
			dest_rect2.right -= v22;
		}
		v24 = v6->Height;
		v25 = src_rect2.bottom;
		if( src_rect2.bottom <= v24 )
		{
			v27 = dest_rect2.bottom;
		}
		else
		{
			v26 = src_rect2.bottom - v24;
			v25 = src_rect2.bottom - (src_rect2.bottom - v24);
			v27 = dest_rect2.bottom - (src_rect2.bottom - v24);
			src_rect2.bottom -= src_rect2.bottom - v24;
			dest_rect2.bottom -= v26;
		}
		v28 = dest_area->ClipRect.left;
		if( dest_rect2.left < v28 )
		{
			v29 = v28 - dest_rect2.left;
			dest_rect2.left += v29;
			src_rect2.left += v29;
		}
		v30 = dest_area->ClipRect.top;
		if( dest_rect2.top < v30 )
		{
			v31 = v30 - dest_rect2.top;
			dest_rect2.top += v31;
			src_rect2.top += v31;
		}
		v32 = dest_area->ClipRect.right;
		if( v23 > v32 + 1 )
		{
			v33 = v23 - v32 - 1;
			v23 -= v33;
			v21 -= v33;
			dest_rect2.right = v23;
			src_rect2.right = v21;
		}
		v34 = dest_area->ClipRect.bottom;
		if( v27 > v34 + 1 )
		{
			v35 = v27 - v34 - 1;
			v27 -= v35;
			v25 -= v35;
			dest_rect2.bottom = v27;
			src_rect2.bottom = v25;
		}
		if( dest_rect2.left < v23 && dest_rect2.top < v27 && src_rect2.left < v21 && src_rect2.top < v25 )
		{
			ddrval = 1;
			if( v6->UseTrans && allow_trans )
				v36 = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))dest_area->DrawSurface->vfptr[1].Release)(
								dest_area->DrawSurface,
								&dest_rect2,
								v6->DrawSurface,
								&src_rect2,
								0x01008000,
								0);
			else
				v36 = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))dest_area->DrawSurface->vfptr[1].Release)(
								dest_area->DrawSurface,
								&dest_rect2,
								v6->DrawSurface,
								&src_rect2,
								0x01000000,
								0);
			v37 = 0;
			ddrval = v36;
			err = 0;
			if( v36 )
			{
				v38 = v6->DrawSystem;
				v37 = TDrawSystem::GetBlitErrorNum(v36);
				err = v37;
			}
			if( !v37 )
				err = 0;
		}
	}
}

void TDrawArea::PtrCopy(TDrawArea *dest_area, int dest_x, int dest_y, RECT *src_rect)
{
	int v11; // eax@7
	char *v15; // esi@21
	char *v16; // edi@21
	int v17; // ecx@21
	int v18; // eax@21
	char *v19; // edi@22
	char *v20; // esi@22

	void **SrcP;
	void **DestP;

	int XofS;
	int YofD;
	int YofS;

	if( src_rect->left >= 0
		&& src_rect->left <= src_rect->right
		&& src_rect->right < this->Width
		&& src_rect->top >= 0
		&& src_rect->top <= src_rect->bottom
		&& src_rect->bottom < this->Height )
	{
		int nLines = src_rect->bottom - src_rect->top + 1;
		int v11 = src_rect->right - src_rect->left + 1;
		int nWidth = src_rect->right - src_rect->left + 1;

		if( dest_x >= 0 && dest_x < dest_area->Width && dest_y >= 0 && dest_y < dest_area->Height )
		{
			if( dest_x + v11 > dest_area->Width )
				nWidth = dest_area->Width - dest_x;

			if( dest_y + nLines > dest_area->Height )
				nLines = dest_area->Height - dest_y;

			if( this->DrawSystem && this->DrawSystem->DrawType == 2 && !this->Lock(aPtrcopy1, 1) || !dest_area->Lock(aPtrcopy2, 1) )
				return;

			YofD = dest_y;
			XofS = src_rect->left;
			YofS = src_rect->top;

			SrcP = this->CurDisplayOffsets;
			DestP = dest_area->CurDisplayOffsets;

			do
			{
				v15 = (char *)SrcP[YofS] + XofS;
				v16 = (char *)DestP[YofD] + dest_x;
				v17 = ((_BYTE)nWidth - (_BYTE)v16 - (_BYTE)nWidth) & 0x03;
				v18 = nWidth - v17;
				if( nWidth > v17 )
				{
					qmemcpy(v16, v15, v17);
					v20 = &v15[v17];
					v19 = &v16[v17];
					v18 &= 3u;
					unsigned int v21 = (unsigned int)(nWidth - v17) >> 2;
					qmemcpy(v19, v20, 4 * v21);
					v15 = &v20[4 * v21];
					v16 = &v19[4 * v21];
					v17 = 0;
				}
				qmemcpy(v16, v15, v18 + v17);
				++YofS;
				++YofD;
			}
			while ( --nLines );

			if( this->DrawSystem && this->DrawSystem->DrawType == 2 )
			{
				this->Unlock(aPtrcopy1);

				dest_area->Unlock(aPtrcopy2);
			}
		}
	}
}

void TDrawArea::PtrSpanCopy(TDrawArea *dest_area, int dest_x, int dest_y, RECT *src_rect, char **SpanListPtrs)
{
	RECT *v6; // edi@1
	TDrawArea *v7; // edx@1
	int v8; // ecx@2
	int v9; // ecx@4
	int v10; // eax@5
	int v11; // edx@7
	int v12; // eax@7
	TDrawArea *v13; // ebx@8
	int v14; // ecx@10
	int v15; // esi@18
	int v16; // edi@18
	char *i; // ebx@18
	int v18; // eax@19
	char *v19; // esi@19
	char *v20; // edi@19
	int v21; // ecx@19
	int v22; // eax@19
	int v23; // ecx@19
	unsigned __int8 v24; // of@19
	int v25; // eax@19
	char *v26; // edi@20
	char *v27; // esi@20
	unsigned int v28; // ecx@20
	int v29; // [sp-14h] [bp-2Ch]@19
	int v30; // [sp-10h] [bp-28h]@19
	void **SrcP; // [sp+Ch] [bp-Ch]@17
	int XofS; // [sp+10h] [bp-8h]@17
	TDrawArea *DestP; // [sp+14h] [bp-4h]@1
	void **DestPa; // [sp+14h] [bp-4h]@17
	int YofS; // [sp+20h] [bp+8h]@17
	int YofD; // [sp+24h] [bp+Ch]@17
	int nLines; // [sp+2Ch] [bp+14h]@7

	v6 = src_rect;
	v7 = this;
	DestP = this;
	if( src_rect->left >= 0 )
	{
		v8 = src_rect->right;
		if( src_rect->left <= v8 && v8 < v7->Width )
		{
			v9 = src_rect->top;
			if( v9 >= 0 )
			{
				v10 = src_rect->bottom;
				if( v9 <= v10 && v10 < v7->Height )
				{
					v11 = dest_x;
					v12 = v10 - v9 + 1;
					nLines = v12;
					if( dest_x >= 0 )
					{
						v13 = dest_area;
						if( dest_x < dest_area->Width && dest_y >= 0 )
						{
							v14 = dest_area->Height;
							if( dest_y < v14 )
							{
								if( dest_y + v12 > v14 )
									nLines = v14 - dest_y;
								if( DestP->DrawSystem && DestP->DrawSystem->DrawType == 2 )
								{
									if( !TDrawArea::Lock(dest_area, aPtrspancopy, 1) )
										return;
									v11 = dest_x;
								}
								XofS = v6->left;
								YofS = v6->top;
								YofD = dest_y;
								SrcP = DestP->CurDisplayOffsets;
								DestPa = v13->CurDisplayOffsets;
								do
								{
									v15 = (int)SrcP[YofS] + XofS;
									v16 = (int)DestPa[YofD] + v11;
									for ( i = SpanListPtrs[YofS]; i; i = *(char **)i )
									{
										v30 = v15;
										v29 = v16;
										v18 = *((_DWORD *)i + 2);
										v19 = (char *)(v18 + v15);
										v20 = (char *)(v18 + v16);
										v21 = *((_DWORD *)i + 3) - v18 + 1;
										v22 = v21;
										v23 = ((_BYTE)v21 - (_BYTE)v20 - (_BYTE)v21) & 3;
										v24 = __OFSUB__(v22, v23);
										v25 = v22 - v23;
										if( !((unsigned __int8)((v25 < 0) ^ v24) | (v25 == 0)) )
										{
											qmemcpy(v20, v19, v23);
											v27 = &v19[v23];
											v26 = &v20[v23];
											v28 = v25;
											v25 &= 3u;
											v28 >>= 2;
											qmemcpy(v26, v27, 4 * v28);
											v19 = &v27[4 * v28];
											v20 = &v26[4 * v28];
											v23 = 0;
										}
										qmemcpy(v20, v19, v25 + v23);
										v16 = v29;
										v15 = v30;
									}
									++YofS;
									++YofD;
								}
								while ( --nLines );
							}
						}
					}
				}
			}
		}
	}
}

void TDrawArea::PtrSurfaceCopy(TDrawArea *dest_area, int dest_x, int dest_y, RECT *src_rect, int SourceLock, int DestLock)
{
	int v7; // edi@1
	TDrawArea *v8; // edx@1
	int v9; // ecx@2
	int v10; // esi@4
	int v11; // eax@5
	int v12; // eax@7
	int v13; // edi@8
	int v14; // ecx@9
	int v15; // esi@10
	int v16; // esi@25
	char *v17; // esi@26
	char *v18; // edi@26
	int v19; // ecx@27
	int v20; // eax@27
	char *v21; // edi@28
	char *v22; // esi@28
	unsigned int v23; // ecx@28
	void **SrcP; // [sp+Ch] [bp-14h]@25
	void **DestP; // [sp+10h] [bp-10h]@25
	int nWidth; // [sp+14h] [bp-Ch]@7
	TDrawArea *XofS; // [sp+18h] [bp-8h]@1
	int XofSa; // [sp+18h] [bp-8h]@25
	int nLines; // [sp+1Ch] [bp-4h]@7
	int YofD; // [sp+30h] [bp+10h]@25
	int YofS; // [sp+34h] [bp+14h]@25

	v7 = src_rect->left;
	v8 = this;
	XofS = this;
	if( src_rect->left >= 0 )
	{
		v9 = src_rect->right;
		if( v7 <= v9 && v9 < v8->Width )
		{
			v10 = src_rect->top;
			if( v10 >= 0 )
			{
				v11 = src_rect->bottom;
				if( v10 <= v11 && v11 < v8->Height )
				{
					nLines = v11 - v10 + 1;
					v12 = v9 - v7 + 1;
					nWidth = v9 - v7 + 1;
					if( dest_x >= 0 )
					{
						v13 = dest_area->Width;
						if( dest_x < v13 )
						{
							v14 = dest_y;
							if( dest_y >= 0 )
							{
								v15 = dest_area->Height;
								if( dest_y < v15 )
								{
									if( dest_x + v12 > v13 )
										nWidth = v13 - dest_x;
									if( dest_y + nLines > v15 )
										nLines = v15 - dest_y;
									if( v8->DrawSystem && v8->DrawSystem->DrawType == 2 )
									{
										if( SourceLock )
										{
											if( !TDrawArea::Lock(v8, aPtrsurfacecopy, 1) )
												return;
											v8 = XofS;
											v14 = dest_y;
										}
										if( DestLock )
										{
											if( !TDrawArea::Lock(dest_area, aPtrsurfaceco_1, 1) )
											{
												if( SourceLock )
													TDrawArea::Unlock(XofS, aPtrsurfacecopy);
												return;
											}
											v8 = XofS;
											v14 = dest_y;
										}
									}
									YofD = v14;
									v16 = src_rect->left;
									YofS = src_rect->top;
									SrcP = v8->CurDisplayOffsets;
									XofSa = v16;
									DestP = dest_area->CurDisplayOffsets;
									do
									{
										v17 = (char *)SrcP[YofS] + XofSa;
										v18 = (char *)DestP[YofD] + dest_x;
										if( ((unsigned __int8)v18 ^ (unsigned __int8)(XofSa + LOBYTE(SrcP[YofS]))) & 3 )
										{
											qmemcpy(v18, v17, nWidth);
										}
										else
										{
											v19 = ((_BYTE)nWidth - (_BYTE)v18 - (_BYTE)nWidth) & 3;
											v20 = nWidth - v19;
											if( nWidth > v19 )
											{
												qmemcpy(v18, v17, v19);
												v22 = &v17[v19];
												v21 = &v18[v19];
												v20 &= 3u;
												v23 = (unsigned int)(nWidth - v19) >> 2;
												qmemcpy(v21, v22, 4 * v23);
												v17 = &v22[4 * v23];
												v18 = &v21[4 * v23];
												v19 = 0;
											}
											qmemcpy(v18, v17, v20 + v19);
										}
										++YofS;
										++YofD;
										--nLines;
									}
									while ( nLines );
									if( v8->DrawSystem && v8->DrawSystem->DrawType == 2 )
									{
										if( SourceLock )
											TDrawArea::Unlock(v8, aPtrsurfacecopy);
										if( DestLock )
											TDrawArea::Unlock(dest_area, aPtrsurfaceco_1);
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void TDrawArea::OverlayMemCopy(RECT *src_rect, RECT *dest_rect, int xDelta, int yDelta, int xOffset, int YOffset)
{
	int v7; // edi@6
	int v8; // edx@6
	int v9; // ecx@6
	int v10; // ebx@6
	RECT *v11; // eax@6
	bool v12; // zf@8
	RECT *v13; // eax@14
	int v14; // edx@14
	RECT *v15; // eax@17
	int v16; // edx@17
	TDrawArea *v17; // [sp+Ch] [bp-18h]@1
	int LineLen; // [sp+10h] [bp-14h]@6
	int BackCopy; // [sp+14h] [bp-10h]@6
	int SrcXStart; // [sp+18h] [bp-Ch]@6
	int DstXStart; // [sp+1Ch] [bp-8h]@6
	int Lines; // [sp+20h] [bp-4h]@6
	void **SrcP; // [sp+38h] [bp+14h]@13

	v17 = this;
	if( (xDelta || yDelta)
		&& (!this->DrawSystem || this->DrawSystem->DrawType != 2 || TDrawArea::Lock(this, aOverlaymemcopy, 1)) )
	{
		v7 = xOffset;
		BackCopy = 0;
		v8 = src_rect->bottom;
		v9 = src_rect->top;
		v10 = src_rect->right;
		Lines = src_rect->bottom - v9 + 1;
		SrcXStart = xOffset + src_rect->left;
		v11 = dest_rect;
		LineLen = (v10 - src_rect->left + 4) >> 2;
		DstXStart = dest_rect->left + xOffset;
		if( yDelta < 0 )
		{
			src_rect = (RECT *)-1;
			dest_rect = (RECT *)(YOffset + v8);
			xOffset = YOffset + v11->bottom;
		}
		v12 = yDelta == 0;
		if( yDelta > 0 )
		{
			src_rect = (RECT *)1;
			dest_rect = (RECT *)(YOffset + v9);
			xOffset = YOffset + v11->top;
			v12 = yDelta == 0;
		}
		if( v12 )
		{
			dest_rect = (RECT *)(YOffset + v9);
			xOffset = YOffset + v11->top;
			src_rect = (RECT *)1;
			if( xDelta < 0 )
			{
				BackCopy = 1;
				SrcXStart = v7 + v10 - 3;
				DstXStart = v11->right + v7 - 3;
			}
		}
		SrcP = v17->CurDisplayOffsets;
		if( BackCopy )
		{
			v15 = dest_rect;
			v16 = xOffset;
			do
			{
				qmemcpy((char *)SrcP[v16] + DstXStart, (char *)SrcP[(_DWORD)v15] + SrcXStart, 4 * LineLen);
				v15 = (RECT *)((char *)v15 + (_DWORD)src_rect);
				v16 += (int)src_rect;
				--Lines;
			}
			while ( Lines );
		}
		else
		{
			v13 = dest_rect;
			v14 = xOffset;
			do
			{
				qmemcpy((char *)SrcP[v14] + DstXStart, (char *)SrcP[(_DWORD)v13] + SrcXStart, 4 * LineLen);
				v13 = (RECT *)((char *)v13 + (_DWORD)src_rect);
				v14 += (int)src_rect;
				--Lines;
			}
			while ( Lines );
		}
		if( v17->DrawSystem )
		{
			if( v17->DrawSystem->DrawType == 2 )
				TDrawArea::Unlock(v17, aOverlaymemcopy);
		}
	}
}

void TDrawArea::SetTrans(int use_trans_in, char trans_color_in)
{
	DDCOLORKEY ddck;

	this->UseTrans = use_trans_in;

	if( use_trans_in )
		this->TransColor = trans_color_in;
	else
		this->TransColor = -1;

	if( use_trans_in && this->DrawSurface && this->DrawSystem && this->DrawSystem->DrawType == 2 )
	{
		ddck.dwColorSpaceLowValue = this->TransColor;
		ddck.dwColorSpaceHighValue = ddck.dwColorSpaceLowValue;

		((void (__stdcall *)(IDirectDrawSurface *, signed int, DDCOLORKEY *))this->DrawSurface->vfptr[9].Release)(this->DrawSurface, 8, &ddck);
	}
}

void TDrawArea::SetOverlayTrans(int use_trans_in, char trans_color_in)
{
	DDCOLORKEY ddck;

	this->UseTrans = use_trans_in;
	this->TransColor = trans_color_in;

	if( use_trans_in && this->DrawSurface && this->DrawSystem && this->DrawSystem->DrawType == 2 )
	{
		ddck.dwColorSpaceLowValue = (unsigned __int8)trans_color_in;
		ddck.dwColorSpaceHighValue = (unsigned __int8)trans_color_in;
		((void (__stdcall *)(IDirectDrawSurface *, signed int, DDCOLORKEY *))this->DrawSurface->vfptr[9].Release)(this->DrawSurface, 16, &ddck);
	}
}

void TDrawArea::SetPixel(int x, int y, char color)
{
	if( this->Bits
		&& x >= this->ClipRect.left
		&& x <= this->ClipRect.right
		&& y >= this->ClipRect.top
		&& y <= this->ClipRect.bottom )
	{
		if( this->Orien == 1 )
			*(&this->Bits[x] + y * this->Pitch) = color;
		else
			*(&this->Bits[x] + this->Pitch * (this->Height - y - 1)) = color;
	}
}

static void TDrawArea::DrawLine(int x1, int y1, int x2, int y2, char color)
{
	int v6; // ebp@1
	int v7; // esi@1
	int v8; // edi@2
	int v9; // ebx@2
	int v10; // eax@6
	int v11; // ecx@6
	int v12; // edi@10
	int v13; // ebp@10
	int v14; // ecx@11
	int v15; // ebx@14
	int i; // eax@14
	int v17; // ebx@19
	int x1a; // [sp+14h] [bp+4h]@11
	int yd; // [sp+18h] [bp+8h]@11

	v6 = x2;
	v7 = x1;
	if( x1 == x2 )
	{
		v8 = y1;
		v9 = y2;
		if( y1 <= y2 || (v8 = y2, v9 = y1, y2 <= y1) )
		{
			do
				ASMDraw_HLine(x1, x2, v8++);
			while ( v8 <= v9 );
		}
	}
	else
	{
		v10 = y1;
		v11 = y2;
		if( y1 == y2 )
		{
			ASMDraw_HLine(x1, x2, y1);
		}
		else
		{
			if( x2 < x1 )
			{
				v10 = y2;
				v7 = x2;
				x2 = x1;
				v6 = x1;
				y2 = y1;
				v11 = y1;
			}
			v12 = v10;
			v13 = v6 - v7 + 1;
			if( v10 >= v11 )
			{
				x1a = -1;
				yd = v10 - v11 + 1;
				v14 = v10 - v11 + 1;
			}
			else
			{
				x1a = 1;
				v14 = v11 - v10 + 1;
				yd = v14;
			}
			if( v13 < v14 )
			{
				v17 = 0;
				while ( 1 )
				{
					ASMDraw_HLine(v7, v7, v12);
					if( v12 == y2 )
						break;
					v17 += v13;
					if( v17 >= yd )
					{
						++v7;
						v17 -= yd;
					}
					v12 += x1a;
				}
			}
			else
			{
				v15 = 0;
				for ( i = v7; v7 < x2; ++v7 )
				{
					v15 += v14;
					if( v15 >= v13 )
					{
						ASMDraw_HLine(i, v7, v12);
						v12 += x1a;
						v14 = yd;
						v15 -= v13;
						i = v7 + 1;
					}
				}
				ASMDraw_HLine(i, v7, v12);
			}
		}
	}
}

void TDrawArea::DrawRect(int x1, int y1, int x2, int y2, char color)
{
	int v6; // ebp@1
	int v7; // edi@1
	int v8; // ebx@3
	int v9; // esi@3
	int v10; // edi@5
	int v11; // esi@6
	TDrawArea *v12; // [sp+10h] [bp-4h]@1

	v6 = x1;
	v7 = x2;
	v12 = this;
	if( x1 > x2 )
	{
		v6 = x2;
		x2 = x1;
		v7 = x1;
	}
	v8 = y1;
	v9 = y2;
	if( y1 > y2 )
	{
		v8 = y2;
		y2 = y1;
		v9 = y1;
	}
	v10 = v7 - v6 + 1;
	if( v10 >= 1 )
	{
		v11 = v9 - v8 + 1;
		if( v11 >= 1 )
		{
			this->DrawHorzLine(v6, v8, v10, color);
			this->DrawHorzLine(v6, y2, v10, color);
			this->DrawVertLine(v6, v8, v11, color);
			this->DrawVertLine(x2, v8, v11, color);
		}
	}
}

void TDrawArea::DrawRect(RECT *rect, char color)
{
	this->DrawRect(
		rect->left,
		rect->top,
		rect->right,
		rect->bottom,
		color);
}

void TDrawArea::DrawHorzLine(int x, int y, int len, char color)
{
	int v6;
	int v7;
	int v8;
	int v9;
	int v10;

	if( this->Bits )
	{
		v6 = this->ClipRect.right;
		v7 = x;
		if( x <= v6 && y >= this->ClipRect.top && y <= this->ClipRect.bottom )
		{
			v8 = this->ClipRect.left;
			if( x >= v8 )
			{
				v9 = len;
			}
			else
			{
				v9 = x - v8 + len;
				v7 = this->ClipRect.left;
			}
			if( v9 + v7 - 1 > v6 )
				v9 = v6 - v7 + 1;
			if( v9 >= 1 )
			{
				if( this->Orien == 1 )
					v10 = y * this->Pitch;
				else
					v10 = this->Pitch * (this->Height - y - 1);
				memset(&this->Bits[v7] + v10, (unsigned __int8)color, v9);
			}
		}
	}
}

void TDrawArea::DrawVertLine(int x, int y, int len, char color)
{
	char *v5; // ebx@1
	int v6; // eax@4
	int v7; // edx@4
	int v8; // esi@5
	int v9; // ebp@6
	int v10; // esi@12
	char *v11; // eax@12
	int v12; // esi@13
	int v13; // ecx@15

	v5 = this->Bits;
	if( v5 )
	{
		if( x >= this->ClipRect.left && x <= this->ClipRect.right )
		{
			v6 = this->ClipRect.bottom;
			v7 = y;
			if( y <= v6 )
			{
				v8 = this->ClipRect.top;
				if( y >= v8 )
				{
					v9 = len;
				}
				else
				{
					v9 = y - v8 + len;
					v7 = this->ClipRect.top;
				}
				if( v9 + v7 - 1 > v6 )
					v9 = v6 - v7 + 1;
				if( v9 >= 1 )
				{
					if( this->Orien == 1 )
					{
						v10 = this->Pitch;
						v11 = &v5[x] + v10 * v7;
					}
					else
					{
						v12 = this->Pitch;
						v11 = &v5[x] + v12 * (this->Height - v7 - 1);
						v10 = -v12;
					}
					if( v9 > 0 )
					{
						v13 = v9;
						do
						{
							*v11 = color;
							v11 += v10;
							--v13;
						}
						while ( v13 );
					}
				}
			}
		}
	}
}

void TDrawArea::FillRect(int x1, int y1, int x2, int y2, char color)
{
	int v6; // edi@2
	int v7; // esi@2
	int v8; // eax@4
	int v9; // edx@4
	int v10; // ebx@7
	int v11; // ebp@9
	int v12; // edx@18
	int v13; // ebp@18
	int v14; // ecx@21
	int v15; // eax@21
	int v16; // edi@21
	char *v17; // esi@21
	int v18; // edx@22
	int x1a; // [sp+18h] [bp+4h]@18

	char *v19 = this->Bits;
	if( this->Bits )
	{
		v6 = x1;
		v7 = x2;
		if( x1 > x2 )
		{
			v6 = x2;
			v7 = x1;
		}
		v8 = y1;
		v9 = y2;
		if( y1 > y2 )
		{
			v8 = y2;
			v9 = y1;
		}
		if( v6 <= this->ClipRect.right )
		{
			v10 = this->ClipRect.left;
			if( v7 >= v10 && v8 <= this->ClipRect.bottom )
			{
				v11 = this->ClipRect.top;
				if( v9 >= v11 )
				{
					if( v6 < v10 )
						v6 = this->ClipRect.left;
					if( v7 > this->ClipRect.right )
						v7 = this->ClipRect.right;
					if( v8 < v11 )
						v8 = this->ClipRect.top;
					if( v9 > this->ClipRect.bottom )
						v9 = this->ClipRect.bottom;
					v12 = v9 - v8 + 1;
					x1a = v7 - v6 + 1;
					v13 = v12;
					if( x1a >= 1 && v12 >= 1 )
					{
						if( this->Orien == 1 )
						{
							v14 = this->Pitch;
							v15 = v6 + v14 * v8;
							v16 = v14;
							v17 = &v19[v15];
						}
						else
						{
							v18 = this->Pitch;
							v17 = &v19[v6] + v18 * (this->Height - v8 - 1);
							v16 = -v18;
						}
						if( v13 > 0 )
						{
							do
							{
								memset(v17, (unsigned __int8)color, x1a);
								v17 += v16;
							}
							while ( --v13 );
						}
					}
				}
			}
		}
	}
}

void TDrawArea::DrawBevel(int x1, int y1, int x2, int y2, char c1, char c2)
{
	int v7 = x2;
	int v8 = x1;
	if( x1 > x2 )
	{
		v8 = x2;
		x2 = x1;
		v7 = x1;
	}
	int v10 = y1;
	int v11 = y2;
	if( y1 > y2 )
	{
		v10 = y2;
		y2 = y1;
		v11 = y1;
	}
	int v12 = v7 - v8 + 1;
	if( v12 >= 1 )
	{
		int x1a = v11 - v10 + 1;
		if( x1a >= 1 )
		{
			int x1b = x1a - 1;
			this->DrawHorzLine(v8 + 1, v10, v12 - 1, c1);
			this->DrawVertLine(x2, v10 + 1, x1b, c1);
			this->DrawHorzLine(v8, y2, v12, c2);
			this->DrawVertLine(v8, v10, x1b, c2);
		}
	}
}

void TDrawArea::DrawBevel2(int x1, int y1, int x2, int y2, char c1, char c2, char c3, char c4)
{
	int v9 = x1;
	int v10 = x2;
	if( x1 > x2 )
	{
		x1 = x2;
		x2 = v9;
		v10 = v9;
		v9 = x1;
	}
	int v12 = y1;
	int v13 = y2;
	if( y1 > y2 )
	{
		v12 = y2;
		y2 = y1;
		v13 = y1;
	}
	int v14 = v10 - v9 + 1;
	if( v14 >= 1 )
	{
		int v15 = v13 - v12 + 1;
		if( v15 >= 1 )
		{
			int x = v9 + 1;
			this->DrawHorzLine(v9 + 1, v12, v14 - 1, c1);
			this->DrawVertLine(x2, v12 + 1, v15 - 2, c1);
			this->DrawHorzLine(x1 + 2, v12 + 1, v14 - 3, c2);
			this->DrawVertLine(x2 - 1, v12 + 2, v15 - 4, c2);
			this->DrawHorzLine(x1, y2, v14, c4);
			this->DrawVertLine(x1, v12, v15 - 1, c4);
			this->DrawHorzLine(x, y2 - 1, v14 - 2, c3);
			this->DrawVertLine(x, v12 + 1, v15 - 3, c3);
		}
	}
}

void TDrawArea::DrawBevel3(int x1, int y1, int x2, int y2, char c1, char c2, char c3, char c4, char c5, char c6)
{
	int v11 = x1;
	int v12 = x2;
	if( x1 > x2 )
	{
		x1 = x2;
		x2 = v11;
		v12 = v11;
		v11 = x1;
	}
	int v14 = y1;
	int v15 = y2;
	if( y1 > y2 )
	{
		v14 = y2;
		y2 = y1;
		v15 = y1;
	}
	int v16 = v12 - v11 + 1;
	if( v16 >= 1 )
	{
		int v17 = v15 - v14 + 1;
		if( v17 >= 1 )
		{
			int x = v11 + 1;
			this->DrawHorzLine(v11 + 1, v14, v16 - 1, c1);
			this->DrawVertLine(x2, v14 + 1, v17 - 2, c1);
			this->DrawHorzLine(x1 + 2, v14 + 1, v16 - 3, c2);
			this->DrawVertLine(x2 - 1, v14 + 2, v17 - 4, c2);
			this->DrawHorzLine(x1 + 3, v14 + 2, v16 - 5, c3);
			this->DrawVertLine(x2 - 2, v14 + 3, v17 - 6, c3);
			this->DrawHorzLine(x1, y2, v16, c6);
			this->DrawVertLine(x1, v14, v17 - 1, c6);
			this->DrawHorzLine(x, y2 - 1, v16 - 2, c5);
			this->DrawVertLine(x, v14 + 1, v17 - 3, c5);
			this->DrawHorzLine(x1 + 2, y2 - 2, v16 - 4, c4);
			this->DrawVertLine(x1 + 2, v14 + 2, v17 - 5, c4);
		}
	}
}

void TDrawArea::DrawBevel21(int x1, int y1, int x2, int y2, char c1, char c2, char c3, char c4)
{
	int v10 = x2;
	if( x1 > x2 )
	{
		x1 = x2;
		x2 = x1;
		v10 = x1;
	}
	int v12 = y1;
	int v13 = y2;
	if( y1 > y2 )
	{
		v12 = y2;
		y2 = y1;
		v13 = y1;
	}
	int v14 = v10 - x1 + 1;
	if( v14 >= 1 )
	{
		int v15 = v13 - v12 + 1;
		if( v15 >= 1 )
		{
			int y1a = x1 + 1;
			this->DrawHorzLine(x1 + 1, v12, v14 - 1, c1);
			this->DrawVertLine(x2, v12 + 1, v15 - 2, c1);
			this->DrawHorzLine(y1a, v12 + 1, v14 - 2, c2);
			this->DrawVertLine(x2 - 1, v12 + 2, v15 - 3, c2);
			this->DrawHorzLine(x1, y2, v14, c4);
			this->DrawVertLine(x1, v12, v15 - 1, c4);
		}
	}
}

void TDrawArea::DrawBevel32(int x1, int y1, int x2, int y2, char c1, char c2, char c3, char c4, char c5, char c6)
{
	int v12 = x2;
	if( x1 > x2 )
	{
		x1 = x2;
		x2 = x1;
		v12 = x1;
	}
	int v14 = y1;
	int v15 = y2;
	if( y1 > y2 )
	{
		v14 = y2;
		y2 = y1;
		v15 = y1;
	}
	int v16 = v12 - x1 + 1;
	if( v16 >= 1 )
	{
		int v17 = v15 - v14 + 1;
		if( v17 >= 1 )
		{
			int x = x1 + 1;
			this->DrawHorzLine(x1 + 1, v14, v16 - 1, c1);
			this->DrawVertLine(x2, v14 + 1, v17 - 2, c1);
			this->DrawHorzLine(x1 + 2, v14 + 1, v16 - 3, c2);
			this->DrawVertLine(x2 - 1, v14 + 2, v17 - 4, c2);
			this->DrawHorzLine(x1 + 2, v14 + 2, v16 - 4, c3);
			this->DrawVertLine(x2 - 2, v14 + 3, v17 - 5, c3);
			this->DrawHorzLine(x1, y2, v16, c6);
			this->DrawVertLine(x1, v14, v17 - 1, c6);
			this->DrawHorzLine(x, y2 - 1, v16 - 2, c5);
			this->DrawVertLine(x, v14 + 1, v17 - 3, c5);
		}
	}
}

void TDrawArea::SetShadowTable(RGE_Color_Table *color_table_in)
{
	this->shadow_color_table = color_table_in;
}

void TDrawArea::DrawShadowBox(int x1, int y1, int x2, int y2)
{
	_BYTE *v16;
	int v17;

	if( this->shadow_color_table && this->Bits )
	{
		if( x1 < this->ClipRect.left )
			x1 = this->ClipRect.left;
		if( y1 < this->ClipRect.top )
			y1 = this->ClipRect.top;
		if( x2 > this->ClipRect.right )
			x2 = this->ClipRect.right;
		int v6 = y2;
		if( y2 > this->ClipRect.bottom )
			v6 = this->ClipRect.bottom;
		if( x1 < 0 )
			x1 = 0;
		if( y1 < 0 )
			y1 = 0;
		int v7 = this->Width;
		if( x2 >= v7 )
			x2 = v7 - 1;
		int v8 = this->Height;
		if( v6 >= v8 )
			v6 = v8 - 1;
		if( x2 >= x1 && v6 >= y1 )
		{
			int v10 = this->Orien * this->AlignedWidth();
			int v11 = this->Orien >= 1 ? y1 * v10 : v10 * (y1 - this->Height + 1);
			int v12 = (int)(&this->Bits[x1] + v11);
			unsigned int v13 = x2 + v12 - x1;
			int v14 = (int)this->shadow_color_table->table;
			if( y1 <= v6 )
			{
				int v15 = v6 - y1 + 1;
				do
				{
					v16 = (_BYTE *)v12;
					if( v12 <= v13 )
					{
						do
						{
							v17 = *v16++;
							*(v16 - 1) = *(_BYTE *)(v14 + v17);
						}
						while ( (unsigned int)v16 <= v13 );
					}
					v12 += v10;
					v13 += v10;
				}
				while ( --v15 );
			}
		}
	}
}

void TDrawArea::GetPalette(PALETTEENTRY *palette1)
{
	PALETTEENTRY *v2 = palette1;
	signed int i = 256;
	do
	{
		++v2;
		--i;
		v2[-1] = *(PALETTEENTRY *)((char *)this->DrawSystem + 120 - (_DWORD)palette1 + (unsigned int)v2 - 4);
	}
	while ( i );
}

void TDrawArea::SetPalette(PALETTEENTRY *palette1)
{
	palette1[0x0000].peRed   = 0;
	palette1[0x0000].peGreen = 0;
	palette1[0x0000].peBlue  = 0;
	palette1[0x0000].peFlags = 0;

	palette1[0x00FF].peRed   = -1;
	palette1[0x00FF].peGreen = -1;
	palette1[0x00FF].peBlue  = -1;
	palette1[0x00FF].peFlags = 0;

	this->DrawSystem->ModifyPalette(0x0000, 0x0100, palette1);
}

void TDrawArea::take_snapshot(char *filespec, int *index_no)
{
	TDrawArea *v3; // esi@1
	int v4; // eax@1
	int v5; // ecx@1
	signed int v6; // eax@1
	char v7; // dl@2
	char v8; // cl@2
	signed int v9; // ebp@3
	int v10; // eax@7
	_BYTE *v11; // edi@10
	int v12; // ebx@10
	int i; // ebp@12
	int v14; // eax@13
	_BYTE *j; // ecx@13
	size_t bmWide; // [sp+10h] [bp-87Ch]@1
	int v17; // [sp+14h] [bp-878h]@1
	tagBITMAPFILEHEADER bmFH; // [sp+18h] [bp-874h]@1
	tagBITMAPINFOHEADER bmIH; // [sp+28h] [bp-864h]@1
	char BMPFile[60]; // [sp+50h] [bp-83Ch]@5
	tagRGBQUAD bmPAL[256]; // [sp+8Ch] [bp-800h]@2
	PALETTEENTRY thePal[256]; // [sp+48Ch] [bp-400h]@1

	v3 = this;
	v4 = this->Width;
	v5 = this->Height;
	bmIH.biWidth = v4;
	v17 = v5;
	bmIH.biHeight = v5;
	bmWide = ((_WORD)v4 + 3) & 0xFFFC;
	bmFH.bfType = 19778;
	bmFH.bfSize = bmWide * v5 + 1078;
	bmFH.bfReserved1 = 0;
	bmFH.bfReserved2 = 0;
	bmFH.bfOffBits = 1078;
	bmIH.biSize = 40;
	bmIH.biPlanes = 1;
	bmIH.biBitCount = 8;
	bmIH.biCompression = 0;
	bmIH.biSizeImage = 0;
	bmIH.biXPelsPerMeter = 0;
	bmIH.biYPelsPerMeter = 0;
	bmIH.biClrUsed = 0;
	bmIH.biClrImportant = 0;
	TDrawArea::GetPalette(v3, thePal);
	v6 = 0;
	do
	{
		v7 = thePal[v6].peGreen;
		bmPAL[v6].rgbBlue = thePal[v6].peBlue;
		v8 = thePal[v6].peRed;
		bmPAL[v6].rgbGreen = v7;
		bmPAL[v6].rgbRed = v8;
		bmPAL[v6].rgbReserved = 0;
		++v6;
	}
	while ( v6 < 256 );
	v9 = 0;
	while ( 1 )
	{
		if( filespec )
			sprintf(BMPFile, filespec, *index_no);
		else
			sprintf(BMPFile, aCAoe_03d_bmp, *index_no);
		++v9;
		v10 = _open(BMPFile, 0);
		if( v10 == -1 )
			break;
		++*index_no;
		_close(v10);
		if( v9 > 1000 )
			return;
	}
	v11 = malloc(bmWide);
	v12 = _open(BMPFile, 33537, 384);
	if( v12 != -1 )
	{
		_write(v12, &bmFH, 0xEu);
		_write(v12, &bmIH, 0x28u);
		_write(v12, bmPAL, 0x400u);
		if( TDrawArea::Lock(v3, aTake_snapshot, 1) )
		{
			for ( i = v17 - 1; i >= 0; --i )
			{
				v14 = 0;
				for ( j = v3->CurDisplayOffsets[i]; v14 < v3->Width; ++j )
					v11[v14++] = *j;
				_write(v12, v11, bmWide);
			}
			TDrawArea::Unlock(v3, aTake_snapshot);
		}
		_close(v12);
	}
	free(v11);
}
