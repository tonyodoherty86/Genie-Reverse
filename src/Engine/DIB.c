
_UNKNOWN SrcXTbl;

unsigned __int8 shape_file_first;
unsigned __int8 sound_file_first;

char asc_5837C4[3] = " \n";
char byte_5837C6 = '\0';

struct PAL_TABLE *System_color_Table = NULL;
_UNKNOWN unk_5841E5;

void DibBlt(BITMAPINFO256 *DestInfo, char *DestBits, RECT *ClipRect, int DestX, int DestY, int DestWid, int DestHgt, BITMAPINFO256 *SrcInfo, char *SrcBits, int SrcX, int SrcY, int SrcWid, int SrcHgt, int Clip, int Mirror, int Flip)
{
    int v16; // esi@1
    BITMAPINFO256 *v17; // edi@1
    BITMAPINFO256 *v18; // ebp@3
    int v19; // ecx@5
    int v20; // ebx@5
    int v21; // esi@5
    int v22; // edi@6
    char *v23; // edi@8
    int v24; // eax@12
    int v25; // esi@12
    char *v26; // esi@14
    int v27; // ebp@14
    int v28; // eax@20
    int v29; // edx@20
    int v30; // ebp@21
    void *v31; // ecx@21
    int v32; // edx@24
    int v33; // ecx@25
    int v34; // ebp@25
    signed int v35; // ebp@28
    char *v36; // ebx@29
    int v37; // esi@29
    char *v38; // ecx@31
    int v39; // edx@33
    int v40; // ecx@33
    int *v41; // esi@34
    int v42; // eax@35
    int DestOrien; // [sp+10h] [bp-8h]@3
    int DestTotHgt; // [sp+14h] [bp-4h]@3

    v16 = Flip;
    v17 = DestInfo;
    if( Clip
        && !ClipDibBlt(DestInfo, ClipRect, &DestX, &DestY, &DestWid, &DestHgt, &SrcX, &SrcY, &SrcWid, &SrcHgt, Mirror, Flip) )
    {
        return;
    }
    GetDibDim(v17, &Clip, &DestTotHgt, &DestOrien);
    GetDibDim(SrcInfo, &Flip, (int *)&ClipRect, (int *)&DestInfo);
    v18 = DestInfo;
    if( v16 )
    {
        v18 = (BITMAPINFO256 *)-(signed int)DestInfo;
        DestInfo = (BITMAPINFO256 *)-(signed int)DestInfo;
    }
    v19 = DestWid;
    v20 = DestOrien;
    v21 = (SrcWid << 8) / DestWid;
    SrcInfo = (BITMAPINFO256 *)((SrcHgt << 8) / DestHgt);
    if( DestOrien == 1 )
        v22 = DestY * Clip;
    else
        v22 = Clip * (DestTotHgt - DestY - 1);
    v23 = &DestBits[DestX] + v22;
    if( v21 != 256 || (SrcHgt << 8) / DestHgt != 256 )
    {
        if( !Mirror )
        {
            v28 = SrcX;
            v29 = SrcX;
            if( DestWid <= 0 )
                goto LABEL_28;
            v30 = DestWid;
            v31 = &SrcXTbl;
            do
            {
                v31 = (char *)v31 + 4;
                *((_DWORD *)v31 - 1) = v29 >> 8;
                v29 += v21;
                --v30;
            }
            while ( v30 );
            goto LABEL_27;
        }
    }
    else if( !Mirror )
    {
        if( v18 == (BITMAPINFO256 *)1 )
        {
            v24 = Flip;
            v25 = SrcY * Flip;
        }
        else
        {
            v24 = Flip;
            v25 = Flip * ((_DWORD)ClipRect + -SrcY - 1);
        }
        Flip = v24 * (_DWORD)v18;
        v26 = &SrcBits[SrcX] + v25;
        v27 = 0;
        Clip *= DestOrien;
        if( DestHgt > 0 )
        {
            while ( 1 )
            {
                memcpy(v23, v26, v19);
                v23 += Clip;
                v26 += Flip;
                if( ++v27 >= DestHgt )
                    break;
                v19 = DestWid;
            }
        }
        return;
    }
    v28 = SrcX;
    v32 = SrcX;
    if( DestWid - 1 <= -1 )
        goto LABEL_28;
    v33 = 4 * (DestWid - 1) + 6476344;
    v34 = DestWid;
    do
    {
        v33 -= 4;
        *(_DWORD *)(v33 + 4) = v32 >> 8;
        v32 += v21;
        --v34;
    }
    while ( v34 );
LABEL_27:
    v28 = SrcX;
LABEL_28:
    v35 = SrcY << 8;
    Clip *= v20;
    Mirror = 0;
    if( DestHgt > 0 )
    {
        v36 = SrcBits;
        v37 = Flip;
        do
        {
            if( DestInfo == (BITMAPINFO256 *)1 )
                v38 = (char *)(v35 >> 8);
            else
                v38 = (char *)ClipRect + -(v35 >> 8) - 1;
            v39 = 0;
            v40 = (int)(&v36[v28] + v37 * (_DWORD)v38);
            if( DestWid > 0 )
            {
                v41 = (int *)&SrcXTbl;
                do
                {
                    v42 = *v41;
                    ++v39;
                    ++v41;
                    v23[v39 - 1] = *(_BYTE *)(v40 + v42);
                }
                while ( v39 < DestWid );
                v28 = SrcX;
                v37 = Flip;
            }
            v35 += (signed int)SrcInfo;
            v23 += Clip;
            ++Mirror;
        }
        while ( Mirror < DestHgt );
    }
}

void TransDibBlt(BITMAPINFO256 *DestInfo, char *DestBits, RECT *ClipRect, int DestX, int DestY, int DestWid, int DestHgt, BITMAPINFO256 *SrcInfo, char *SrcBits, TRANSINFO *TransInfo, int SrcX, int SrcY, int SrcWid, int SrcHgt, int Clip, int Mirror, int Flip, int TransColor)
{
    TRANSINFO *v18; // ebp@1
    int v19; // edi@6
    BITMAPINFO256 *v20; // ebx@6
    int v21; // esi@8
    int v22; // ebx@10
    int v23; // edi@11
    int v24; // ecx@13
    char *v25; // edi@13
    int v26; // edx@14
    void *v27; // eax@15
    int v28; // eax@19
    int v29; // edx@19
    BITMAPINFO256 *v30; // ebp@24
    signed int v31; // eax@25
    signed int v32; // eax@28
    int v33; // ebx@29
    char *v34; // ecx@29
    int v35; // esi@31
    int v36; // edx@32
    RECT *v37; // ebp@33
    int v38; // edx@33
    int v39; // eax@35
    int v40; // esi@41
    _DWORD *v41; // ebx@42
    char v42; // dl@43
    bool v43; // sf@46
    unsigned __int8 v44; // of@46
    signed int v45; // ebx@48
    char *v46; // edx@49
    int v47; // eax@51
    int v48; // ecx@53
    int v49; // eax@53
    _DWORD *v50; // esi@54
    char v51; // dl@55
    int SrcTotHgt; // [sp+10h] [bp-10h]@8
    int sySkip; // [sp+14h] [bp-Ch]@8
    int DestOrien; // [sp+18h] [bp-8h]@8
    int DestTotHgt; // [sp+1Ch] [bp-4h]@8

    v18 = TransInfo;
    if( TransInfo && !TransInfo->AnyTrans )
    {
        DibBlt(
            DestInfo,
            DestBits,
            ClipRect,
            DestX,
            DestY,
            DestWid,
            DestHgt,
            SrcInfo,
            SrcBits,
            SrcX,
            SrcY,
            SrcWid,
            SrcHgt,
            Clip,
            Mirror,
            Flip);
        return;
    }
    if( TransColor < 0 )
        TransColor = 0;
    v19 = Flip;
    v20 = DestInfo;
    if( !Clip
        || ClipDibBlt(DestInfo, ClipRect, &DestX, &DestY, &DestWid, &DestHgt, &SrcX, &SrcY, &SrcWid, &SrcHgt, Mirror, Flip) )
    {
        v21 = (SrcWid << 8) / DestWid;
        sySkip = (SrcHgt << 8) / DestHgt;
        GetDibDim(v20, &Clip, &DestTotHgt, &DestOrien);
        GetDibDim(SrcInfo, (int *)&DestInfo, &SrcTotHgt, &Flip);
        if( v19 )
            Flip = -Flip;
        v22 = DestOrien;
        ClipRect = (RECT *)((DestWid << 8) / SrcWid);
        if( DestOrien == 1 )
            v23 = DestY * Clip;
        else
            v23 = Clip * (DestTotHgt - DestY - 1);
        v24 = SrcX;
        v25 = &DestBits[DestX] + v23;
        if( Mirror )
        {
            if( DestWid - 1 > -1 )
            {
                v28 = 4 * (DestWid - 1) + 6476344;
                v29 = DestWid;
                do
                {
                    v28 -= 4;
                    *(_DWORD *)(v28 + 4) = v24 >> 8;
                    v24 += v21;
                    --v29;
                }
                while ( v29 );
                goto LABEL_21;
            }
        }
        else
        {
            v26 = DestWid;
            if( DestWid > 0 )
            {
                v27 = &SrcXTbl;
                do
                {
                    v27 = (char *)v27 + 4;
                    *((_DWORD *)v27 - 1) = v24 >> 8;
                    v24 += v21;
                    --v26;
                }
                while ( v26 );
LABEL_21:
                v18 = TransInfo;
                goto LABEL_22;
            }
        }
LABEL_22:
        if( !Mirror && v18 && (v30 = (BITMAPINFO256 *)v18->LineInfo, (SrcInfo = v30) != 0) )
        {
            v31 = SrcY << 8;
            Clip *= v22;
            TransInfo = (TRANSINFO *)(SrcY << 8);
            Mirror = 0;
            if( DestHgt > 0 )
            {
                while ( 1 )
                {
                    v32 = v31 >> 8;
                    if( Flip == 1 )
                    {
                        v33 = SrcX;
                        v34 = &SrcBits[SrcX] + (_DWORD)DestInfo * v32;
                    }
                    else
                    {
                        v33 = SrcX;
                        v34 = &SrcBits[SrcX] + (_DWORD)DestInfo * (SrcTotHgt - v32 - 1);
                    }
                    v35 = (int)v30 + 16 * v32;
                    if( !*(_DWORD *)v35 )
                    {
                        v36 = *(_DWORD *)(v35 + 8);
                        if( v36 >= v33 )
                        {
                            v37 = ClipRect;
                            v38 = (signed int)ClipRect * (v36 - v33) >> 8;
                        }
                        else
                        {
                            v37 = ClipRect;
                            v38 = 0;
                        }
                        v39 = (signed int)v37 * (*(_DWORD *)(v35 + 12) - v33 + 1) >> 8;
                        if( v39 > DestWid )
                            v39 = DestWid;
                        if( v39 > v38 )
                        {
                            if( v37 == (RECT *)256 && *(_DWORD *)(v35 + 4) )
                            {
                                memcpy(&v25[v38], &v34[v38], v39 - v38);
                            }
                            else
                            {
                                v40 = v38;
                                if( v38 < v39 )
                                {
                                    v41 = (_DWORD *)(4 * v38 + 6476344);
                                    do
                                    {
                                        v42 = v34[*v41];
                                        //LOBYTE(DestBits) = v34[*v41];
                                        //if( (unsigned __int8)DestBits != TransColor )
                                            //v25[v40] = v42;
                                        ++v40;
                                        ++v41;
                                    }
                                    while ( v40 < v39 );
                                }
                            }
                        }
                    }
                    v25 += Clip;
                    v31 = (signed int)&TransInfo->AnyTrans + sySkip;
                    v44 = __OFSUB__(Mirror + 1, DestHgt);
                    v43 = Mirror + 1 - DestHgt < 0;
                    TransInfo = (TRANSINFO *)((char *)TransInfo + sySkip);
                    ++Mirror;
                    if( !(v43 ^ v44) )
                        break;
                    v30 = SrcInfo;
                }
            }
        }
        else
        {
            Clip *= v22;
            Mirror = 0;
            v45 = SrcY << 8;
            if( DestHgt > 0 )
            {
                v46 = SrcBits;
                do
                {
                    if( Flip == 1 )
                        v47 = v45 >> 8;
                    else
                        v47 = SrcTotHgt - (v45 >> 8) - 1;
                    v48 = 0;
                    v49 = (int)(&v46[SrcX] + (_DWORD)DestInfo * v47);
                    if( DestWid > 0 )
                    {
                        //v50 = &SrcXTbl;
                        do
                        {
                            v51 = *(_BYTE *)(v49 + *v50);
                            //LOBYTE(DestBits) = *(_BYTE *)(v49 + *v50);
                            //if( (unsigned __int8)DestBits != TransColor )
                                //v25[v48] = v51;
                            ++v48;
                            ++v50;
                        }
                        while ( v48 < DestWid );
                        v46 = SrcBits;
                    }
                    v25 += Clip;
                    v45 += sySkip;
                    ++Mirror;
                }
                while ( Mirror < DestHgt );
            }
        }
    }
}

int ClipDibBlt(BITMAPINFO256 *DestInfo, RECT *ClipRect, int *DestX, int *DestY, int *DestWid, int *DestHgt, int *SrcX, int *SrcY, int *SrcWid, int *SrcHgt, int Mirror, int Flip)
{
    int v16; // eax@6
    int v17; // edi@6
    int v18; // ebp@8
    int v19; // ecx@9
    int v20; // ebp@12
    int *v21; // eax@13
    int v22; // ecx@13
    int v23; // edx@17
    int *v24; // esi@18
    int v25; // ecx@18
    int v26; // ecx@22
    int *v27; // ebx@23
    int v28; // ecx@23
    int v29; // ecx@23
    int v30; // ecx@26
    int v31; // ecx@27
    int *v32; // edx@27
    int v33; // ecx@27
    int result; // eax@34
    int ey; // [sp+10h] [bp-4h]@6
    BITMAPINFO256 *DestInfoa; // [sp+18h] [bp+4h]@6
    int ex; // [sp+1Ch] [bp+8h]@12

    int v12;
    int v13;
    int v14;
    int v15;

    if( ClipRect )
    {
        v12 = ClipRect->left;
        v13 = ClipRect->top;
        v14 = ClipRect->right + 1;
        v15 = ClipRect->bottom + 1;
    }
    else
    {
        v12 = 0;
        v13 = 0;
        v14 = DestInfo->bmiHeader.biWidth;
        v15 = DestInfo->bmiHeader.biHeight;
    }
    if( v15 < 0 )
        v15 = -v15;
    v16 = v15 - 1;
    DestInfoa = (BITMAPINFO256 *)(v14 - 1);
    v17 = *DestX;
    ey = v16;
    if( *DestX > v14 - 1 )
        goto LABEL_38;
    if( *DestY > v16 )
        goto LABEL_38;
    v18 = *DestWid;
    if( *DestWid + v17 - 1 < v12 )
        goto LABEL_38;
    v19 = *DestHgt;
    if( *DestHgt + *DestY - 1 < v13 || v18 < 1 || v19 < 1 )
        goto LABEL_38;
    v20 = (*SrcWid << 8) / v18;
    ex = (*SrcHgt << 8) / v19;
    if( v17 >= v12 )
    {
        v21 = DestWid;
    }
    else
    {
        *DestX = v12;
        v21 = DestWid;
        *DestWid -= v12 - v17;
        v22 = v20 * ((v12 - v17) << 8) >> 16;
        if( !Mirror )
            *SrcX += v22;
        *SrcWid -= v22;
    }
    v23 = *DestY;
    if( *DestY >= v13 )
    {
        v24 = DestHgt;
    }
    else
    {
        *DestY = v13;
        v24 = DestHgt;
        *DestHgt -= v13 - v23;
        v25 = ex * ((v13 - v23) << 8) >> 16;
        if( !Flip )
            *SrcY += v25;
        *SrcHgt -= v25;
    }
    v26 = *v21 + *DestX;
    if( v26 - 1 <= (signed int)DestInfoa )
    {
        v27 = SrcWid;
    }
    else
    {
        v27 = SrcWid;
        v28 = v26 - (_DWORD)DestInfoa - 1;
        *v21 -= v28;
        v29 = v20 * (v28 << 8) >> 16;
        *v27 -= v29;
        if( Mirror )
            *SrcX += v29;
    }
    v30 = *v24 + *DestY;
    if( v30 - 1 <= ey )
    {
        v32 = SrcHgt;
    }
    else
    {
        v31 = v30 - ey - 1;
        *v24 -= v31;
        v32 = SrcHgt;
        v33 = ex * (v31 << 8) >> 16;
        *SrcHgt -= v33;
        if( Flip )
            *SrcY += v33;
    }
    if( *v21 < 1 || *v24 < 1 || *v27 < 1 || *v32 < 1 )
LABEL_38:
        result = 0;
    else
        result = 1;
    return result;
}

void GetDibDim(BITMAPINFO256 *Info, int *TotWid, int *TotHgt, int *Orien)
{
    int v4; // eax@1

    *TotWid = (Info->bmiHeader.biWidth + 3) & 0xFFFFFFFC;
    v4 = Info->bmiHeader.biHeight;
    *TotHgt = v4;
    if( v4 >= 0 )
    {
        *Orien = -1;
    }
    else
    {
        *TotHgt = -v4;
        *Orien = 1;
    }
}

int TileDibBlt(BITMAPINFO256 *DestInfo, char *DestBits, RECT *ClipRect, int DestX, int DestY, int DestWid, int DestHgt, int BlockWid, int BlockHgt, BITMAPINFO256 *SrcInfo, char *SrcBits, TRANSINFO *TransInfo, int SrcX, int SrcY, int SrcWid, int SrcHgt, int Trans, int Mirror, int Flip)
{
    int v19; // ecx@1
    int v20; // esi@1
    int v21; // edx@1
    int v22; // ebx@3
    int v23; // eax@11
    int v24; // edi@11
    int v25; // ecx@11
    int v26; // esi@11
    int v27; // ebx@11
    int v28; // esi@11
    int v29; // ecx@11
    int v30; // edi@11
    int v31; // eax@13
    int v32; // eax@14
    int v33; // ebx@16
    int v34; // edx@19
    int v35; // eax@20
    int v36; // ebx@21
    int v37; // ebp@21
    int v38; // eax@23
    int v39; // edi@23
    int v40; // eax@25
    int v41; // eax@30
    bool v42; // zf@36
    int v44; // ebx@39
    int v45; // eax@41
    int v46; // edi@41
    int v47; // eax@43
    int v48; // eax@48
    int SrcBotHgt; // [sp+10h] [bp-1Ch]@11
    int SrcRtWid; // [sp+14h] [bp-18h]@11
    int DestBotHgt; // [sp+18h] [bp-14h]@11
    int SrcTopHgt; // [sp+1Ch] [bp-10h]@11
    int SrcLtWid; // [sp+20h] [bp-Ch]@11
    int v54; // [sp+24h] [bp-8h]@11
    int v55; // [sp+28h] [bp-4h]@11
    int DestYa; // [sp+40h] [bp+14h]@41
    int DestY1; // [sp+44h] [bp+18h]@13
    int xBlocks; // [sp+48h] [bp+1Ch]@16
    TRANSINFO *TransInfoa; // [sp+5Ch] [bp+30h]@38
    signed int SrcWida; // [sp+68h] [bp+3Ch]@1
    signed int sxSkip; // [sp+6Ch] [bp+40h]@1
    int sxSkipa; // [sp+6Ch] [bp+40h]@11
    int sySkip; // [sp+70h] [bp+44h]@21
    int sySkipa; // [sp+70h] [bp+44h]@39
    int Mirrora; // [sp+74h] [bp+48h]@24
    int Flipa; // [sp+78h] [bp+4Ch]@23
    int Flipb; // [sp+78h] [bp+4Ch]@42

    v19 = SrcWid;
    v20 = SrcHgt;
    SrcWida = (SrcWid << 8) / BlockWid;
    v21 = SrcX;
    sxSkip = (SrcHgt << 8) / BlockHgt;
    if( SrcX < 0 )
    {
        v21 = v19 + SrcX;
        SrcX += v19;
    }
    v22 = SrcY;
    if( SrcY < 0 )
    {
        v22 = v20 + SrcY;
        SrcY += v20;
    }
    if( v21 >= v19 )
    {
        do
            v21 -= v19;
        while ( v21 >= v19 );
        SrcX = v21;
    }
    if( v22 >= v20 )
    {
        do
            v22 -= v20;
        while ( v22 >= v20 );
        SrcY = v22;
    }
    v23 = v19 - v21;
    v24 = v20 - v22;
    v25 = v19 - (v19 - v21);
    SrcRtWid = v23;
    v26 = v20 - (v20 - v22);
    v55 = v21 - v25;
    SrcTopHgt = v26;
    SrcBotHgt = v24;
    SrcLtWid = v25;
    v54 = v22 - v26;
    v27 = DestWid;
    v28 = (v23 << 16) / SrcWida >> 8;
    v29 = BlockWid - v28;
    v30 = (v24 << 16) / sxSkip >> 8;
    sxSkipa = v30;
    DestBotHgt = BlockHgt - v30;
    if( BlockWid >= DestWid && BlockHgt >= DestHgt )
    {
        v31 = 1;
        DestY1 = 1;
LABEL_18:
        xBlocks = v31;
        goto LABEL_19;
    }
    v32 = DestWid / BlockWid;
    DestY1 = DestWid / BlockWid;
    if( BlockWid * (v27 / BlockWid) < v27 )
        DestY1 = v32 + 1;
    v33 = DestHgt;
    xBlocks = DestHgt / BlockHgt;
    if( BlockHgt * xBlocks < v33 )
    {
        v31 = xBlocks + 1;
        goto LABEL_18;
    }
LABEL_19:
    v34 = DestY;
    if( !Trans )
    {
        v35 = xBlocks;
        TransInfoa = (TRANSINFO *)DestY;
        if( xBlocks > 0 )
        {
            v44 = Flip;
            sySkipa = xBlocks;
            while ( 1 )
            {
                v45 = v34 + v30;
                v46 = DestX;
                DestYa = v45;
                if( DestY1 > 0 )
                {
                    Flipb = DestY1;
                    do
                    {
                        v47 = sxSkipa;
                        if( sxSkipa )
                        {
                            if( v28 )
                            {
                                DibBlt(
                                    DestInfo,
                                    DestBits,
                                    ClipRect,
                                    v46,
                                    v34,
                                    v28,
                                    sxSkipa,
                                    SrcInfo,
                                    SrcBits,
                                    SrcX,
                                    SrcY,
                                    SrcRtWid,
                                    SrcBotHgt,
                                    1,
                                    Mirror,
                                    v44);
                                v29 = BlockWid - v28;
                                v47 = sxSkipa;
                            }
                            if( v29 )
                            {
                                DibBlt(
                                    DestInfo,
                                    DestBits,
                                    ClipRect,
                                    v46 + v28,
                                    (int)TransInfoa,
                                    v29,
                                    v47,
                                    SrcInfo,
                                    SrcBits,
                                    v55,
                                    SrcY,
                                    SrcLtWid,
                                    SrcBotHgt,
                                    1,
                                    Mirror,
                                    v44);
                                v29 = BlockWid - v28;
                            }
                        }
                        v48 = DestBotHgt;
                        if( DestBotHgt )
                        {
                            if( v28 )
                            {
                                DibBlt(
                                    DestInfo,
                                    DestBits,
                                    ClipRect,
                                    v46,
                                    DestYa,
                                    v28,
                                    DestBotHgt,
                                    SrcInfo,
                                    SrcBits,
                                    SrcX,
                                    v54,
                                    SrcRtWid,
                                    SrcTopHgt,
                                    1,
                                    Mirror,
                                    v44);
                                v29 = BlockWid - v28;
                                v48 = DestBotHgt;
                            }
                            if( v29 )
                            {
                                DibBlt(
                                    DestInfo,
                                    DestBits,
                                    ClipRect,
                                    v46 + v28,
                                    DestYa,
                                    v29,
                                    v48,
                                    SrcInfo,
                                    SrcBits,
                                    v55,
                                    v54,
                                    SrcLtWid,
                                    SrcTopHgt,
                                    1,
                                    Mirror,
                                    v44);
                                v29 = BlockWid - v28;
                            }
                        }
                        v46 += BlockWid;
                        v34 = (int)TransInfoa;
                        --Flipb;
                    }
                    while ( Flipb );
                }
                v34 += BlockHgt;
                v42 = sySkipa == 1;
                TransInfoa = (TRANSINFO *)v34;
                --sySkipa;
                if( v42 )
                    break;
                v30 = sxSkipa;
            }
            v35 = xBlocks;
        }
        return DestY1 * v35;
    }
    v35 = xBlocks;
    if( xBlocks <= 0 )
        return DestY1 * v35;
    v36 = Flip;
    v37 = Mirror;
    sySkip = xBlocks;
    while ( 1 )
    {
        v38 = v34 + v30;
        v39 = DestX;
        Flipa = v38;
        if( DestY1 > 0 )
        {
            Mirrora = DestY1;
            do
            {
                v40 = sxSkipa;
                if( sxSkipa )
                {
                    if( v28 )
                    {
                        TransDibBlt(
                            DestInfo,
                            DestBits,
                            ClipRect,
                            v39,
                            v34,
                            v28,
                            sxSkipa,
                            SrcInfo,
                            SrcBits,
                            TransInfo,
                            SrcX,
                            SrcY,
                            SrcRtWid,
                            SrcBotHgt,
                            1,
                            v37,
                            v36,
                            0);
                        v29 = BlockWid - v28;
                        v40 = sxSkipa;
                    }
                    if( v29 )
                    {
                        TransDibBlt(
                            DestInfo,
                            DestBits,
                            ClipRect,
                            v39 + v28,
                            DestY,
                            v29,
                            v40,
                            SrcInfo,
                            SrcBits,
                            TransInfo,
                            v55,
                            SrcY,
                            SrcLtWid,
                            SrcBotHgt,
                            1,
                            v37,
                            v36,
                            0);
                        v29 = BlockWid - v28;
                    }
                }
                v41 = DestBotHgt;
                if( DestBotHgt )
                {
                    if( v28 )
                    {
                        TransDibBlt(
                            DestInfo,
                            DestBits,
                            ClipRect,
                            v39,
                            Flipa,
                            v28,
                            DestBotHgt,
                            SrcInfo,
                            SrcBits,
                            TransInfo,
                            SrcX,
                            v54,
                            SrcRtWid,
                            SrcTopHgt,
                            1,
                            v37,
                            v36,
                            0);
                        v29 = BlockWid - v28;
                        v41 = DestBotHgt;
                    }
                    if( v29 )
                    {
                        TransDibBlt(
                            DestInfo,
                            DestBits,
                            ClipRect,
                            v39 + v28,
                            Flipa,
                            v29,
                            v41,
                            SrcInfo,
                            SrcBits,
                            TransInfo,
                            v55,
                            v54,
                            SrcLtWid,
                            SrcTopHgt,
                            1,
                            v37,
                            v36,
                            0);
                        v29 = BlockWid - v28;
                    }
                }
                v39 += BlockWid;
                v34 = DestY;
                --Mirrora;
            }
            while ( Mirrora );
        }
        v34 += BlockHgt;
        v42 = sySkip == 1;
        DestY = v34;
        --sySkip;
        if( v42 )
            break;
        v30 = sxSkipa;
    }
    return DestY1 * xBlocks;
}

int DibCheckTrans(BITMAPINFO256 *DibInfo, TRANSINFO *TransInfo, char *DibBits)
{
    int v3; // ebx@1
    LINEINFO *v4; // eax@1
    TRANSINFO *v5; // edx@1
    int result; // eax@2
    int v7; // eax@3
    int v8; // esi@3
    BITMAPINFO256 *v9; // ecx@3
    int v10; // ebp@4
    int v11; // esi@6
    int v12; // eax@7
    int v13; // edi@9
    char *v14; // eax@9
    int i; // ecx@9
    int v16; // edx@16
    int j; // ecx@17
    signed int v18; // ebx@21
    int v19; // ecx@22
    int h; // [sp+8h] [bp-14h]@1
    int AnyTrans; // [sp+Ch] [bp-10h]@3
    int tw; // [sp+10h] [bp-Ch]@1
    int w; // [sp+14h] [bp-8h]@1
    int orien; // [sp+18h] [bp-4h]@1
    BITMAPINFO256 *DibInfoa; // [sp+20h] [bp+4h]@3

    GetDibDim(DibInfo, &tw, &h, &orien);
    v3 = DibInfo->bmiHeader.biWidth;
    w = DibInfo->bmiHeader.biWidth;
    v4 = (LINEINFO *)malloc(16 * h);
    v5 = TransInfo;
    TransInfo->LineInfo = v4;
    if( v4 )
    {
        v7 = h;
        v8 = 0;
        v9 = 0;
        AnyTrans = 0;
        DibInfoa = 0;
        if( h > 0 )
        {
            v10 = 0;
            while ( 1 )
            {
                v11 = 1;
                if( orien == 1 )
                    v12 = (_DWORD)v9 * tw;
                else
                    v12 = tw * (v7 - (_DWORD)v9 - 1);
                v13 = v3;
                v14 = &DibBits[v12];
                for ( i = 0; i < v3; ++i )
                {
                    if( v14[i] )
                    {
                        if( v11 )
                        {
                            v11 = 0;
                            v13 = i;
                        }
                    }
                    else if( !AnyTrans )
                    {
                        AnyTrans = 1;
                    }
                }
                v16 = v13;
                if( !v11 )
                {
                    for ( j = v13 + 1; j < v3; ++j )
                    {
                        if( v14[j] )
                            v16 = j;
                    }
                }
                v18 = 1;
                if( !v11 )
                {
                    v19 = v13;
                    if( v13 <= v16 )
                    {
                        while ( v14[v19] )
                        {
                            if( ++v19 > v16 )
                                goto LABEL_27;
                        }
                        v18 = 0;
                    }
                }
LABEL_27:
                ++v10;
                TransInfo->LineInfo[v10 - 1].AllTrans = v11;
                *((_DWORD *)&TransInfo->LineInfo[v10] - 3) = v18;
                *((_DWORD *)&TransInfo->LineInfo[v10] - 2) = v13;
                *((_DWORD *)&TransInfo->LineInfo[v10] - 1) = v16;
                v7 = h;
                DibInfoa = (BITMAPINFO256 *)((char *)DibInfoa + 1);
                if( (signed int)DibInfoa >= h )
                    break;
                v3 = w;
                v9 = DibInfoa;
            }
            v5 = TransInfo;
            v8 = AnyTrans;
        }
        v5->AnyTrans = v8;
        if( !v8 )
            free(v5->LineInfo);
        result = v8;
    }
    else
    {
        result = 1;
    }
    return result;
}

BITMAPINFOHEADER *GetPaletteFromDib(char *FileName, int MakeIdentity)
{
    BITMAPINFOHEADER *result = DibOpenFile(FileName);
    BITMAPINFOHEADER *v3 = result;
    if( result )
    {
        void *v4 = DibCreatePalette(result);
        if( MakeIdentity )
            CreateIdentityPalette(v4);
        DibFree(v3);
        result = (BITMAPINFOHEADER *)v4;
    }
    return result;
}

void *ReadPalette(char *FileName, int ResourceId, int MakeIdentity)
{
    __int32 v3; // ebp@1
    int v4; // eax@4
    int v5; // esi@4
    __int32 v6; // ebx@5
    char *v7; // edi@5
    char *v8; // esi@10
    void *result; // eax@14
    char *v10; // eax@17
    __int32 v11; // eax@18
    __int32 v12; // ebx@18
    LOGPALETTE *v13; // eax@18
    LOGPALETTE *v14; // edi@18
    int v15; // esi@18
    int v16; // esi@20
    char *v17; // eax@21
    char *v18; // eax@22
    char *v19; // eax@23
    struct PAL_TABLE *v20; // eax@30
    void *v21; // ecx@31
    char v22; // dl@32
    TDrawSystem *v23; // eax@35
    char *data; // [sp+10h] [bp-10h]@1
    int own_mem; // [sp+14h] [bp-Ch]@1
    void *hpal; // [sp+18h] [bp-8h]@1
    int resDataSize; // [sp+1Ch] [bp-4h]@10

    v3 = 0;
    data = 0;
    own_mem = -1;
    hpal = 0;
    if( FileName )
    {
        if( *FileName )
        {
            if( shape_file_first )
            {
                v4 = _open(FileName, 0x8000);
                v5 = v4;
                if( v4 != -1 )
                {
                    lseek(v4, 0, 2);
                    v6 = _tell(v5);
                    v7 = (char *)malloc(v6);
                    data = v7;
                    if( v7 )
                    {
                        lseek(v5, 0, 0);
                        read(v5, v7, v6);
                        own_mem = 1;
                    }
                    _close(v5);
                }
            }
        }
    }
    if( !data && ResourceId != -1 )
    {
        v8 = RESFILE_load(0x62696E61u, ResourceId, &own_mem, &resDataSize);
        if( own_mem )
        {
            data = v8;
        }
        else
        {
            data = (char *)malloc(resDataSize);
            memcpy(data, v8, resDataSize);
            own_mem = 1;
        }
    }
    if( data )
    {
        //LOWORD(FileName) = *(_WORD *)asc_5837C4;
        //BYTE2(FileName) = byte_5837C6;
        if( strtok(data, (const char *)&FileName) )
        {
            if( strtok(0, (const char *)&FileName) )
            {
                v10 = strtok(0, (const char *)&FileName);
                if( v10 )
                {
                    v11 = atol(v10);
                    v12 = v11;
                    v13 = (LOGPALETTE *)malloc(4 * v11 + 8);
                    v14 = v13;
                    v15 = 0;
                    ResourceId = 0;
                    if( v13 )
                    {
                        v13->palNumEntries = v12;
                        v13->palVersion = 768;
                        if( v12 > 0 )
                        {
                            v16 = (int)&v13->palPalEntry[0].peGreen;
                            do
                            {
                                v17 = strtok(0, (const char *)&FileName);
                                if( !v17 )
                                    break;
                                *(_BYTE *)(v16 - 1) = atoi(v17);
                                v18 = strtok(0, (const char *)&FileName);
                                if( !v18 )
                                    break;
                                *(_BYTE *)v16 = atoi(v18);
                                v19 = strtok(0, (const char *)&FileName);
                                if( !v19 )
                                    break;
                                *(_BYTE *)(v16 + 1) = atoi(v19);
                                *(_BYTE *)(v16 + 2) = 0;
                                if( v3 == v12 - 1 )
                                    ResourceId = 1;
                                ++v3;
                                v16 += 4;
                            }
                            while ( v3 < v12 );
                            v15 = ResourceId;
                        }
                        if( v15 )
                        {
                            if( v12 == 256 )
                            {
                                v20 = System_color_Table;
                                if( (signed int)System_color_Table >= 0 )
                                {
                                    v21 = &unk_5841E5;
                                    do
                                    {
                                        v22 = *((char *)v21 - 1);
                                        v21 = (char *)v21 + 8;
                                        v14->palPalEntry[(_DWORD)v20].peRed = v22;
                                        v14->palPalEntry[(_DWORD)v20].peGreen = *((char *)v21 - 8);
                                        v14->palPalEntry[(_DWORD)v20].peBlue = *((char *)v21 - 7);
                                        v14->palPalEntry[(_DWORD)v20].peFlags = 0;
                                        v20 = *(struct PAL_TABLE **)((char *)v21 - 5);
                                    }
                                    while ( (signed int)v20 >= 0 );
                                }
                            }
                            if( v15 )
                            {
                                hpal = CreatePalette(v14);
                                if( MakeIdentity )
                                {
                                    v23 = rge_base_game->draw_system;
                                    if( v23->DrawType == 1 || v23->ScreenMode == 1 )
                                        CreateIdentityPalette(hpal);
                                }
                            }
                        }
                        free((void *)v14);
                    }
                }
            }
        }
        if( own_mem == 1 )
            free(data);
        result = hpal;
    }
    else
    {
        result = 0;
    }
    return result;
}

BITMAPINFOHEADER *DibOpenFile(char *szFile)
{
    int v1; // esi@1
    HMODULE v2; // eax@2
    HRSRC v3; // eax@2
    HRSRC *v4; // ST08_4@3
    HMODULE v5; // eax@3
    HGLOBAL v6; // eax@3
    BITMAPINFOHEADER *result; // eax@3
    BITMAPINFOHEADER *v8; // esi@5
    unsigned int v9; // eax@6
    unsigned __int16 v10; // cx@7
    SIZE_T v11; // edi@9
    HGLOBAL v12; // eax@9
    HGLOBAL v13; // eax@9
    HGLOBAL v14; // eax@9
    BITMAPINFOHEADER *v15; // eax@9
    HGLOBAL v16; // eax@10
    HGLOBAL v17; // eax@10
    BITMAPINFOHEADER *v18; // esi@10
    signed int v19; // eax@13
    unsigned __int16 v20; // cx@14
    int fh; // [sp+10h] [bp-90h]@1
    __int32 dwBits; // [sp+14h] [bp-8Ch]@6
    struct _OFSTRUCT ReOpenBuff; // [sp+18h] [bp-88h]@1

    v1 = OpenFile(szFile, &ReOpenBuff, 0);
    fh = v1;
    if( v1 == -1 )
    {
        v2 = GetModuleHandleA(0);
        v3 = FindResourceA(v2, szFile, (LPCSTR)2);
        if( v3 )
        {
            *v4 = v3;
            v5 = GetModuleHandleA(0);
            v6 = LoadResource(v5, *v4);
            result = (BITMAPINFOHEADER *)LockResource(v6);
        }
        else
        {
            result = 0;
        }
    }
    else
    {
        result = DibReadBitmapInfo(v1);
        v8 = result;
        if( result )
        {
            v9 = result->biClrUsed;
            dwBits = v8->biSizeImage;
            if( !v9 )
            {
                v10 = v8->biBitCount;
                if( v10 <= 8u )
                    v9 = 1 << v10;
            }
            v11 = v8->biSize + v8->biSizeImage + 4 * v9;
            v12 = GlobalHandle(v8);
            GlobalUnlock(v12);
            v13 = GlobalHandle(v8);
            v14 = GlobalReAlloc(v13, v11, 0);
            v15 = (BITMAPINFOHEADER *)GlobalLock(v14);
            if( v15 )
            {
                v18 = v15;
            }
            else
            {
                v16 = GlobalHandle(v8);
                GlobalUnlock(v16);
                v17 = GlobalHandle(v8);
                GlobalFree(v17);
                v18 = 0;
            }
            if( v18 )
            {
                v19 = v18->biClrUsed;
                if( !v19 )
                {
                    v20 = v18->biBitCount;
                    if( v20 <= 8u )
                        v19 = 1 << v20;
                }
                _hread(fh, (char *)v18 + 4 * v19 + v18->biSize, dwBits);
            }
            _lclose(fh);
            result = v18;
        }
    }
    return result;
}

char *ReadDibBits(char *szFile)
{
    BITMAPINFOHEADER *BitMapInfo1;
    BITMAPINFOHEADER *BitMapInfo2;
    char *v1;
    HFILE hFile;
    char *v10;
    struct _OFSTRUCT ReOpenBuff;

    v1 = 0;
    hFile = OpenFile(szFile, &ReOpenBuff, 0);
    if( hFile != -1 )
    {
        BitMapInfo1 = DibReadBitmapInfo(hFile);
        BitMapInfo2 = BitMapInfo1;
        if( BitMapInfo1 )
        {
            GlobalUnlock(GlobalHandle(BitMapInfo1));
            GlobalFree(GlobalHandle(BitMapInfo2));
            v10 = new char[BitMapInfo1->biSizeImage];
            v1 = v10;
            if( v10 )
                _hread(hFile, v10, BitMapInfo1->biSizeImage);
        }
        _lclose(hFile);
        return v1;
    }
    else
    {
        return 0;
    }
}

BITMAPINFOHEADER *DibWriteClipped(BITMAPINFOHEADER *pDIB, char *szFile, int x, int y, int w, int h)
{
    BITMAPINFOHEADER *result; // eax@1
    BITMAPINFO256 *v7; // esi@1
    unsigned int v8; // eax@2
    unsigned __int16 v9; // cx@3
    char *v10; // ecx@6
    char *v11; // eax@9

    result = DibCreate(8, w, h);
    v7 = (BITMAPINFO256 *)result;
    if( result )
    {
        v8 = pDIB->biClrUsed;
        if( !v8 )
        {
            v9 = pDIB->biBitCount;
            if( v9 <= 8u )
                v8 = 1 << v9;
        }
        memcpy((char *)v7 + v7->bmiHeader.biSize, (char *)pDIB + pDIB->biSize, 4 * v8);
        if( pDIB->biCompression == 3 )
            v10 = (char *)&pDIB->biPlanes + pDIB->biSize;
        else
            v10 = (char *)pDIB + 4 * pDIB->biClrUsed + pDIB->biSize;
        if( v7->bmiHeader.biCompression == 3 )
            v11 = (char *)&v7->bmiHeader.biPlanes + v7->bmiHeader.biSize;
        else
            v11 = (char *)v7 + 4 * v7->bmiHeader.biClrUsed + v7->bmiHeader.biSize;
        DibBlt(v7, v11, 0, 0, 0, w, h, (BITMAPINFO256 *)pDIB, v10, x, y, w, h, 1, 0, 0);
        DibWriteFile(&v7->bmiHeader, szFile);
        DibFree(&v7->bmiHeader);
        result = (BITMAPINFOHEADER *)1;
    }
    return result;
}

int DibWriteFile(BITMAPINFOHEADER *pdib, char *szFile)
{
    int result; // eax@2
    HFILE v3; // ebp@3
    unsigned int v4; // eax@5
    unsigned int v5; // ecx@5
    unsigned int v6; // edx@5
    __int32 v7; // esi@5
    unsigned __int16 v8; // cx@6
    tagBITMAPFILEHEADER hdr; // [sp+Ch] [bp-98h]@5
    struct _OFSTRUCT ReOpenBuff; // [sp+1Ch] [bp-88h]@3

    if( pdib )
    {
        v3 = OpenFile(szFile, &ReOpenBuff, 0x1002u);
        if( v3 == -1 )
        {
            result = 0;
        }
        else
        {
            v4 = pdib->biClrUsed;
            v5 = pdib->biSizeImage;
            v6 = pdib->biSize;
            hdr.bfType = 19778;
            hdr.bfReserved1 = 0;
            v7 = v6 + v5 + 4 * v4;
            hdr.bfReserved2 = 0;
            hdr.bfSize = v7 + 14;
            if( !v4 )
            {
                v8 = pdib->biBitCount;
                if( v8 <= 8u )
                    v4 = 1 << v8;
            }
            hdr.bfOffBits = v6 + 4 * v4 + 14;
            _lwrite(v3, (LPCCH)&hdr, 0xEu);
            _hwrite(v3, (LPCCH)pdib, v7);
            _lclose(v3);
            result = 1;
        }
    }
    else
    {
        result = 0;
    }
    return result;
}

void *DibCreatePalette(BITMAPINFOHEADER *pdib)
{
    signed int v2; // edi@3
    unsigned __int16 v3; // cx@4
    char *v4; // esi@10
    LOGPALETTE *v5; // eax@10
    LOGPALETTE *v6; // ebp@10
    int v7; // eax@12
    char v8; // cl@13
    HPALETTE v9; // ST18_4@14
    HDC v10; // esi@15
    HPALETTE hpal; // [sp+8h] [bp-4h]@1

    hpal = 0;
    if( !pdib )
        return 0;
    v2 = pdib->biClrUsed;
    if( !v2 )
    {
        v3 = pdib->biBitCount;
        if( v3 <= 8u )
            v2 = 1 << v3;
    }
    if( v2 == 3 && pdib->biCompression == 3 )
        v2 = 0;
    if( v2 <= 0 )
    {
        v10 = GetDC(0);
        hpal = CreateHalftonePalette(v10);
        ReleaseDC(0, v10);
        return hpal;
    }
    v4 = (char *)pdib + pdib->biSize;
    v5 = (LOGPALETTE *)LocalAlloc(0x40u, 4 * v2 + 8);
    v6 = v5;
    if( !v5 )
        return hpal;
    v5->palNumEntries = v2;
    v5->palVersion = 768;
    if( v2 > 0 )
    {
        v7 = (int)&v5->palPalEntry[0].peGreen;
        do
        {
            v8 = v4[2];
            v4 += 4;
            *(_BYTE *)(v7 - 1) = v8;
            *(_BYTE *)v7 = *(v4 - 3);
            *(_BYTE *)(v7 + 1) = *(v4 - 4);
            *(_BYTE *)(v7 + 2) = 0;
            v7 += 4;
            --v2;
        }
        while ( v2 );
    }
    v9 = CreatePalette(v6);
    LocalFree((HLOCAL)v6);
    return v9;
}

BITMAPINFOHEADER *DibReadBitmapInfo(int fh)
{
    int v1; // ebx@1
    BITMAPINFOHEADER *result; // eax@2
    LONG v3; // ebp@3
    unsigned int v4; // eax@9
    unsigned __int16 bc_8; // ST30_2@10
    unsigned __int16 v6; // dx@10
    unsigned __int16 v7; // ax@10
    unsigned int v8; // ebp@13
    HGLOBAL v9; // eax@20
    char *v10; // esi@22
    int v11; // edx@24
    int v12; // eax@25
    int *v13; // ecx@25
    unsigned int v14; // esi@25
    int v15; // eax@25
    char v16; // dl@26
    BITMAPINFOHEADER *pdib; // [sp+10h] [bp-50h]@20
    unsigned int off; // [sp+18h] [bp-48h]@3
    tagBITMAPFILEHEADER bf; // [sp+28h] [bp-38h]@3
    BITMAPINFOHEADER bi; // [sp+38h] [bp-28h]@7
    int fha; // [sp+64h] [bp+4h]@9
    int fhb; // [sp+64h] [bp+4h]@25

    v1 = fh;
    if( fh == -1 )
    {
        result = 0;
    }
    else
    {
        v3 = _llseek(fh, 0, 1);
        off = v3;
        if( _lread(fh, &bf, 0xEu) == 14 )
        {
            if( bf.bfType != 19778 )
            {
                bf.bfOffBits = 0;
                _llseek(fh, v3, 0);
            }
            if( _lread(fh, &bi, 0x28u) == 40 )
            {
                v4 = bi.biSize;
                fha = bi.biSize;
                if( bi.biSize == 12 )
                {
                    bc_8 = bi.biHeight;
                    v6 = HIWORD(bi.biWidth);
                    bi.biWidth = LOWORD(bi.biWidth);
                    v7 = HIWORD(bi.biHeight);
                    bi.biSize = 40;
                    bi.biHeight = v6;
                    bi.biPlanes = bc_8;
                    bi.biBitCount = v7;
                    bi.biCompression = 0;
                    bi.biSizeImage = 0;
                    bi.biXPelsPerMeter = 0;
                    bi.biYPelsPerMeter = 0;
                    bi.biClrUsed = 0;
                    bi.biClrImportant = 0;
                    _llseek(v1, -28, 1);
                    v4 = bi.biSize;
                }
                if( bi.biClrUsed || bi.biBitCount > 8u )
                    v8 = bi.biClrUsed;
                else
                    v8 = 1 << SLOBYTE(bi.biBitCount);
                if( !bi.biSizeImage )
                    bi.biSizeImage = bi.biHeight * ((((unsigned int)bi.biBitCount * bi.biWidth + 31) >> 3) & 0x1FFFFFFC);
                if( !bi.biClrUsed && bi.biBitCount <= 8u )
                    bi.biClrUsed = 1 << SLOBYTE(bi.biBitCount);
                v9 = GlobalAlloc(2u, 4 * v8 + v4);
                result = (BITMAPINFOHEADER *)GlobalLock(v9);
                pdib = result;
                if( result )
                {
                    memcpy(result, &bi, sizeof(BITMAPINFOHEADER));
                    v10 = (char *)result + result->biSize;
                    if( v8 )
                    {
                        if( fha == 12 )
                        {
                            _lread(v1, v10, 3 * v8);
                            v11 = v8 - 1;
                            if( ((v8 - 1) & 0x80000000) == 0 )
                            {
                                v12 = (int)&v10[2 * v11];
                                v13 = (int *)&v10[4 * v11];
                                BYTE3(fhb) = 0;
                                v14 = v8;
                                v15 = v11 + v12 + 1;
                                do
                                {
                                    v16 = *(_BYTE *)(v15 + 1);
                                    v15 -= 3;
                                    /*
                                    BYTE2(fhb) = v16;
                                    LOBYTE(fhb) = *(_BYTE *)(v15 + 2);
                                    BYTE1(fhb) = *(_BYTE *)(v15 + 3);
                                    */
                                    *v13 = fhb;
                                    --v13;
                                }
                                while ( --v14 );
                            }
                        }
                        else
                        {
                            _lread(v1, v10, 4 * v8);
                        }
                        result = pdib;
                    }
                    if( bf.bfOffBits )
                    {
                        _llseek(v1, off + bf.bfOffBits, 0);
                        result = pdib;
                    }
                }
                else
                {
                    result = 0;
                }
            }
            else
            {
                result = 0;
            }
        }
        else
        {
            result = 0;
        }
    }
    return result;
}

BITMAPINFOHEADER *DibFromBitmap(void *hbm, unsigned int biStyle, unsigned int biBits, void *hpal, unsigned int wUsage)
{
    void *v6; // ebp@3
    unsigned int v7; // ebx@5
    HGLOBAL v8; // eax@7
    struct tagBITMAPINFO *v9; // eax@7
    struct tagBITMAPINFO *v10; // esi@7
    signed int v11; // eax@10
    HDC v12; // ebx@18
    signed int v13; // eax@18
    unsigned __int16 v14; // cx@19
    unsigned int v15; // eax@21
    unsigned int v16; // eax@24
    HGLOBAL v17; // eax@26
    SIZE_T v18; // ST14_4@26
    HGLOBAL v19; // eax@26
    HGLOBAL v20; // eax@26
    struct tagBITMAPINFO *v21; // eax@26
    struct tagBITMAPINFO *v22; // edi@26
    char *v23; // eax@28
    int v24; // eax@30
    signed int v25; // edx@30
    unsigned __int16 v26; // cx@31
    unsigned int v27; // ecx@33
    HGLOBAL v28; // eax@37
    HGLOBAL v29; // eax@37
    int nColors; // [sp+10h] [bp-1Ch]@1
    tagBITMAP bm; // [sp+14h] [bp-18h]@5
    HPALETTE hpala; // [sp+3Ch] [bp+10h]@18

    nColors = 0;
    if( !hbm )
        return 0;
    v6 = hpal;
    if( !hpal )
        v6 = GetStockObject(15);
    GetObjectA(hbm, 24, &bm);
    GetObjectA(v6, 4, &nColors);
    v7 = biBits;
    if( !biBits )
        v7 = bm.bmBitsPixel * bm.bmPlanes;
    v8 = GlobalAlloc(2u, 0x428u);
    v9 = (struct tagBITMAPINFO *)GlobalLock(v8);
    v10 = v9;
    if( !v9 )
        return 0;
    v9->bmiHeader.biSize = 40;
    v9->bmiHeader.biWidth = bm.bmWidth;
    v9->bmiHeader.biHeight = bm.bmHeight;
    v9->bmiHeader.biPlanes = 1;
    v9->bmiHeader.biBitCount = v7;
    v9->bmiHeader.biCompression = biStyle;
    v9->bmiHeader.biSizeImage = 0;
    v9->bmiHeader.biXPelsPerMeter = 0;
    v9->bmiHeader.biYPelsPerMeter = 0;
    v9->bmiHeader.biClrUsed = 0;
    v9->bmiHeader.biClrImportant = 0;
    if( (unsigned __int16)v7 > 8u )
        v11 = 0;
    else
        v11 = 1 << v7;
    v10->bmiHeader.biClrUsed = v11;
    if( biStyle == 3 )
    {
        if( v7 == 16 )
        {
            v10->bmiColors[0] = (RGBQUAD)63488;
            v10[1].bmiHeader.biSize = 2016;
            v10[1].bmiHeader.biWidth = 31;
        }
        else if( v7 == 24 || v7 == 32 )
        {
            v10->bmiColors[0] = (RGBQUAD)255;
            v10[1].bmiHeader.biSize = 65280;
            v10[1].bmiHeader.biWidth = 16711680;
        }
    }
    v12 = CreateCompatibleDC(0);
    hpala = SelectPalette(v12, v6, 0);
    RealizePalette(v12);
    SetStretchBltMode(v12, 4);
    GetDIBits(v12, hbm, 0, v10->bmiHeader.biHeight, 0, v10, wUsage);
    v13 = v10->bmiHeader.biClrUsed;
    if( !v13 )
    {
        v14 = v10->bmiHeader.biBitCount;
        if( v14 <= 8u )
            v13 = 1 << v14;
    }
    v10->bmiHeader.biClrUsed = v13;
    v15 = v10->bmiHeader.biSizeImage;
    if( !v15 )
        v15 = v10->bmiHeader.biHeight
                * (((v10->bmiHeader.biWidth * (unsigned int)v10->bmiHeader.biBitCount + 31) >> 3) & 0x1FFFFFFC);
    v10->bmiHeader.biSizeImage = v15;
    if( !v15 )
    {
        v16 = v10->bmiHeader.biHeight
                * (((v10->bmiHeader.biWidth * (unsigned int)v10->bmiHeader.biBitCount + 31) >> 3) & 0x1FFFFFFC);
        v10->bmiHeader.biSizeImage = v16;
        if( biStyle )
            v10->bmiHeader.biSizeImage = 3 * v16 >> 1;
    }
    v17 = GlobalHandle(v10);
    GlobalUnlock(v17);
    v18 = v10->bmiHeader.biSizeImage + v10->bmiHeader.biSize + 4 * v10->bmiHeader.biClrUsed;
    v19 = GlobalHandle(v10);
    v20 = GlobalReAlloc(v19, v18, 0);
    v21 = (struct tagBITMAPINFO *)GlobalLock(v20);
    v22 = v21;
    if( v21 )
    {
        if( v21->bmiHeader.biCompression == 3 )
            v23 = (char *)&v21->bmiHeader.biPlanes + v21->bmiHeader.biSize;
        else
            v23 = (char *)v21 + 4 * v21->bmiHeader.biClrUsed + v21->bmiHeader.biSize;
        v24 = GetDIBits(v12, hbm, 0, v22->bmiHeader.biHeight, v23, v22, wUsage);
        v25 = v22->bmiHeader.biClrUsed;
        if( !v25 )
        {
            v26 = v22->bmiHeader.biBitCount;
            if( v26 <= 8u )
                v25 = 1 << v26;
        }
        v27 = v22->bmiHeader.biSizeImage;
        v22->bmiHeader.biClrUsed = v25;
        if( !v27 )
            v27 = v22->bmiHeader.biHeight
                    * ((((unsigned int)v22->bmiHeader.biBitCount * v22->bmiHeader.biWidth + 31) >> 3) & 0x1FFFFFFC);
        v22->bmiHeader.biSizeImage = v27;
        if( v24 )
            goto exit_0;
        DibFree(&v22->bmiHeader);
    }
    else
    {
        v28 = GlobalHandle(v10);
        GlobalUnlock(v28);
        v29 = GlobalHandle(v10);
        GlobalFree(v29);
    }
    v22 = 0;
exit_0:
    SelectPalette(v12, hpala, 0);
    DeleteDC(v12);
    return (BITMAPINFOHEADER *)v22;
}

int DibSetUsage(BITMAPINFOHEADER *pdib, void *hpal, unsigned int wUsage)
{
    void *v3; // eax@1
    signed int v5; // esi@5
    unsigned __int16 v6; // cx@6
    char *v7; // ebx@12
    tagPALETTEENTRY *v8; // ecx@16
    int v9; // eax@16
    char v10; // dl@17
    signed int v11; // eax@19
    char *i; // ecx@19
    tagPALETTEENTRY ape[256]; // [sp+10h] [bp-400h]@15

    v3 = hpal;
    if( !hpal )
        v3 = GetStockObject(15);
    if( !pdib )
        return 0;
    v5 = pdib->biClrUsed;
    if( !v5 )
    {
        v6 = pdib->biBitCount;
        if( v6 <= 8u )
            v5 = 1 << v6;
    }
    if( v5 == 3 && pdib->biCompression == 3 )
        v5 = 0;
    if( v5 <= 0 )
        return 1;
    v7 = (char *)pdib + pdib->biSize;
    if( wUsage == 1 )
    {
        v11 = 0;
        for ( i = (char *)pdib + pdib->biSize; v11 < v5; i += 2 )
            *(_WORD *)i = v11++;
        return 1;
    }
    if( v5 >= 256 )
        v5 = 256;
    GetPaletteEntries(v3, 0, v5, ape);
    if( v5 <= 0 )
        return 1;
    v8 = ape;
    v9 = (int)(v7 + 1);
    do
    {
        v10 = v8->peRed;
        ++v8;
        *(_BYTE *)(v9 + 1) = v10;
        *(_BYTE *)v9 = *(_BYTE *)((char *)ape - v7 + v9);
        *(_BYTE *)(v9 - 1) = *(_BYTE *)(&ape[0].peGreen - v7 + v9);
        *(_BYTE *)(v9 + 2) = 0;
        v9 += 4;
        --v5;
    }
    while ( v5 );
    return 1;
}

BITMAPINFOHEADER *DibDraw(void *hdc, int x, int y, int dx, int dy, BITMAPINFOHEADER *pdib, int x0, int y0, int dx0, int dy0, int rop, unsigned int wUsage)
{
    BITMAPINFOHEADER *result; // eax@1
    int v13; // edx@2
    int v14; // edi@2
    int v15; // ebx@5
    int v16; // esi@5
    char *v17; // ecx@9

    result = pdib;
    if( pdib )
    {
        v13 = dy0;
        v14 = dx0;
        if( dx0 == -1 && dy0 == -1 )
        {
            v14 = pdib->biWidth;
            v13 = pdib->biHeight;
        }
        v15 = dx;
        v16 = dy;
        if( dx == -1 && dy == -1 )
        {
            v15 = v14;
            v16 = v13;
        }
        if( pdib->biCompression == 3 )
            v17 = (char *)&pdib->biPlanes + pdib->biSize;
        else
            v17 = (char *)pdib + 4 * pdib->biClrUsed + pdib->biSize;
        result = (BITMAPINFOHEADER *)StretchDIBits(
            hdc,
            x,
            y,
            v15,
            v16,
            x0,
            y0,
            v14,
            v13,
            v17,
            (const BITMAPINFO *)pdib,
            wUsage,
            rop);
    }
    return result;
}

BITMAPINFOHEADER *DibCopy(BITMAPINFOHEADER *pdib)
{
    BITMAPINFOHEADER *result; // eax@2
    HGLOBAL v2; // eax@3
    void *v3; // edi@3

    if( pdib )
    {
        v2 = GlobalAlloc(2u, pdib->biSizeImage + pdib->biSize + 4 * pdib->biClrUsed);
        v3 = GlobalLock(v2);
        if( v3 )
            memcpy(v3, pdib, pdib->biSizeImage + pdib->biSize + 4 * pdib->biClrUsed);
        result = (BITMAPINFOHEADER *)v3;
    }
    else
    {
        result = 0;
    }
    return result;
}

BITMAPINFOHEADER *DibCreate(int bits, int dx, int dy)
{
    unsigned int v3; // edi@1
    HGLOBAL v4; // eax@1
    BITMAPINFOHEADER *v5; // esi@1
    BITMAPINFOHEADER *result; // eax@1
    int v7; // edi@6
    unsigned int *i; // ecx@6
    _DWORD *v9; // ecx@7

    v3 = dy * ((bits * dx / 8 + 3) & 0xFFFFFFFC);
    v4 = GlobalAlloc(0x42u, v3 + 1064);
    v5 = (BITMAPINFOHEADER *)GlobalLock(v4);
    result = 0;
    if( v5 )
    {
        v5->biSize = 40;
        v5->biWidth = dx;
        v5->biHeight = dy;
        v5->biPlanes = 1;
        v5->biBitCount = bits;
        v5->biCompression = 0;
        v5->biSizeImage = v3;
        v5->biXPelsPerMeter = 0;
        v5->biYPelsPerMeter = 0;
        v5->biClrUsed = 0;
        v5->biClrImportant = 0;
        if( bits == 4 )
        {
            v5->biClrUsed = 16;
        }
        else if( bits == 8 )
        {
            v5->biClrUsed = 256;
        }
        v7 = 0;
        for ( i = &v5[1].biSize; v7 < (signed int)v5->biClrUsed / 16; ++v7 )
        {
            *i = 0;
            v9 = i + 1;
            *v9 = (char *)&pathSystem + 732096;
            ++v9;
            *v9 = 0x8000;
            ++v9;
            *v9 = (char *)&pathSystem + 764864;
            ++v9;
            *v9 = 128;
            ++v9;
            *v9 = (char *)&pathSystem + 732224;
            ++v9;
            *v9 = 32896;
            ++v9;
            *v9 = 12632256;
            ++v9;
            *v9 = (char *)&pathSystem + 764992;
            ++v9;
            *v9 = 16711680;
            ++v9;
            *v9 = 65280;
            ++v9;
            *v9 = 16776960;
            ++v9;
            *v9 = 255;
            ++v9;
            *v9 = 16711935;
            ++v9;
            *v9 = 0xFFFF;
            ++v9;
            *v9 = 0xFFFFFF;
            i = v9 + 1;
        }
        result = v5;
    }
    return result;
}

void DibMapToPalette(BITMAPINFOHEADER *pdib, void *hpal, int TransLogic, int ZeroIsTrans)
{
    void *v4; // ebx@1
    char *v5; // edi@3
    unsigned int v6; // edx@3
    unsigned __int16 v7; // cx@4
    int v8; // esi@5
    tagRGBQUAD *v9; // ecx@16
    signed int v10; // ebx@16
    signed int v11; // esi@16
    int v12; // eax@16
    signed int v13; // edi@16
    int v14; // eax@18
    signed int v15; // edx@25
    unsigned __int16 v16; // cx@26
    int v17; // edi@28
    char *v18; // esi@29
    unsigned __int16 v19; // ax@33
    char v20; // al@33
    unsigned __int16 v21; // ax@35
    int v22; // eax@38
    bool v23; // zf@38
    bool v24; // sf@38
    unsigned __int8 v25; // of@38
    HGLOBAL v26; // eax@39
    SIZE_T v27; // ST08_4@39
    HGLOBAL v28; // eax@39
    HGLOBAL v29; // eax@39
    char *v30; // eax@40
    char *v31; // eax@46
    HGLOBAL v32; // eax@48
    SIZE_T v33; // ST08_4@48
    HGLOBAL v34; // eax@48
    HGLOBAL v35; // eax@48
    unsigned int v36; // eax@51
    int v37; // eax@52
    int v38; // edi@59
    char *v39; // esi@60
    char ZeroIndex; // [sp+13h] [bp-125h]@1
    char *lpBits; // [sp+14h] [bp-124h]@10
    unsigned int SizeImage; // [sp+18h] [bp-120h]@7
    int nPalColors; // [sp+1Ch] [bp-11Ch]@1
    int nDibColors; // [sp+20h] [bp-118h]@5
    tagRGBQUAD *lpRgb; // [sp+24h] [bp-114h]@3
    tagPALETTEENTRY pe; // [sp+28h] [bp-110h]@61
    int ZeroBlue; // [sp+2Ch] [bp-10Ch]@17
    int TransIndex; // [sp+30h] [bp-108h]@1
    int HitEnd; // [sp+34h] [bp-104h]@16
    char xlat[256]; // [sp+38h] [bp-100h]@32

    v4 = hpal;
    nPalColors = 0;
    ZeroIndex = 0;
    LOBYTE(TransIndex) = 0;
    if( !hpal || !pdib )
        return;
    v5 = (char *)pdib + pdib->biSize;
    lpRgb = (tagRGBQUAD *)((char *)pdib + pdib->biSize);
    GetObjectA(hpal, 4, &nPalColors);
    v6 = pdib->biClrUsed;
    if( v6 || (v7 = pdib->biBitCount, v7 > 8u) )
    {
        nDibColors = pdib->biClrUsed;
        v8 = v6;
    }
    else
    {
        v8 = 1 << v7;
        nDibColors = 1 << v7;
    }
    SizeImage = pdib->biSizeImage;
    if( !pdib->biSizeImage )
        SizeImage = pdib->biHeight * ((((unsigned int)pdib->biBitCount * pdib->biWidth + 31) >> 3) & 0x1FFFFFFC);
    if( pdib->biCompression == 3 )
        lpBits = (char *)&pdib->biPlanes + pdib->biSize;
    else
        lpBits = (char *)pdib + 4 * v6 + pdib->biSize;
    if( TransLogic )
    {
        if( ZeroIsTrans )
            LOBYTE(TransIndex) = 0;
        else
            LOBYTE(TransIndex) = lpBits[(pdib->biHeight - 1) * ((pdib->biWidth + 3) & 0xFFFFFFFC)];
        v9 = lpRgb;
        v10 = lpRgb->rgbGreen;
        v11 = (unsigned __int8)v5[2];
        ZeroIndex = 0;
        v12 = lpRgb->rgbBlue;
        HitEnd = 0;
        v13 = 1;
        while ( 1 )
        {
            v11 += v13;
            v10 += v13;
            v14 = v13 + v12;
            ZeroBlue = v14;
            if( v11 > 255 || v10 > 255 || v14 > 255 || v11 < 0 || v10 < 0 || v14 < 0 )
            {
                if( HitEnd )
                    break;
                v13 = -1;
                v15 = v9->rgbRed;
                v10 = v9->rgbGreen;
                v14 = v9->rgbBlue;
                HitEnd = 1;
                v11 = v15;
                ZeroBlue = v14;
            }
            HIBYTE(v16) = v14;
            LOBYTE(v16) = v10;
            ZeroIndex = GetNearestPaletteIndex(hpal, (unsigned __int8)v11 | (v16 << 8));
            if( ZeroIndex )
                break;
            v12 = ZeroBlue;
            v9 = lpRgb;
        }
        v4 = hpal;
        v8 = nDibColors;
    }
    v17 = 0;
    if( v8 > 0 )
    {
        v18 = &lpRgb->rgbRed;
        do
        {
            if( TransLogic )
            {
                if( v17 == (unsigned __int8)TransIndex )
                {
                    xlat[v17] = 0;
                }
                else
                {
                    LOBYTE(v19) = *(v18 - 1);
                    HIBYTE(v19) = *(v18 - 2);
                    v20 = GetNearestPaletteIndex(v4, (unsigned __int8)*v18 | (v19 << 8));
                    xlat[v17] = v20;
                    if( !v20 )
                        xlat[v17] = ZeroIndex;
                }
            }
            else
            {
                LOBYTE(v21) = *(v18 - 1);
                HIBYTE(v21) = *(v18 - 2);
                xlat[v17] = GetNearestPaletteIndex(v4, (unsigned __int8)*v18 | (v21 << 8));
            }
            ++v17;
            v18 += 4;
        }
        while ( v17 < nDibColors );
        v8 = nDibColors;
    }
    v22 = nPalColors;
    v25 = __OFSUB__(nPalColors, v8);
    v23 = nPalColors == v8;
    v24 = nPalColors - v8 < 0;
    pdib->biClrUsed = nPalColors;
    if( (unsigned __int8)(v24 ^ v25) | v23 )
    {
        if( !(v24 ^ v25) )
            goto LABEL_51;
        if( pdib->biCompression == 3 )
            v31 = (char *)&pdib->biPlanes + pdib->biSize;
        else
            v31 = (char *)pdib + 4 * v22 + pdib->biSize;
        memcpy(v31, lpBits, SizeImage);
        v32 = GlobalHandle(pdib);
        GlobalUnlock(v32);
        v33 = SizeImage + pdib->biSize + 4 * nPalColors;
        v34 = GlobalHandle(pdib);
        v35 = GlobalReAlloc(v34, v33, 0);
        GlobalLock(v35);
        if( pdib->biCompression == 3 )
        {
            lpBits = (char *)&pdib->biPlanes + pdib->biSize;
            goto LABEL_51;
        }
LABEL_50:
        lpBits = (char *)pdib + 4 * pdib->biClrUsed + pdib->biSize;
        goto LABEL_51;
    }
    v26 = GlobalHandle(pdib);
    GlobalUnlock(v26);
    v27 = SizeImage + pdib->biSize + 4 * nPalColors;
    v28 = GlobalHandle(pdib);
    v29 = GlobalReAlloc(v28, v27, 0);
    GlobalLock(v29);
    if( pdib->biCompression == 3 )
        v30 = (char *)&pdib->biPlanes + pdib->biSize;
    else
        v30 = (char *)pdib + 4 * pdib->biClrUsed + pdib->biSize;
    memmove(v30, lpBits, SizeImage);
    if( pdib->biCompression != 3 )
        goto LABEL_50;
    lpBits = (char *)&pdib->biPlanes + pdib->biSize;
LABEL_51:
    v36 = pdib->biCompression;
    if( v36 )
    {
        v37 = v36 - 1;
        if( v37 )
        {
            if( v37 == 1 )
                xlatRle4(lpBits, SizeImage, xlat);
        }
        else
        {
            xlatRle8(lpBits, SizeImage, xlat);
        }
    }
    else if( pdib->biBitCount == 8 )
    {
        xlatClut8(lpBits, SizeImage, xlat);
    }
    else
    {
        xlatClut4(lpBits, SizeImage, xlat);
    }
    v38 = 0;
    if( nPalColors > 0 )
    {
        v39 = &lpRgb->rgbGreen;
        do
        {
            GetPaletteEntries(v4, v38++, 1u, &pe);
            v39[1] = pe.peRed;
            *v39 = pe.peGreen;
            *(v39 - 1) = pe.peBlue;
            v39[2] = 0;
            v39 += 4;
        }
        while ( v38 < nPalColors );
    }
}

void xlatClut8(char *pb, unsigned int dwSize, char *xlat)
{
    unsigned int v3 = dwSize;
    if( dwSize )
    {
        char *v4 = pb;
        do
        {
            v5 = (unsigned __int8)*v4++;
            *(v4 - 1) = xlat[v5];
        }
        while ( --v3 );
    }
}

void xlatClut4(char *pb, unsigned int dwSize, char *xlat)
{
    unsigned int v3 = dwSize;
    if( dwSize )
    {
        char *v4 = pb;
        do
        {
            *v4 = 16 * xlat[(unsigned int)(unsigned __int8)*v4 >> 4] | xlat[*v4 & 0xF];
            ++v4;
        }
        while ( --v3 );
    }
}

void xlatRle8(char *pb, unsigned int dwSize, char *xlat)
{
    char *v3; // eax@1
    char v4; // cl@2
    char v5; // bl@2
    int v6; // eax@2
    int v7; // ecx@3
    int v8; // edx@7

    v3 = pb;
    while ( true )
    {
        do
        {
            while ( 1 )
            {
                v4 = *v3;
                v5 = v3[1];
                v6 = (int)(v3 + 1);
                if( !v4 )
                    break;
                v3 = (char *)(v6 + 1);
                *(v3 - 1) = xlat[(unsigned __int8)v5];
            }
            v3 = (char *)(v6 + 1);
            v7 = (unsigned __int8)v5;
        }
        while ( !v5 );
        if( v5 == 1 )
            break;
        if( v5 == 2 )
        {
            v3 += 2;
        }
        else
        {
            if( v5 )
            {
                do
                {
                    v8 = (unsigned __int8)*v3++;
                    --v7;
                    *(v3 - 1) = xlat[v8];
                }
                while ( v7 );
            }
            if( v5 & 1 )
                ++v3;
        }
    }
}

void memmove(char *d, char *s, int len)
{
    char *v3 = &d[len - 1];
    char *v4 = &s[len - 1];
    if( len )
    {
        int i = len;
        do
        {
            *v3-- = *v4--;
        }
        while ( --i );
    }
}

void CreateIdentityPalette(void *hpal)
{
    signed int v1; // edi@1
    signed int v2; // ebp@1
    HWND v3; // eax@1
    HDC v4; // eax@2
    char *v5; // ecx@8
    char *v6; // esi@8
    signed int v7; // eax@8
    struct PAL_TABLE *v8; // ecx@12
    void *v9; // eax@13
    char v10; // dl@14
    struct PAL_TABLE *v11; // ecx@14
    void *hdc; // [sp+10h] [bp-808h]@4
    void *hwnd; // [sp+14h] [bp-804h]@1
    tagPALETTEENTRY new_pal[256]; // [sp+18h] [bp-800h]@4
    tagPALETTEENTRY from_pal[256]; // [sp+418h] [bp-400h]@6

    v1 = 0;
    v2 = 0;
    v3 = GetActiveWindow();
    hwnd = v3;
    if( v3 )
        v4 = GetDC(v3);
    else
        v4 = GetDC(0);
    hdc = v4;
    if( !GetSystemPaletteEntries(v4, 0, 0x100u, new_pal) )
        v1 = 1;
    if( !GetPaletteEntries(hpal, 0, 0x100u, from_pal) )
        v2 = 1;
    v5 = &new_pal[10].peFlags;
    v6 = &from_pal[10].peGreen;
    v7 = 0;
    do
    {
        v6 += 4;
        new_pal[v7 + 10].peRed = from_pal[v7 + 10].peRed;
        new_pal[v7 + 10].peGreen = *(v6 - 4);
        *(v5 - 1) = from_pal[v7 + 10].peBlue;
        *v5 = 1;
        ++v7;
        v5 += 4;
    }
    while ( v7 < 236 );
    if( v1 || v2 )
    {
        v8 = System_color_Table;
        if( (signed int)System_color_Table >= 0 )
        {
            v9 = &unk_5841E5;
            do
            {
                v10 = *((char *)v9 - 1);
                v9 = (char *)v9 + 8;
                v11 = (struct PAL_TABLE *)(4 * (_DWORD)v8);
                *((_BYTE *)&v11->index + (_DWORD)new_pal) = v10;
                *((_BYTE *)&v11->index + (_DWORD)new_pal + 1) = *((char *)v9 - 8);
                *((_BYTE *)&v11->index + (_DWORD)new_pal + 2) = *((char *)v9 - 7);
                *((_BYTE *)&v11->index + (_DWORD)new_pal + 3) = 0;
                v8 = *(struct PAL_TABLE **)((char *)v9 - 5);
            }
            while ( (signed int)v8 >= 0 );
        }
    }
    ReleaseDC(hwnd, hdc);
    ResizePalette(hpal, 0x100u);
    SetPaletteEntries(hpal, 0, 0x100u, new_pal);
}

void *CopyPalette(void *hpal)
{
    void *result; // eax@2
    const LOGPALETTE *v2; // esi@4
    HPALETTE v3; // edi@5
    int nNumEntries; // [sp+8h] [bp-4h]@1

    nNumEntries = 0;
    if( hpal )
    {
        GetObjectA(hpal, 4, &nNumEntries);
        result = (void *)nNumEntries;
        if( nNumEntries )
        {
            result = LocalAlloc(0x40u, 4 * nNumEntries + 8);
            v2 = (const LOGPALETTE *)result;
            if( result )
            {
                *(_WORD *)result = 768;
                *((_WORD *)result + 1) = nNumEntries;
                GetPaletteEntries(hpal, 0, nNumEntries, (LPPALETTEENTRY)result + 1);
                v3 = CreatePalette(v2);
                LocalFree((HLOCAL)v2);
                result = v3;
            }
        }
    }
    else
    {
        result = 0;
    }
    return result;
}

void DibFree(BITMAPINFOHEADER *pdib)
{
    GlobalUnlock(GlobalHandle(pdib));

    GlobalFree(GlobalHandle(pdib));
}
