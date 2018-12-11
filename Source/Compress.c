#include "IDA.h"

int dword_886C60;
int dword_886C64[0];
int dword_886C68[0];
int dword_886C6C;
int dword_886CEC;
int dword_886CF0;
int dword_886CF4;
int dword_886CF8[0];
int dword_887174[0];
int dword_887178[0];
int dword_8875F8;
int dword_887600[0];
int dword_887A80;
int dword_887A84;
int dword_887A88;
int dword_887A8C;
int dword_887A90;
int dword_887A94[0];
int dword_887A98[0];
int dword_887A9C[0];
_UNKNOWN unk_887B18;
int dword_887B1C;
int dword_887B20[0];
int dword_887B24;
int dword_887FA4;
int dword_887FA8;
unsigned short word_58EF48[0];
char byte_58F248[0];
char byte_58F148[0];
char byte_58F948[0];
unsigned short word_58FA48[0];
char byte_58F9C8[0];
char byte_58F348[0];
char byte_58F748[0];
char byte_58F548[0];

int sub_547B30();
char sub_547C90(DWORD *a1, BYTE *a2, unsigned int a3);
int sub_547CF0();
int sub_547D50();
int sub_547D80(int a1, int a2);
int sub_547EF0(unsigned int a1);
void sub_547F40(unsigned int a1, int a2);
int sub_548030();
int sub_5480B0(int a1);
int sub_548410();
void sub_548660();
int sub_548750(void *a1, int a2, unsigned int a3);
int sub_548770(int a1, int *a2);
void sub_548800(int a1, int *a2, int a3, void *a4);
BOOL sub_5488F0();
void sub_548910();
int sub_548B00(int a1, int a2, DWORD *a3);
int sub_548C20(int a1, int a2, int a3, int a4);
void sub_548CB0(int a1);
void sub_548D60();
DWORD *sub_549020(DWORD *result, DWORD *a2, int *a3, int a4);
DWORD *sub_549040(int a1, int a2, int a3);
DWORD *sub_5490A0(int a1, int a2);
int sub_549120();
int sub_549150();
int sub_5492F0();
int sub_549460(int a1);
short sub_549970(int a1);
int sub_549B20();
int sub_549B70();
int sub_549F40();
void sub_54A360();
int sub_54A380();
void sub_54A450(void *a1, char a2, unsigned int a3);

int sub_54A580();

void sub_54A870(int a1, int a2);
void sub_54A9DE(int a1);
void sub_54AAA1(unsigned int a1, BYTE *a2, BYTE *a3);
int sub_54AB0C(short a1, unsigned int a2);
int sub_54AB24(short a1, unsigned int a2);
unsigned int sub_54AB34(short a1, unsigned int a2);
unsigned int sub_54AB98(unsigned char a1, short a2, int a3);
unsigned int sub_54ABE4(unsigned char a1, short a2, int a3);
int sub_54AC2D(int a1, int a2);
void sub_54AF80(unsigned int a1, short a2, unsigned int a3);

int deflate_data(int a1, int a2, int a3, int a4)
{
    int result; // eax@3

    dword_887A80 = a1;
    if ( a1 && *(DWORD *)(a1 + 229752) == 305419896 )
    {
        *(DWORD *)(a1 + 229724) = a2;
        *(DWORD *)(dword_887A80 + 229728) = a3;
        *(DWORD *)(dword_887A80 + 229716) = *(DWORD *)(dword_887A80 + 229724);
        *(DWORD *)(dword_887A80 + 229720) = *(DWORD *)(dword_887A80 + 229728);
        *(DWORD *)(dword_887A80 + 229696) = a4;
        dword_887A94[0] = dword_887A80;
        dword_887FA4 = dword_887A80 + 37122;
        dword_886CF0 = dword_887A80 + 53506;
        dword_886CEC = dword_887A80 + 119042;
        dword_886C60 = *(DWORD *)(dword_887A80 + 229684);
        dword_887B1C = *(DWORD *)(dword_887A80 + 229676);
        dword_887FA8 = *(DWORD *)(dword_887A80 + 229680);
        dword_887A8C = *(DWORD *)(dword_887A80 + 229648);
        dword_886CF4 = *(DWORD *)(dword_887A80 + 229652);
        dword_887A84 = *(DWORD *)(dword_887A80 + 229656);
        dword_887A90 = *(DWORD *)(dword_887A80 + 229744);
        dword_887A88 = *(DWORD *)(dword_887A80 + 229748);
        result = sub_547B30();
        *(DWORD *)(dword_887A80 + 229676) = dword_887B1C;
        *(DWORD *)(dword_887A80 + 229680) = dword_887FA8;
        *(DWORD *)(dword_887A80 + 229648) = dword_887A8C;
        *(DWORD *)(dword_887A80 + 229652) = dword_886CF4;
        *(DWORD *)(dword_887A80 + 229656) = dword_887A84;
        *(DWORD *)(dword_887A80 + 229744) = dword_887A90;
        *(DWORD *)(dword_887A80 + 229748) = dword_887A88;
    }
    else
    {
        result = 2;
    }
    return result;
}

int sub_547B30()
{
    int result; // eax@13
    int v1; // eax@15

    while ( 1 )
    {
        if ( sub_54A380() && !*(DWORD *)(dword_887A80 + 229696) )
            return 0;
        if ( *(DWORD *)(dword_887A80 + 229700) )
            sub_547EF0(*(DWORD *)(dword_887A80 + 229704));
        sub_547F40(*(DWORD *)(dword_887A80 + 229704), *(DWORD *)(dword_887A80 + 229668));
        if ( !*(DWORD *)(dword_887A80 + 229704) )
            sub_547C90((DWORD *)(dword_887A80 + 0x8000), (BYTE *)dword_887A80, 0x1102u);
        if ( sub_549460(*(DWORD *)(dword_887A80 + 229704)) )
            return 1;
        *(DWORD *)(dword_887A80 + 229704) += 4096;
        if ( *(DWORD *)(dword_887A80 + 229704) == 0x8000 )
        {
            *(DWORD *)(dword_887A80 + 229704) = 0;
            *(DWORD *)(dword_887A80 + 229700) = 1;
        }
        if ( *(DWORD *)(dword_887A80 + 229696) && !*(DWORD *)(dword_887A80 + 229720) )
            break;
        *(DWORD *)(dword_887A80 + 229668) = 0;
    }
    sub_54A360();
    if ( v1 )
    {
        result = 1;
    }
    else if ( sub_548030() )
    {
        result = 1;
    }
    else if ( sub_547D50() )
    {
        result = 1;
    }
    else if ( sub_547CF0() )
    {
        result = 1;
    }
    else
    {
        *(DWORD *)(dword_887A80 + 229752) = -1412623820;
        result = 1;
    }
    return result;
}

char sub_547C90(DWORD *a1, BYTE *a2, unsigned int a3)
{
    int v3; // esi@1
    DWORD *v4; // ecx@2
    unsigned int v5; // edx@2
    BYTE *v6; // edi@2
    int v7; // eax@3
    int v8; // eax@3

    v3 = a3;
    if ( (signed int)a3 < 16 )
    {
        v4 = a1;
        v6 = a2;
    }
    else
    {
        v4 = a1;
        v5 = a3 >> 4;
        v6 = a2;
        v3 = a3 - 16 * (a3 >> 4);
        do
        {
            v7 = *(DWORD *)v6;
            v6 += 16;
            *v4 = v7;
            v4 += 4;
            --v5;
            *(v4 - 3) = *((DWORD *)v6 - 3);
            *(v4 - 2) = *((DWORD *)v6 - 2);
            v8 = *((DWORD *)v6 - 1);
            *(v4 - 1) = v8;
        }
        while ( v5 );
    }
    for ( ; v3; --v3 )
    {
        LOBYTE(v8) = *v6++;
        *(BYTE *)v4 = v8;
        v4 = (DWORD *)((char *)v4 + 1);
    }
    return v8;
}

int sub_547CF0()
{
    int result; // eax@2

    if ( (*(int (__cdecl **)(DWORD, int))(dword_887A80 + 229740))(
                 *(DWORD *)(dword_887A80 + 229732),
                 *(DWORD *)(dword_887A80 + 229736) - dword_887A88) )
    {
        result = 1;
    }
    else
    {
        dword_887A90 = *(DWORD *)(dword_887A80 + 229732);
        result = 0;
        dword_887A88 = *(DWORD *)(dword_887A80 + 229736);
    }
    return result;
}

int sub_547D50()
{
    int result; // eax@2

    if ( sub_547D80(0, 7) )
    {
        result = 1;
    }
    else
    {
        dword_886CF4 = 0;
        result = 0;
    }
    return result;
}

int sub_547D80(int a1, int a2)
{
    int result; // eax@2

    if ( dword_887A84 )
    {
        *(DWORD *)(dword_887A80 + 229660) += a2;
        result = 0;
    }
    else
    {
        dword_887A8C |= a1 << dword_886CF4;
        dword_886CF4 += a2;
        if ( dword_886CF4 >= 8 )
        {
            if ( dword_886CF4 < 16 )
            {
                if ( --dword_887A88 >= 0 )
                {
                    *(BYTE *)dword_887A90 = dword_887A8C;
                    result = 0;
                    dword_887A8C = (unsigned int)dword_887A8C >> 8;
                    dword_886CF4 -= 8;
                    ++dword_887A90;
                }
                else
                {
                    ++dword_887A88;
                    while ( --dword_887A88 < 0 )
                    {
                        ++dword_887A88;
                        if ( sub_547CF0() )
                            return 1;
                    }
                    *(BYTE *)dword_887A90 = dword_887A8C;
                    result = 0;
                    dword_887A8C = (unsigned int)dword_887A8C >> 8;
                    dword_886CF4 -= 8;
                    ++dword_887A90;
                }
            }
            else
            {
                dword_887A88 -= 2;
                if ( dword_887A88 >= 0 )
                {
                    *(WORD *)dword_887A90 = dword_887A8C;
                    result = 0;
                    dword_887A90 += 2;
                    dword_887A8C = (unsigned int)dword_887A8C >> 16;
                    dword_886CF4 -= 16;
                }
                else
                {
                    dword_887A88 += 2;
                    while ( --dword_887A88 < 0 )
                    {
                        ++dword_887A88;
                        if ( sub_547CF0() )
                            return 1;
                    }
                    *(BYTE *)dword_887A90++ = dword_887A8C;
                    while ( --dword_887A88 < 0 )
                    {
                        ++dword_887A88;
                        if ( sub_547CF0() )
                            return 1;
                    }
                    *(BYTE *)dword_887A90 = BYTE1(dword_887A8C);
                    result = 0;
                    dword_887A8C = (unsigned int)dword_887A8C >> 16;
                    dword_886CF4 -= 16;
                    ++dword_887A90;
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

int sub_547EF0(unsigned int a1)
{
    int result; // eax@1
    int v2; // esi@2
    int v3; // edx@2
    int v4; // ecx@3

    result = a1;
    if ( a1 + 4096 > a1 )
    {
        v2 = 2 * a1;
        v3 = 4096;
        while ( 1 )
        {
            result = dword_886CEC;
            v4 = *(WORD *)(dword_886CEC + v2);
            if ( !(BYTE1(v4) & 0x80) )
                break;
            if ( v4 != 0xFFFF )
            {
                v4 &= 0x7FFFu;
                result = dword_887FA4;
LABEL_7:
                *(WORD *)(result + 2 * v4) = -1;
            }
            v2 += 2;
            if ( !--v3 )
                return result;
        }
        result = dword_886CF0;
        goto LABEL_7;
    }
    return result;
}

void sub_547F40(unsigned int a1, int a2)
{
    unsigned int v2; // ebx@1
    unsigned int v3; // ecx@3
    int v4; // edx@4
    unsigned int v5; // edi@4
    unsigned int v6; // edi@7
    int v7; // edx@7
    unsigned int v8; // esi@8
    int v9; // eax@9
    unsigned short v10; // ax@9

    v2 = a2 - 2;
    if ( a2 - 2 <= 0 )
        v2 = 0;
    v3 = a1;
    if ( a2 > v2 )
    {
        v4 = a2 - v2;
        v5 = 2 * (v2 + a1);
        do
        {
            v5 += 2;
            *(WORD *)(dword_886CEC + v5 - 2) = -1;
            --v4;
            *(WORD *)(dword_886CF0 + v5 - 2) = *(WORD *)(dword_886CEC + v5 - 2);
        }
        while ( v4 );
    }
    if ( a2 > 2 )
    {
        v6 = a2 + a1 - 2;
        v7 = *(BYTE *)(a1 + dword_887A94[0] + 1) ^ 32 * *(BYTE *)(a1 + dword_887A94[0]);
        if ( a1 < v6 )
        {
            v8 = 2 * a1;
            do
            {
                v9 = 32 * (unsigned char)v7 ^ *(BYTE *)(dword_887A94[0] + v3 + 2);
                v7 = v9;
                BYTE1(v9) |= 0x80u;
                *(WORD *)(dword_886CEC + v8) = v9;
                *(WORD *)(dword_886CF0 + v8) = *(WORD *)(dword_887FA4 + 2 * v7);
                v10 = *(WORD *)(dword_886CF0 + v8);
                if ( v10 != -1 )
                    *(WORD *)(dword_886CEC + 2 * v10) = v3;
                v8 += 2;
                *(WORD *)(dword_887FA4 + 2 * v7) = v3++;
            }
            while ( v6 > v3 );
        }
    }
}

int sub_548030()
{
    int v0; // eax@1

    v0 = *(DWORD *)(dword_887A80 + 222992);
    if ( v0 != 32 )
    {
        for ( *(DWORD *)(dword_887A80 + 221448) += 32 - v0;
                    *(DWORD *)(dword_887A80 + 222992);
                    --*(DWORD *)(dword_887A80 + 222992) )
        {
            **(DWORD **)(dword_887A80 + 222988) *= 2;
        }
        *(DWORD *)(dword_887A80 + 222988) += 4;
        *(DWORD *)(dword_887A80 + 222992) = 32;
    }
    return sub_5480B0(1);
}

int sub_5480B0(int a1)
{
    int result; // eax@3
    int v2; // eax@4
    unsigned int v3; // esi@19
    unsigned int v4; // edx@23
    unsigned int v5; // ecx@23
    unsigned int v6; // edx@47
    unsigned int v7; // eax@47

    *(DWORD *)(dword_887A80 + 223000) = *(DWORD *)(dword_887A80 + 229664);
    if ( *(DWORD *)(dword_887A80 + 221448) )
    {
        if ( sub_547D80(0, 1) )
            return 1;
        v2 = *(DWORD *)(dword_887A80 + 229688);
        if ( v2 )
        {
            if ( v2 == 1 )
            {
                sub_548910();
                if ( sub_549120() )
                    return 1;
                if ( sub_548410() )
                    return 1;
            }
            else if ( *(DWORD *)(dword_887A80 + 221448) >= 128 )
            {
                if ( *(DWORD *)(dword_887A80 + 223004) < 14745 )
                {
                    dword_887A84 = 1;
                    *(DWORD *)(dword_887A80 + 229660) = 0;
                    sub_548910();
                    if ( sub_549120() )
                        return 1;
                    if ( sub_548410() )
                        return 1;
                    v6 = *(DWORD *)(dword_887A80 + 229660);
                    dword_887A84 = 0;
                    v7 = 8 * *(DWORD *)(dword_887A80 + 223004) + 34;
                    if ( ((BYTE)dword_886CF4 + 2) & 7 )
                        v7 = v7 - (((BYTE)dword_886CF4 + 2) & 7) + 8;
                    if ( v7 >= v6 )
                    {
                        if ( sub_549120() )
                            return 1;
                        if ( sub_548410() )
                            return 1;
                    }
                    else if ( sub_5492F0() )
                    {
                        return 1;
                    }
                }
                else
                {
                    sub_548910();
                    if ( sub_549120() )
                        return 1;
                    if ( sub_548410() )
                        return 1;
                }
            }
            else
            {
                dword_887A84 = 1;
                *(DWORD *)(dword_887A80 + 229660) = 0;
                sub_548660();
                if ( sub_5488F0() )
                    return 1;
                if ( sub_548410() )
                    return 1;
                v3 = *(DWORD *)(dword_887A80 + 229660);
                *(DWORD *)(dword_887A80 + 229660) = 0;
                sub_548910();
                if ( sub_549120() )
                    return 1;
                if ( sub_548410() )
                    return 1;
                v4 = *(DWORD *)(dword_887A80 + 229660);
                dword_887A84 = 0;
                v5 = 8 * *(DWORD *)(dword_887A80 + 223004) + 34;
                if ( ((BYTE)dword_886CF4 + 2) & 7 )
                    v5 = v5 - (((BYTE)dword_886CF4 + 2) & 7) + 8;
                if ( v5 >= v3 || v5 >= v4 )
                {
                    if ( v4 <= v3 )
                    {
                        if ( sub_549120() )
                            return 1;
                        if ( sub_548410() )
                            return 1;
                    }
                    else
                    {
                        sub_548660();
                        if ( sub_5488F0() )
                            return 1;
                        if ( sub_548410() )
                            return 1;
                    }
                }
                else if ( sub_5492F0() )
                {
                    return 1;
                }
            }
        }
        else
        {
            sub_548660();
            if ( sub_5488F0() )
                return 1;
            if ( sub_548410() )
                return 1;
        }
    }
    *(DWORD *)(dword_887A80 + 222988) = dword_887A80 + 221452;
    *(DWORD *)(dword_887A80 + 222992) = 32;
    *(DWORD *)(dword_887A80 + 221444) = dword_887A80 + 184578;
    *(DWORD *)(dword_887A80 + 221448) = 0;
    *(DWORD *)(dword_887A80 + 223004) = 0;
    *(DWORD *)(dword_887A80 + 222996) = *(DWORD *)(dword_887A80 + 223000);
    if ( !a1 )
        goto LABEL_66;
    if ( sub_547D80(1, 1) )
        return 1;
    sub_548660();
    if ( sub_5488F0() )
        return 1;
    if ( sub_548410() )
        result = 1;
    else
LABEL_66:
        result = 0;
    return result;
}

int sub_548410()
{
    char *v0; // esi@1
    int v1; // ebp@2
    int *v2; // eax@4
    int v3; // ebx@6
    unsigned int v4; // edi@6
    int v5; // eax@6
    int v6; // eax@9
    int v8; // eax@12
    unsigned char v9; // al@15
    int v10; // [sp+10h] [bp-Ch]@1
    int v11; // [sp+14h] [bp-8h]@1
    int v12; // [sp+18h] [bp-4h]@1

    v11 = 0;
    v0 = (char *)(dword_887A80 + 184578);
    v10 = dword_887A80 + 221452;
    v12 = *(DWORD *)(dword_887A80 + 221448);
    if ( v12 <= 0 )
        return (unsigned int)sub_547D80(*(DWORD *)(dword_887A80 + 226744), *(DWORD *)(dword_887A80 + 225388)) >= 1;
    v1 = dword_887A80 + 221452;
    while ( 1 )
    {
        if ( !v11 )
        {
            v11 = 32;
            v2 = (int *)v10;
            v10 += 4;
            v1 = *v2;
        }
        if ( !(v1 & 0x80000000) )
            break;
        v3 = (unsigned char)*v0;
        v4 = *(WORD *)(v0 + 1) - 1;
        v5 = dword_887A80 + 4 * (unsigned short)word_58EF48[v3];
        if ( sub_547D80(*(DWORD *)(v5 + 225720), *(DWORD *)(v5 + 224364)) )
            return 1;
        if ( sub_547D80((unsigned char)(v3 & byte_58F248[v3]), (unsigned char)byte_58F148[v3]) )
            return 1;
        if ( v4 >= 0x200 )
        {
            v8 = dword_887A80 + 4 * (unsigned char)byte_58F948[v4 >> 8];
            if ( sub_547D80(*(DWORD *)(v8 + 226872), *(DWORD *)(v8 + 225516)) )
                return 1;
            if ( sub_547D80(v4 & (unsigned short)word_58FA48[v4 >> 8], (unsigned char)byte_58F9C8[v4 >> 8]) )
                return 1;
        }
        else
        {
            v6 = dword_887A80 + 4 * (unsigned char)byte_58F348[v4];
            if ( sub_547D80(*(DWORD *)(v6 + 226872), *(DWORD *)(v6 + 225516)) )
                return 1;
            if ( sub_547D80(v4 & (unsigned char)byte_58F748[v4], (unsigned char)byte_58F548[v4]) )
                return 1;
        }
        v0 += 3;
LABEL_16:
        v1 *= 2;
        --v11;
        if ( --v12 <= 0 )
            return (unsigned int)sub_547D80(*(DWORD *)(dword_887A80 + 226744), *(DWORD *)(dword_887A80 + 225388)) >= 1;
    }
    v9 = *v0++;
    if ( !sub_547D80(*(DWORD *)(dword_887A80 + 4 * v9 + 225720), *(DWORD *)(dword_887A80 + 4 * v9 + 224364)) )
        goto LABEL_16;
    return 1;
}

void sub_548660()
{
    sub_548750((void *)(dword_887A80 + 224364), 8, 0x90u);
    sub_548750((void *)(dword_887A80 + 224940), 9, 0x70u);
    sub_548750((void *)(dword_887A80 + 225388), 7, 0x18u);
    sub_548750((void *)(dword_887A80 + 225484), 8, 8u);
    sub_548770(288, (int *)(dword_887A80 + 224364));
    sub_548800(288, (int *)(dword_887A80 + 224364), 15, (void *)(dword_887A80 + 225720));
    sub_548750((void *)(dword_887A80 + 225516), 5, 0x20u);
    sub_548770(32, (int *)(dword_887A80 + 225516));
    sub_548800(32, (int *)(dword_887A80 + 225516), 15, (void *)(dword_887A80 + 226872));
}

int sub_548750(void *a1, int a2, unsigned int a3)
{
    int result; // eax@2

    if ( a3 )
    {
        result = a2;
        memset32(a1, a2, a3);
    }
    return result;
}

int sub_548770(int a1, int *a2)
{
    int *v2; // ecx@2
    int v3; // eax@2
    int v4; // edi@3
    int result; // eax@4
    int v6; // ecx@4
    int i; // edi@6
    int *v8; // ecx@8

    dword_8875F8 = 0;
    sub_548750(dword_887A98, 0, 0x21u);
    if ( a1 > 0 )
    {
        v2 = a2;
        v3 = a1;
        do
        {
            v4 = *v2;
            ++v2;
            ++dword_887A98[v4];
            --v3;
        }
        while ( v3 );
    }
    result = 0;
    v6 = 1;
    do
    {
        dword_886C68[v6] = result;
        result += dword_887A98[v6];
        ++v6;
    }
    while ( v6 <= 32 );
    for ( i = 0; i < a1; ++i )
    {
        result = a2[i];
        if ( result )
        {
            v8 = (int *)(4 * result + 8940648);
            ++dword_8875F8;
            result = dword_886C68[result] + 1;
            *v8 = result;
            dword_887174[result] = i;
        }
    }
    return result;
}

void sub_548800(int a1, int *a2, int a3, void *a4)
{
    int v4; // edx@2
    int v5; // eax@4
    int i; // ebp@4
    int v7; // ebx@5
    int v8; // eax@8
    int v9; // ecx@9
    int v10; // esi@9
    int v11; // edi@10
    int v12; // ecx@11
    int v13; // eax@11
    int *j; // esi@11
    int v15; // edi@12
    int v16; // ebx@12
    int *v17; // edi@14
    unsigned int v18; // ebx@16
    int v19; // eax@16
    int v20; // ecx@16
    char v21; // bp@17

    if ( dword_8875F8 )
    {
        v4 = a1;
        if ( a1 > 0 )
            memset(a4, 0, 4 * a1);
        v5 = 1;
        for ( i = 0; a3 >= v5; ++v5 )
        {
            v7 = dword_887A98[v5];
            if ( v7 > 0 )
            {
                memset32((void *)(4 * i + 8940792), v5, v7);
                i += v7;
            }
        }
        v8 = 0;
        dword_886C6C = 0;
        if ( a3 >= 2 )
        {
            v9 = 2;
            v10 = a3 - 1;
            do
            {
                v11 = dword_887A94[v9];
                ++v9;
                --v10;
                v8 = 2 * (v8 + v11);
                dword_886C64[v9] = v8;
            }
            while ( v10 );
        }
        v12 = 0;
        v13 = 0;
        for ( j = a2; dword_8875F8 > v13; a2[v16] = v15 )
        {
            v15 = dword_886CF8[v12];
            v16 = dword_887178[v12];
            ++v12;
            ++v13;
        }
        if ( a1 > 0 )
        {
            v17 = (int *)a4;
            do
            {
                if ( *j )
                {
                    v18 = dword_886C68[*j]++;
                    v19 = *j;
                    v20 = 0;
                    if ( *j > 0 )
                    {
                        do
                        {
                            v21 = v18;
                            v18 >>= 1;
                            v20 = v21 & 1 | 2 * v20;
                            --v19;
                        }
                        while ( v19 );
                    }
                    *v17 = v20;
                }
                ++v17;
                ++j;
                --v4;
            }
            while ( v4 );
        }
    }
}

BOOL sub_5488F0()
{
    return (unsigned int)sub_547D80(1, 2) >= 1;
}

void sub_548910()
{
    BYTE *v0; // esi@1
    int v1; // ebx@1
    int *v2; // edi@1
    int v3; // edx@2
    unsigned int v4; // eax@6
    short v5; // bp@6
    int v6; // eax@9
    int v7; // [sp+10h] [bp-4h]@1

    v0 = (BYTE *)(dword_887A80 + 184578);
    v1 = 0;
    v2 = (int *)(dword_887A80 + 221452);
    sub_548750((void *)(dword_887A80 + 223008), 0, 0x120u);
    sub_548750((void *)(dword_887A80 + 224160), 0, 0x20u);
    v7 = *(DWORD *)(dword_887A80 + 221448);
    if ( v7 > 0 )
    {
        v3 = *(DWORD *)(dword_887A80 + 221448);
        do
        {
            if ( !v1 )
            {
                v3 = *v2;
                ++v2;
                v1 = 32;
            }
            if ( v3 & 0x80000000 )
            {
                v4 = *(WORD *)(v0 + 1) - 1;
                v5 = word_58EF48[*v0];
                ++*(DWORD *)(dword_887A80 + 4 * (unsigned short)v5 + 223008);
                if ( v4 >= 0x200 )
                {
                    v0 += 3;
                    ++*(DWORD *)(dword_887A80 + 4 * (unsigned char)byte_58F948[v4 >> 8] + 224160);
                }
                else
                {
                    v0 += 3;
                    ++*(DWORD *)(dword_887A80 + 4 * (unsigned char)byte_58F348[v4] + 224160);
                }
            }
            else
            {
                v6 = *v0++;
                ++*(DWORD *)(dword_887A80 + 4 * v6 + 223008);
            }
            v3 *= 2;
            --v1;
            --v7;
        }
        while ( v7 );
    }
    ++*(DWORD *)(dword_887A80 + 224032);
    sub_548B00(288, dword_887A80 + 223008, (DWORD *)(dword_887A80 + 224364));
    sub_548770(288, (int *)(dword_887A80 + 224364));
    sub_548CB0(15);
    sub_548800(288, (int *)(dword_887A80 + 224364), 15, (void *)(dword_887A80 + 225720));
    sub_548B00(32, dword_887A80 + 224160, (DWORD *)(dword_887A80 + 225516));
    sub_548770(32, (int *)(dword_887A80 + 225516));
    sub_548CB0(15);
    sub_548800(32, (int *)(dword_887A80 + 225516), 15, (void *)(dword_887A80 + 226872));
    sub_548D60();
}

int sub_548B00(int a1, int a2, DWORD *a3)
{
    DWORD *v3; // esi@3
    int v4; // edi@5
    int result; // eax@5
    int *v6; // ebx@6
    DWORD *v7; // ecx@6
    int v8; // edi@10
    int v9; // ebx@13
    int v10; // ST0C_4@14
    int v11; // eax@15
    int v12; // ebx@15
    int v13; // ebp@15

    if ( a1 <= 0 || (memset(dword_887600, 0xFFu, 4 * a1), a1 <= 0) )
    {
        v3 = a3;
    }
    else
    {
        v3 = a3;
        memset(a3, 0, 4 * a1);
    }
    v4 = 1;
    result = 0;
    if ( a1 > 0 )
    {
        v6 = &dword_887B24;
        v7 = (DWORD *)a2;
        do
        {
            if ( *v7 )
            {
                *v6 = result;
                ++v6;
                ++v4;
            }
            ++v7;
            ++result;
        }
        while ( a1 > result );
    }
    v8 = v4 - 1;
    if ( v8 > 1 )
    {
        v9 = v8 >> 1;
        while ( v9 )
        {
            v10 = v9--;
            sub_548C20((int)dword_887B20, a2, v8, v10);
        }
        do
        {
            v11 = dword_887B20[v8];
            v12 = dword_887B24;
            --v8;
            dword_887B24 = v11;
            sub_548C20((int)dword_887B20, a2, v8, 1);
            v13 = dword_887B24;
            *(DWORD *)(a2 + 4 * v13) += *(DWORD *)(a2 + 4 * v12);
            sub_548C20((int)dword_887B20, a2, v8, 1);
            do
            {
                result = v13;
                ++v3[v13];
                v13 = dword_887600[v13];
            }
            while ( v13 != -1 );
            dword_887600[result] = v12;
            do
            {
                ++v3[v12];
                v12 = dword_887600[v12];
            }
            while ( v12 != -1 );
        }
        while ( v8 != 1 );
    }
    else if ( v8 )
    {
        result = dword_887B24;
        v3[dword_887B24] = 1;
    }
    return result;
}

int sub_548C20(int a1, int a2, int a3, int a4)
{
    int v4; // esi@1
    bool v5; // sf@2
    unsigned char v6; // of@2
    int v7; // ebx@4
    int v8; // edi@4
    int v9; // ebp@4
    int v10; // eax@4
    int v11; // edi@8
    int v12; // ebx@8
    int v13; // eax@11
    int result; // eax@12
    int v15; // [sp+10h] [bp-8h]@1
    DWORD *v16; // [sp+14h] [bp-4h]@2

    v4 = 2 * a4;
    v15 = *(DWORD *)(a1 + 4 * a4);
    if ( 2 * a4 <= a3 )
    {
        v6 = __OFSUB__(v4, a3);
        v5 = v4 - a3 < 0;
        v16 = (DWORD *)(a2 + 4 * *(DWORD *)(a1 + 4 * a4));
        do
        {
            if ( v5 ^ v6 )
            {
                v7 = *(DWORD *)(a1 + 4 * v4 + 4);
                v8 = *(DWORD *)(a2 + 4 * v7);
                v9 = *(DWORD *)(a1 + 4 * v4);
                v10 = *(DWORD *)(a2 + 4 * v9);
                if ( v8 < v10 || v8 == v10 && v7 > v9 )
                    ++v4;
            }
            v11 = *(DWORD *)(a1 + 4 * v4);
            v12 = *(DWORD *)(a2 + 4 * v11);
            if ( v12 > *v16 || v12 == *v16 && v15 > v11 )
                break;
            v13 = a4;
            a4 = v4;
            v4 *= 2;
            *(DWORD *)(a1 + 4 * v13) = v11;
            v6 = __OFSUB__(v4, a3);
            v5 = v4 - a3 < 0;
        }
        while ( v4 <= a3 );
    }
    result = a4;
    *(DWORD *)(a1 + 4 * a4) = v15;
    return result;
}

void sub_548CB0(int a1)
{
    int *v1; // ecx@3
    int v2; // esi@4
    int v3; // edi@5
    int v4; // eax@5
    int v5; // edx@8
    int v6; // edi@8
    int v7; // ecx@9
    int *v8; // eax@10

    if ( dword_8875F8 > 1 )
    {
        if ( a1 + 1 <= 32 )
        {
            v1 = (int *)(4 * (a1 + 1) + 8944280);
            do
            {
                v2 = *v1;
                ++v1;
                dword_887A98[a1] += v2;
            }
            while ( v1 <= (int *)&unk_887B18 );
        }
        v3 = 0;
        v4 = a1;
        if ( a1 > 0 )
        {
            do
            {
                v3 += dword_887A98[v4] << (a1 - v4);
                --v4;
            }
            while ( v4 );
        }
        if ( v3 != 1 << a1 )
        {
            v5 = a1 - 1;
            v6 = (-1 << a1) + v3;
            while ( 2 )
            {
                while ( 1 )
                {
                    v7 = a1 - 1;
                    --dword_887A98[a1];
                    if ( v5 > 0 )
                        break;
LABEL_16:
                    if ( !--v6 )
                        return;
                }
                v8 = (int *)(4 * v5 + 8944280);
                do
                {
                    if ( *v8 )
                    {
                        --dword_887A98[v7];
                        dword_887A9C[v7] += 2;
                        goto LABEL_16;
                    }
                    --v8;
                    --v7;
                }
                while ( v8 > dword_887A98 );
                if ( --v6 )
                    continue;
                break;
            }
        }
    }
}

void sub_548D60()
{
    int v0; // ebx@1
    int v1; // esi@1
    int v2; // edi@1
    int v3; // ecx@2
    int v4; // ecx@4
    int v5; // eax@7
    int v6; // ecx@9
    DWORD *v7; // ST04_4@11
    DWORD *v8; // eax@11
    int *v9; // ecx@12
    int v10; // ebp@12
    int v11; // ST0C_4@14
    int v12; // ST0C_4@18
    int v13; // ST0C_4@21
    int v14; // [sp+10h] [bp-8h]@11
    int v15; // [sp+14h] [bp-4h]@11

    v0 = 255;
    v1 = 0;
    v2 = 0;
    sub_548750((void *)(dword_887A80 + 224288), 0, 0x13u);
    for ( *(DWORD *)(dword_887A80 + 229640) = 285;
                *(DWORD *)(dword_887A80 + 229640) >= 0;
                *(DWORD *)(dword_887A80 + 229640) = v3 - 1 )
    {
        v3 = *(DWORD *)(dword_887A80 + 229640);
        if ( *(DWORD *)(dword_887A80 + 4 * v3 + 224364) )
            break;
    }
    v4 = *(DWORD *)(dword_887A80 + 229640) + 1;
    if ( v4 <= 257 )
        v4 = 257;
    *(DWORD *)(dword_887A80 + 229640) = v4;
    for ( *(DWORD *)(dword_887A80 + 229644) = 29;
                *(DWORD *)(dword_887A80 + 229644) >= 0;
                *(DWORD *)(dword_887A80 + 229644) = v5 - 1 )
    {
        v5 = *(DWORD *)(dword_887A80 + 229644);
        if ( *(DWORD *)(dword_887A80 + 4 * v5 + 225516) )
            break;
    }
    v6 = *(DWORD *)(dword_887A80 + 229644) + 1;
    if ( v6 <= 1 )
        v6 = 1;
    *(DWORD *)(dword_887A80 + 229644) = v6;
    sub_549020(
        (DWORD *)(dword_887A80 + 227076),
        (DWORD *)(dword_887A80 + 227076),
        (int *)(dword_887A80 + 224364),
        *(DWORD *)(dword_887A80 + 229640));
    v7 = (DWORD *)(dword_887A80 + 4 * *(DWORD *)(dword_887A80 + 229640) + 227076);
    sub_549020(v7, v7, (int *)(dword_887A80 + 225516), *(DWORD *)(dword_887A80 + 229644));
    v8 = (DWORD *)(dword_887A80 + 228356);
    v14 = dword_887A80 + 227076;
    v15 = *(DWORD *)(dword_887A80 + 229644) + *(DWORD *)(dword_887A80 + 229640);
    if ( v15 > 0 )
    {
        do
        {
            v9 = (int *)v14;
            v14 += 4;
            v10 = *v9;
            if ( *v9 )
            {
                if ( v1 )
                {
                    v12 = v1;
                    v1 = 0;
                    v8 = sub_5490A0((int)v8, v12);
                }
                if ( v0 == v10 )
                {
                    if ( ++v2 == 6 )
                    {
                        v2 = 0;
                        v8 = sub_549040((int)v8, v0, 6);
                    }
                }
                else
                {
                    if ( v2 )
                    {
                        v13 = v2;
                        v2 = 0;
                        v8 = sub_549040((int)v8, v0, v13);
                    }
                    ++v8;
                    ++*(DWORD *)(dword_887A80 + 4 * v10 + 224288);
                    *(v8 - 1) = v10;
                }
            }
            else
            {
                if ( v2 )
                {
                    v11 = v2;
                    v2 = 0;
                    v8 = sub_549040((int)v8, v0, v11);
                }
                if ( ++v1 == 138 )
                {
                    v1 = 0;
                    v8 = sub_5490A0((int)v8, 138);
                }
            }
            v0 = v10;
            --v15;
        }
        while ( v15 );
    }
    if ( v2 )
    {
        v8 = sub_549040((int)v8, v0, v2);
    }
    else if ( v1 )
    {
        v8 = sub_5490A0((int)v8, v1);
    }
    *(DWORD *)(dword_887A80 + 229636) = v8;
    sub_548B00(19, dword_887A80 + 224288, (DWORD *)(dword_887A80 + 225644));
    sub_548770(19, (int *)(dword_887A80 + 225644));
    sub_548CB0(7);
    sub_548800(19, (int *)(dword_887A80 + 225644), 7, (void *)(dword_887A80 + 227000));
}

DWORD *sub_549020(DWORD *result, DWORD *a2, int *a3, int a4)
{
    int v4; // edx@1
    int *v5; // ecx@2
    int v6; // esi@3

    v4 = a4;
    if ( a4 )
    {
        result = a2;
        v5 = a3;
        do
        {
            v6 = *v5;
            ++v5;
            *result = v6;
            ++result;
            --v4;
        }
        while ( v4 );
    }
    return result;
}

DWORD *sub_549040(int a1, int a2, int a3)
{
    int v3; // esi@2
    DWORD *result; // eax@2
    int v5; // ecx@3
    DWORD *v6; // eax@5

    if ( a3 >= 3 )
    {
        ++*(DWORD *)(dword_887A80 + 224352);
        v6 = (DWORD *)(a1 + 4);
        *(v6 - 1) = 16;
        *v6 = a3 - 3;
        result = (DWORD *)(a1 + 8);
    }
    else
    {
        *(DWORD *)(dword_887A80 + 4 * a2 + 224288) += a3;
        v3 = a3 - 1;
        result = (DWORD *)a1;
        if ( a3 )
        {
            do
            {
                *result = a2;
                ++result;
                v5 = v3--;
            }
            while ( v5 );
        }
    }
    return result;
}

DWORD *sub_5490A0(int a1, int a2)
{
    int v2; // edx@2
    DWORD *result; // eax@2
    int v4; // ecx@3
    DWORD *v5; // eax@6
    DWORD *v6; // eax@7

    if ( a2 >= 3 )
    {
        if ( a2 > 10 )
        {
            ++*(DWORD *)(dword_887A80 + 224360);
            v6 = (DWORD *)(a1 + 4);
            *(v6 - 1) = 18;
            *v6 = a2 - 11;
            result = (DWORD *)(a1 + 8);
        }
        else
        {
            ++*(DWORD *)(dword_887A80 + 224356);
            v5 = (DWORD *)(a1 + 4);
            *(v5 - 1) = 17;
            *v5 = a2 - 3;
            result = (DWORD *)(a1 + 8);
        }
    }
    else
    {
        *(DWORD *)(dword_887A80 + 224288) += a2;
        v2 = a2 - 1;
        result = (DWORD *)a1;
        if ( a2 )
        {
            do
            {
                *result = 0;
                ++result;
                v4 = v2--;
            }
            while ( v4 );
        }
    }
    return result;
}

int sub_549120()
{
    int result; // eax@2

    if ( sub_547D80(2, 2) )
        result = 1;
    else
        result = (unsigned int)sub_549150() >= 1;
    return result;
}

int sub_549150()
{
    int result; // eax@2
    int v1; // esi@5
    int v2; // esi@8
    int v3; // edi@12
    int *v4; // esi@15
    int v5; // edi@17
    int v6; // ecx@19
    int v7; // ecx@23
    int v8; // ecx@26

    if ( sub_547D80(*(DWORD *)(dword_887A80 + 229640) - 257, 5) )
    {
        result = 1;
    }
    else if ( sub_547D80(*(DWORD *)(dword_887A80 + 229644) - 1, 5) )
    {
        result = 1;
    }
    else
    {
        v1 = 18;
        do
        {
            if ( *(DWORD *)(dword_887A80 + 4 * (unsigned char)byte_58EF30[v1] + 225644) )
                break;
            --v1;
        }
        while ( v1 >= 0 );
        v2 = v1 + 1;
        if ( v2 <= 4 )
            v2 = 4;
        if ( sub_547D80(v2 - 4, 4) )
        {
            result = 1;
        }
        else
        {
            v3 = 0;
            if ( v2 <= 0 )
            {
LABEL_15:
                v4 = (int *)(dword_887A80 + 228356);
                while ( *(DWORD *)(dword_887A80 + 229636) > (unsigned int)v4 )
                {
                    v5 = *v4;
                    ++v4;
                    if ( sub_547D80(*(DWORD *)(dword_887A80 + 4 * v5 + 227000), *(DWORD *)(dword_887A80 + 4 * v5 + 225644)) )
                        return 1;
                    switch ( v5 )
                    {
                        case 16:
                            v6 = *v4;
                            ++v4;
                            if ( sub_547D80(v6, 2) )
                                return 1;
                            break;
                        case 17:
                            v7 = *v4;
                            ++v4;
                            if ( sub_547D80(v7, 3) )
                                return 1;
                            break;
                        case 18:
                            v8 = *v4;
                            ++v4;
                            if ( sub_547D80(v8, 7) )
                                return 1;
                            break;
                    }
                }
                result = 0;
            }
            else
            {
                while ( !sub_547D80(*(DWORD *)(dword_887A80 + 4 * (unsigned char)byte_58EF30[v3] + 225644), 3) )
                {
                    if ( ++v3 >= v2 )
                        goto LABEL_15;
                }
                result = 1;
            }
        }
    }
    return result;
}

int sub_5492F0()
{
    int result; // eax@2
    int v1; // ecx@12
    int v2; // ecx@20
    int v3; // esi@20
    int v4; // edi@20
    char v5; // cl@25

    if ( sub_547D80(0, 2) )
    {
        result = 1;
    }
    else if ( sub_547D50() )
    {
        result = 1;
    }
    else
    {
        while ( --dword_887A88 < 0 )
        {
            ++dword_887A88;
            if ( sub_547CF0() )
                return 1;
        }
        *(BYTE *)dword_887A90++ = *(BYTE *)(dword_887A80 + 223004);
        while ( --dword_887A88 < 0 )
        {
            ++dword_887A88;
            if ( sub_547CF0() )
                return 1;
        }
        v1 = *(DWORD *)(dword_887A80 + 223004);
        *(BYTE *)dword_887A90++ = BYTE1(v1);
        while ( --dword_887A88 < 0 )
        {
            ++dword_887A88;
            if ( sub_547CF0() )
                return 1;
        }
        *(BYTE *)dword_887A90++ = ~(unsigned char)*(DWORD *)(dword_887A80 + 223004);
        while ( --dword_887A88 < 0 )
        {
            ++dword_887A88;
            if ( sub_547CF0() )
                return 1;
        }
        v2 = *(DWORD *)(dword_887A80 + 223004);
        *(BYTE *)dword_887A90++ = ~BYTE1(v2);
        v3 = *(DWORD *)(dword_887A80 + 222996);
        v4 = *(DWORD *)(dword_887A80 + 223004);
        while ( v4 > 0 )
        {
            while ( --dword_887A88 < 0 )
            {
                ++dword_887A88;
                if ( sub_547CF0() )
                    return 1;
            }
            v5 = *(BYTE *)(dword_887A94[0] + v3);
            --v4;
            v3 = ((WORD)v3 + 1) & 0x7FFF;
            *(BYTE *)dword_887A90++ = v5;
        }
        result = 0;
    }
    return result;
}

int sub_549460(int a1)
{
    int v1; // ecx@1
    int result; // eax@3
    unsigned int v3; // edx@6
    int v4; // esi@15
    short v5; // di@15
    int v6; // eax@24
    int v7; // ecx@29

    v1 = (a1 - *(DWORD *)(dword_887A80 + 229664)) & 0x7FFF;
    *(DWORD *)(dword_887A80 + 229668) += v1;
    *(DWORD *)(dword_887A80 + 229672) = v1 + *(DWORD *)(dword_887A80 + 229664) + 3837;
    if ( *(DWORD *)(dword_887A80 + 229692) )
    {
        if ( dword_886C60 >= 4 )
            result = sub_549B70();
        else
            result = sub_549F40();
    }
    else
    {
        while ( *(DWORD *)(dword_887A80 + 229668) )
        {
            v3 = *(DWORD *)(dword_887A80 + 229664);
            if ( *(DWORD *)(dword_887A80 + 229672) <= v3 )
                break;
            if ( *(WORD *)(dword_886CF0 + 2 * (*(DWORD *)(dword_887A80 + 229664) & 0x7FFF)) == -1 )
            {
                **(BYTE **)(dword_887A80 + 221444) = *(BYTE *)(dword_887A94[0] + v3);
                ++*(DWORD *)(dword_887A80 + 229664);
                ++*(DWORD *)(dword_887A80 + 221444);
                --*(DWORD *)(dword_887A80 + 229668);
                ++*(DWORD *)(dword_887A80 + 223004);
                **(DWORD **)(dword_887A80 + 222988) *= 2;
                if ( !--*(DWORD *)(dword_887A80 + 222992) && sub_549B20() )
                    return 1;
            }
            else
            {
                dword_887B1C = 2;
                sub_549970(*(DWORD *)(dword_887A80 + 229664));
                if ( dword_887B1C == 2 )
                {
                    *(BYTE *)(*(DWORD *)(dword_887A80 + 221444))++ = *(BYTE *)((*(DWORD *)(dword_887A80 + 229664))++
                                                                                                                                            + dword_887A94[0]);
                    --*(DWORD *)(dword_887A80 + 229668);
                    ++*(DWORD *)(dword_887A80 + 223004);
                    **(DWORD **)(dword_887A80 + 222988) *= 2;
                    if ( !--*(DWORD *)(dword_887A80 + 222992) && sub_549B20() )
                        return 1;
                }
                else
                {
                    v4 = dword_887B1C;
                    v5 = dword_887FA8;
                    while ( v4 < 128 && *(WORD *)(dword_886CF0 + 2 * ((*(WORD *)(dword_887A80 + 229664) + 1) & 0x7FFF)) != -1 )
                    {
                        sub_549970(*(DWORD *)(dword_887A80 + 229664) + 1);
                        if ( dword_887B1C > *(DWORD *)(dword_887A80 + 229668) - 1 )
                            dword_887B1C = *(DWORD *)(dword_887A80 + 229668) - 1;
                        if ( dword_887B1C <= v4 )
                            break;
                        v4 = dword_887B1C;
                        v5 = dword_887FA8;
                        *(BYTE *)(*(DWORD *)(dword_887A80 + 221444))++ = *(BYTE *)((*(DWORD *)(dword_887A80 + 229664))++
                                                                                                                                                + dword_887A94[0]);
                        --*(DWORD *)(dword_887A80 + 229668);
                        ++*(DWORD *)(dword_887A80 + 223004);
                        **(DWORD **)(dword_887A80 + 222988) *= 2;
                        if ( !--*(DWORD *)(dword_887A80 + 222992) && sub_549B20() )
                            return 1;
                    }
                    v6 = *(DWORD *)(dword_887A80 + 229668);
                    if ( v4 <= v6 || (v4 = *(DWORD *)(dword_887A80 + 229668), v6 > 2) )
                    {
                        v7 = ((unsigned short)*(DWORD *)(dword_887A80 + 229664) - v5) & 0x7FFF;
                        if ( v4 != 3 || v7 < 0x4000 )
                        {
                            *(BYTE *)(*(DWORD *)(dword_887A80 + 221444))++ = v4 - 3;
                            **(WORD **)(dword_887A80 + 221444) = v7;
                            *(DWORD *)(dword_887A80 + 221444) += 2;
                            *(DWORD *)(dword_887A80 + 229664) += v4;
                            *(DWORD *)(dword_887A80 + 229668) -= v4;
                            *(DWORD *)(dword_887A80 + 223004) += v4;
                            **(DWORD **)(dword_887A80 + 222988) = 2 * **(DWORD **)(dword_887A80 + 222988) | 1;
                            if ( !--*(DWORD *)(dword_887A80 + 222992) && sub_549B20() )
                                return 1;
                        }
                        else
                        {
                            *(BYTE *)(*(DWORD *)(dword_887A80 + 221444))++ = *(BYTE *)(dword_887A94[0]
                                                                                                                                                    + (*(DWORD *)(dword_887A80 + 229664))++);
                            --*(DWORD *)(dword_887A80 + 229668);
                            ++*(DWORD *)(dword_887A80 + 223004);
                            **(DWORD **)(dword_887A80 + 222988) *= 2;
                            if ( !--*(DWORD *)(dword_887A80 + 222992) && sub_549B20() )
                                return 1;
                        }
                    }
                    else
                    {
                        *(BYTE *)(*(DWORD *)(dword_887A80 + 221444))++ = *(BYTE *)((*(DWORD *)(dword_887A80 + 229664))++
                                                                                                                                                + dword_887A94[0]);
                        --*(DWORD *)(dword_887A80 + 229668);
                        ++*(DWORD *)(dword_887A80 + 223004);
                        **(DWORD **)(dword_887A80 + 222988) *= 2;
                        if ( !--*(DWORD *)(dword_887A80 + 222992) && sub_549B20() )
                            return 1;
                    }
                }
            }
        }
        *(DWORD *)(dword_887A80 + 229664) &= 0x7FFFu;
        result = 0;
    }
    return result;
}

short sub_549970(int a1)
{
    int v1; // ecx@1
    int v2; // edx@1
    int v3; // eax@1
    int v4; // esi@1
    unsigned short v5; // bx@9
    WORD *v6; // ebx@11
    int v7; // edi@12
    short v8; // bp@13
    short v9; // bp@14
    short v10; // bp@15
    short v11; // bp@16
    int v12; // edi@19
    short v14; // [sp+10h] [bp-8h]@1
    short v15; // [sp+12h] [bp-6h]@1

    v1 = dword_886C60;
    v2 = a1 & 0x7FFF;
    v15 = *(WORD *)(a1 + dword_887B1C + dword_887A94[0] - 1);
    LOWORD(v3) = dword_887B1C;
    v14 = *(WORD *)(dword_887A94[0] + a1);
    v4 = dword_887B1C + dword_887A94[0] - 1;
    while ( v1 > 0 )
    {
        --v1;
        LOWORD(v3) = *(WORD *)(dword_886CF0 + 2 * v2);
        v2 = (unsigned short)v3;
        if ( (unsigned short)v3 == 0xFFFF )
            break;
        LOWORD(v3) = v15;
        if ( *(WORD *)(v4 + v2) == v15 )
            goto LABEL_25;
        --v1;
        LOWORD(v3) = *(WORD *)(dword_886CF0 + 2 * v2);
        v2 = (unsigned short)v3;
        if ( (unsigned short)v3 == 0xFFFF )
            return v3;
        LOWORD(v3) = v15;
        if ( *(WORD *)(v4 + v2) == v15 )
            goto LABEL_25;
        --v1;
        LOWORD(v3) = *(WORD *)(dword_886CF0 + 2 * v2);
        v2 = (unsigned short)v3;
        if ( (unsigned short)v3 == 0xFFFF )
            return v3;
        LOWORD(v3) = v15;
        if ( *(WORD *)(v4 + v2) == v15 )
            goto LABEL_25;
        --v1;
        v5 = *(WORD *)(dword_886CF0 + 2 * v2);
        v2 = v5;
        if ( v5 == 0xFFFF )
            return v3;
        LOWORD(v3) = v15;
        if ( *(WORD *)(v4 + v5) == v15 )
        {
LABEL_25:
            v6 = (WORD *)(v2 + dword_887A94[0]);
            if ( *(WORD *)(v2 + dword_887A94[0]) == v14 )
            {
                v7 = dword_887A94[0] + a1;
                v3 = 32;
                do
                {
                    v8 = *(WORD *)(v7 + 2);
                    v7 += 2;
                    ++v6;
                    if ( *v6 != v8 )
                        break;
                    v9 = *(WORD *)(v7 + 2);
                    v7 += 2;
                    ++v6;
                    if ( *v6 != v9 )
                        break;
                    v10 = *(WORD *)(v7 + 2);
                    v7 += 2;
                    ++v6;
                    if ( *v6 != v10 )
                        break;
                    v11 = *(WORD *)(v7 + 2);
                    v7 += 2;
                    ++v6;
                    if ( *v6 != v11 )
                        break;
                    --v3;
                }
                while ( v3 > 0 );
                if ( !v3 )
                {
                    dword_887B1C = 258;
                    dword_887FA8 = v2;
                    return v3;
                }
                v3 = (unsigned char)(*(BYTE *)v6 - *(BYTE *)v7) < 1u;
                v12 = v3 + ((v7 - (dword_887A94[0] + a1)) & 0xFFFFFFFE);
                if ( v12 > dword_887B1C )
                {
                    dword_887FA8 = v2;
                    dword_887B1C = v12;
                    LOWORD(v3) = *(WORD *)(v12 + a1 + dword_887A94[0] - 1);
                    v4 = v12 + dword_887A94[0] - 1;
                    v15 = *(WORD *)(v12 + a1 + dword_887A94[0] - 1);
                }
            }
        }
    }
    return v3;
}

int sub_549B20()
{
    int result; // eax@2

    *(DWORD *)(dword_887A80 + 222988) += 4;
    *(DWORD *)(dword_887A80 + 222992) = 32;
    *(DWORD *)(dword_887A80 + 221448) += 32;
    if ( *(DWORD *)(dword_887A80 + 221448) == 12288 )
        result = sub_5480B0(0);
    else
        result = 0;
    return result;
}

int sub_549B70()
{
    unsigned int v0; // ecx@2
    int v2; // eax@11
    int v3; // ecx@16

    while ( *(DWORD *)(dword_887A80 + 229668) )
    {
        v0 = *(DWORD *)(dword_887A80 + 229664);
        if ( *(DWORD *)(dword_887A80 + 229672) <= v0 )
            break;
        if ( *(WORD *)(dword_886CF0 + 2 * (v0 & 0x7FFF)) == -1 )
        {
            **(BYTE **)(dword_887A80 + 221444) = *(BYTE *)(dword_887A94[0] + v0);
            ++*(DWORD *)(dword_887A80 + 229664);
            ++*(DWORD *)(dword_887A80 + 221444);
            --*(DWORD *)(dword_887A80 + 229668);
            ++*(DWORD *)(dword_887A80 + 223004);
            **(DWORD **)(dword_887A80 + 222988) *= 2;
            if ( !--*(DWORD *)(dword_887A80 + 222992) && sub_549B20() )
                return 1;
        }
        else
        {
            dword_887B1C = 2;
            sub_549970(*(DWORD *)(dword_887A80 + 229664));
            if ( dword_887B1C == 2 )
            {
                *(BYTE *)(*(DWORD *)(dword_887A80 + 221444))++ = *(BYTE *)((*(DWORD *)(dword_887A80 + 229664))++
                                                                                                                                        + dword_887A94[0]);
                --*(DWORD *)(dword_887A80 + 229668);
                ++*(DWORD *)(dword_887A80 + 223004);
                **(DWORD **)(dword_887A80 + 222988) *= 2;
                if ( !--*(DWORD *)(dword_887A80 + 222992) && sub_549B20() )
                    return 1;
            }
            else
            {
                v2 = *(DWORD *)(dword_887A80 + 229668);
                if ( dword_887B1C <= v2 || (dword_887B1C = *(DWORD *)(dword_887A80 + 229668), v2 > 2) )
                {
                    v3 = ((unsigned short)*(DWORD *)(dword_887A80 + 229664) - (WORD)dword_887FA8) & 0x7FFF;
                    if ( dword_887B1C != 3 || v3 < 0x4000 )
                    {
                        *(BYTE *)(*(DWORD *)(dword_887A80 + 221444))++ = dword_887B1C - 3;
                        **(WORD **)(dword_887A80 + 221444) = v3;
                        *(DWORD *)(dword_887A80 + 221444) += 2;
                        *(DWORD *)(dword_887A80 + 229664) += dword_887B1C;
                        *(DWORD *)(dword_887A80 + 229668) -= dword_887B1C;
                        *(DWORD *)(dword_887A80 + 223004) += dword_887B1C;
                        **(DWORD **)(dword_887A80 + 222988) = 2 * **(DWORD **)(dword_887A80 + 222988) | 1;
                        if ( !--*(DWORD *)(dword_887A80 + 222992) && sub_549B20() )
                            return 1;
                    }
                    else
                    {
                        *(BYTE *)(*(DWORD *)(dword_887A80 + 221444))++ = *(BYTE *)(dword_887A94[0]
                                                                                                                                                + (*(DWORD *)(dword_887A80 + 229664))++);
                        --*(DWORD *)(dword_887A80 + 229668);
                        ++*(DWORD *)(dword_887A80 + 223004);
                        **(DWORD **)(dword_887A80 + 222988) *= 2;
                        if ( !--*(DWORD *)(dword_887A80 + 222992) && sub_549B20() )
                            return 1;
                    }
                }
                else
                {
                    *(BYTE *)(*(DWORD *)(dword_887A80 + 221444))++ = *(BYTE *)((*(DWORD *)(dword_887A80 + 229664))++
                                                                                                                                            + dword_887A94[0]);
                    --*(DWORD *)(dword_887A80 + 229668);
                    ++*(DWORD *)(dword_887A80 + 223004);
                    **(DWORD **)(dword_887A80 + 222988) *= 2;
                    if ( !--*(DWORD *)(dword_887A80 + 222992) && sub_549B20() )
                        return 1;
                }
            }
        }
    }
    *(DWORD *)(dword_887A80 + 229664) &= 0x7FFFu;
    return 0;
}

int sub_549F40()
{
    int *v0; // edx@1
    unsigned int v1; // ebx@2
    int *v2; // ecx@2
    WORD *v4; // ebp@7
    WORD *v5; // eax@7
    int v6; // eax@20
    int v7; // eax@25
    int v8; // ecx@25

    while ( 1 )
    {
        v0 = (signed int *)(dword_887A80 + 229668);
        if ( !*(DWORD *)(dword_887A80 + 229668) )
            break;
        v1 = *(DWORD *)(dword_887A80 + 229664);
        v2 = (int *)(dword_887A80 + 229664);
        if ( *(DWORD *)(dword_887A80 + 229672) <= v1 )
            break;
        dword_887FA8 = *(WORD *)(dword_886CF0 + 2 * (v1 & 0x7FFF));
        if ( dword_887FA8 == 0xFFFF )
        {
            **(BYTE **)(dword_887A80 + 221444) = *(BYTE *)(*v2 + dword_887A94[0]);
            ++*(DWORD *)(dword_887A80 + 229664);
            ++*(DWORD *)(dword_887A80 + 221444);
            --*(DWORD *)(dword_887A80 + 229668);
            ++*(DWORD *)(dword_887A80 + 223004);
            **(DWORD **)(dword_887A80 + 222988) *= 2;
            if ( !--*(DWORD *)(dword_887A80 + 222992) && sub_549B20() )
                return 1;
        }
        else
        {
            v4 = (WORD *)(dword_887A94[0] + dword_887FA8);
            v5 = (WORD *)(dword_887A94[0] + *v2);
            if ( *(WORD *)(dword_887A94[0] + dword_887FA8) == *v5 )
            {
                dword_887B1C = 32;
                do
                {
                    ++v4;
                    ++v5;
                    if ( *v5 != *v4 )
                        break;
                    ++v4;
                    ++v5;
                    if ( *v5 != *v4 )
                        break;
                    ++v4;
                    ++v5;
                    if ( *v5 != *v4 )
                        break;
                    ++v4;
                    ++v5;
                    if ( *v5 != *v4 )
                        break;
                    --dword_887B1C;
                }
                while ( dword_887B1C > 0 );
                if ( dword_887B1C )
                    dword_887B1C = ((unsigned char)(*(BYTE *)v5 - *(BYTE *)v4) < 1u)
                                             + (((unsigned int)v4 + -dword_887FA8 - dword_887A94[0]) & 0xFFFFFFFE);
                else
                    dword_887B1C = 258;
                v6 = *v0;
                if ( dword_887B1C <= *v0 || (dword_887B1C = *v0, v6 > 2) )
                {
                    v7 = *v2;
                    v8 = ((unsigned short)*v2 - (WORD)dword_887FA8) & 0x7FFF;
                    if ( dword_887B1C != 3 || v8 < 0x4000 )
                    {
                        *(BYTE *)(*(DWORD *)(dword_887A80 + 221444))++ = dword_887B1C - 3;
                        **(WORD **)(dword_887A80 + 221444) = v8;
                        *(DWORD *)(dword_887A80 + 221444) += 2;
                        *(DWORD *)(dword_887A80 + 229664) += dword_887B1C;
                        *(DWORD *)(dword_887A80 + 229668) -= dword_887B1C;
                        *(DWORD *)(dword_887A80 + 223004) += dword_887B1C;
                        **(DWORD **)(dword_887A80 + 222988) = 2 * **(DWORD **)(dword_887A80 + 222988) | 1;
                        if ( !--*(DWORD *)(dword_887A80 + 222992) && sub_549B20() )
                            return 1;
                    }
                    else
                    {
                        **(BYTE **)(dword_887A80 + 221444) = *(BYTE *)(dword_887A94[0] + v7);
                        ++*(DWORD *)(dword_887A80 + 229664);
                        ++*(DWORD *)(dword_887A80 + 221444);
                        --*(DWORD *)(dword_887A80 + 229668);
                        ++*(DWORD *)(dword_887A80 + 223004);
                        **(DWORD **)(dword_887A80 + 222988) *= 2;
                        if ( !--*(DWORD *)(dword_887A80 + 222992) && sub_549B20() )
                            return 1;
                    }
                }
                else
                {
                    **(BYTE **)(dword_887A80 + 221444) = *(BYTE *)(*v2 + dword_887A94[0]);
                    ++*(DWORD *)(dword_887A80 + 229664);
                    ++*(DWORD *)(dword_887A80 + 221444);
                    --*(DWORD *)(dword_887A80 + 229668);
                    ++*(DWORD *)(dword_887A80 + 223004);
                    **(DWORD **)(dword_887A80 + 222988) *= 2;
                    if ( !--*(DWORD *)(dword_887A80 + 222992) && sub_549B20() )
                        return 1;
                }
            }
            else
            {
                **(BYTE **)(dword_887A80 + 221444) = *v5;
                ++*(DWORD *)(dword_887A80 + 229664);
                ++*(DWORD *)(dword_887A80 + 221444);
                --*(DWORD *)(dword_887A80 + 229668);
                ++*(DWORD *)(dword_887A80 + 223004);
                **(DWORD **)(dword_887A80 + 222988) *= 2;
                if ( !--*(DWORD *)(dword_887A80 + 222992) && sub_549B20() )
                    return 1;
            }
        }
    }
    *(DWORD *)(dword_887A80 + 229664) &= 0x7FFFu;
    return 0;
}

void sub_54A360()
{
    *(DWORD *)(dword_887A80 + 229672) = 0xFFFF;
    JUMPOUT(&loc_5494A0);
}

int sub_54A380()
{
    int v0; // esi@1
    int result; // eax@6

    v0 = *(DWORD *)(dword_887A80 + 229720);
    if ( v0 >= *(DWORD *)(dword_887A80 + 229712) )
        v0 = *(DWORD *)(dword_887A80 + 229712);
    sub_547C90((DWORD *)(dword_887A94[0] + *(DWORD *)(dword_887A80 + 229708)), *(BYTE **)(dword_887A80 + 229716), v0);
    *(DWORD *)(dword_887A80 + 229716) += v0;
    *(DWORD *)(dword_887A80 + 229720) -= v0;
    *(DWORD *)(dword_887A80 + 229708) = ((WORD)v0 + (unsigned short)*(DWORD *)(dword_887A80 + 229708)) & 0x7FFF;
    *(DWORD *)(dword_887A80 + 229712) -= v0;
    *(DWORD *)(dword_887A80 + 229668) += v0;
    if ( *(DWORD *)(dword_887A80 + 229712) )
    {
        if ( *(DWORD *)(dword_887A80 + 229696) )
            sub_54A450((void *)(dword_887A94[0] + *(DWORD *)(dword_887A80 + 229708)), 0, *(DWORD *)(dword_887A80 + 229712));
        result = 1;
    }
    else
    {
        *(DWORD *)(dword_887A80 + 229712) = 4096;
        result = 0;
    }
    return result;
}

void sub_54A450(void *a1, char a2, unsigned int a3)
{
    int v3; // ecx@0
    int v4; // eax@2

    if ( a3 )
    {
        LOBYTE(v3) = a2;
        BYTE1(v3) = a2;
        v4 = v3 << 16;
        LOWORD(v4) = v3;
        memset32(a1, v4, a3 >> 2);
        memset((char *)a1 + 4 * (a3 >> 2), a2, a3 & 3);
    }
}

int deflate_deinit(int a1)
{
    int result; // eax@1

    result = a1;
    dword_887A80 = a1;
    *(DWORD *)(a1 + 229752) = -1412623820;
    return result;
}

int deflate_init(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    int v7; // ecx@1
    int result; // eax@5

    v7 = a2;
    dword_887A80 = a1;
    if ( a2 <= 1 )
        v7 = 1;
    if ( v7 >= 1500 )
        v7 = 1500;
    *(DWORD *)(a1 + 229684) = v7;
    *(DWORD *)(dword_887A80 + 229688) = a3;
    *(DWORD *)(dword_887A80 + 229692) = a4;
    *(DWORD *)(dword_887A80 + 229732) = a5;
    *(DWORD *)(dword_887A80 + 229736) = a6;
    *(DWORD *)(dword_887A80 + 229744) = *(DWORD *)(dword_887A80 + 229732);
    *(DWORD *)(dword_887A80 + 229748) = *(DWORD *)(dword_887A80 + 229736);
    *(DWORD *)(dword_887A80 + 229740) = a7;
    *(DWORD *)(dword_887A80 + 229712) = 4096;
    sub_54A580();
    result = 0;
    *(DWORD *)(dword_887A80 + 229752) = 305419896;
    return result;
}

int sub_54A580()
{
    int v0; // ecx@1
    int v1; // eax@3
    int result; // eax@5

    v0 = 0;
    do
    {
        v0 += 2;
        *(WORD *)(dword_887A80 + v0 + 119040) = -1;
        *(WORD *)(dword_887A80 + v0 + 53504) = -1;
    }
    while ( v0 < 0x10000 );
    v1 = 0;
    do
    {
        v1 += 2;
        *(WORD *)(dword_887A80 + v1 + 37120) = -1;
    }
    while ( v1 < 0x4000 );
    *(DWORD *)(dword_887A80 + 222988) = dword_887A80 + 221452;
    *(DWORD *)(dword_887A80 + 222992) = 32;
    result = dword_887A80 + 184578;
    *(DWORD *)(dword_887A80 + 221444) = dword_887A80 + 184578;
    return result;
}

signed int deflate_buf_size()
{
    return 229756;
}

void sub_54A870(int a1, int a2)
{
    int v2; // ecx@1
    int v3; // eax@1
    int *v4; // esi@1
    int v5; // edi@2
    DWORD *v6; // esi@3
    int v7; // eax@3
    int *v8; // edi@3
    int v9; // ecx@3
    int v10; // eax@4
    int v11; // esi@5
    DWORD *v12; // esi@6
    unsigned int v13; // edx@6
    int v14; // edx@9
    DWORD *v15; // edi@9
    int v16; // ecx@9
    int *v17; // esi@9
    int v18; // eax@10
    DWORD *v19; // ebx@11
    int v20; // ebx@13
    char *v21; // esi@13
    int v22; // ecx@13
    int v23; // ebp@13
    int v24; // eax@14
    int v25; // esi@15
    unsigned int v26; // edx@15
    int v27; // ecx@15
    int v28; // edi@15
    unsigned char v29; // cf@16
    int v30; // ecx@17
    unsigned int v31; // ecx@18
    int v32; // edi@18
    int v33; // ebx@18
    unsigned char v34; // ah@23
    int *v35; // edi@23
    int v36; // edx@23
    int v37; // ebx@25
    int v38; // edi@26
    char *v39; // [sp-10h] [bp-28h]@15
    int v40; // [sp-Ch] [bp-24h]@15
    int v41; // [sp-8h] [bp-20h]@1
    int v42; // [sp-8h] [bp-20h]@9
    int v43; // [sp-8h] [bp-20h]@15

    memset((void *)(a2 + 33396), 0, 0x44u);
    v41 = a2;
    v2 = *(DWORD *)a1;
    v3 = a2 + 33396;
    v4 = *(int **)(a1 + 8);
    do
    {
        v5 = *v4;
        ++v4;
        ++*(DWORD *)(v3 + 4 * v5);
        --v2;
    }
    while ( v2 );
    v6 = (DWORD *)(v41 + 33400);
    v7 = 0;
    *(DWORD *)(v41 + 33332) = 0;
    v8 = (int *)(v41 + 33336);
    v9 = 15;
    do
    {
        v10 = *v6 + v7;
        ++v6;
        v7 = 2 * v10;
        *v8 = v7;
        ++v8;
        --v9;
    }
    while ( v9 );
    v11 = v41;
    if ( v7 == 0x10000 )
        goto LABEL_34;
    v12 = (DWORD *)(v41 + 33400);
    LOBYTE(v9) = 16;
    v13 = 0;
    do
    {
        v13 += *v12;
        ++v12;
        --v9;
    }
    while ( v9 );
    v11 = v41;
    if ( v13 <= 1 )
    {
LABEL_34:
        v42 = a1;
        v14 = v11 + 33328;
        v15 = *(DWORD **)(a1 + 4);
        v16 = *(DWORD *)a1;
        v17 = *(int **)(a1 + 8);
        do
        {
            v18 = *v17;
            ++v17;
            if ( v18 )
            {
                v19 = (DWORD *)(v14 + 4 * v18);
                v18 = (*v19)++;
            }
            *v15 = v18;
            ++v15;
            --v16;
        }
        while ( v16 );
        v20 = v42;
        memset(*(void **)(v42 + 12), 0, 0x400u);
        memset(*(void **)(v42 + 16), 0, 8 * *(DWORD *)v42);
        v21 = *(char **)(v42 + 8);
        v22 = *(DWORD *)v42;
        v23 = -1;
        do
        {
            v24 = *(DWORD *)v21;
            v21 += 4;
            if ( v24 )
            {
                v43 = v22;
                v40 = v20;
                v39 = v21;
                v25 = (int)&v21[-*(DWORD *)(v20 + 8) - 4];
                v26 = *(DWORD *)(*(DWORD *)(v20 + 4) + v25);
                v27 = v24;
                v28 = 0;
                do
                {
                    v29 = v26 & 1;
                    v26 >>= 1;
                    v28 = __RCL__(v28, v29);
                    --v27;
                }
                while ( v27 );
                v30 = v24;
                if ( (unsigned char)v24 > 8u )
                {
                    v34 = BYTE1(v28);
                    v35 = (signed int *)(*(DWORD *)(v20 + 12) + 4 * (unsigned char)v28);
                    v36 = *v35;
                    if ( !*v35 )
                    {
                        *v35 = v23;
                        v36 = v23;
                        v23 -= 2;
                    }
                    v37 = *(DWORD *)(v20 + 16);
                    LOBYTE(v30) = v30 - 9;
                    if ( (BYTE)v30 )
                    {
                        do
                        {
                            do
                            {
                                v29 = v34 & 1;
                                v34 >>= 1;
                                v38 = v29 + ~v36;
                                v36 = *(DWORD *)(v37 + 4 * v38);
                                --v30;
                            }
                            while ( v36 == 0 && v30 );
                            if ( v36 )
                                break;
                            *(DWORD *)(v37 + 4 * v38) = v23;
                            v36 = v23;
                            v23 -= 2;
                        }
                        while ( v30 );
                    }
                    *(DWORD *)(v37 + 4 * ((v34 & 1) + ~v36)) = v25;
                }
                else
                {
                    v31 = 0x100u >> v24;
                    v32 = 4 * v28;
                    v33 = *(DWORD *)(v20 + 12);
                    do
                    {
                        *(DWORD *)(v32 + v33) = v25;
                        v32 += 4 << v24;
                        --v31;
                    }
                    while ( v31 );
                }
                v21 = v39;
                v20 = v40;
                v22 = v43;
            }
            --v22;
        }
        while ( v22 );
    }
}

void sub_54A9DE(int a1)
{
    int v1; // ebp@1

    v1 = *(DWORD *)(a1 + 44424);
    **(DWORD **)(v1 + 16) = *(DWORD *)(a1 + 33324) - *(DWORD *)(a1 + 33316);
    **(DWORD **)(v1 + 28) = *(DWORD *)(a1 + 33304) - *(DWORD *)(a1 + 33296);
}

//error "54AA32: positive sp value has been found (funcsize=0)"

//error "54AA63: positive sp value has been found (funcsize=1)"

void sub_54AAA1(unsigned int a1, BYTE *a2, BYTE *a3)
{
    while ( a1 )
    {
        if ( !((unsigned char)a2 & 3) )
        {
            qmemcpy(a2, a3, a1);
            return;
        }
        *a2++ = *a3++;
        --a1;
    }
}

//error "54B172: positive sp value has been found (funcsize=20)"

int sub_54AB0C(short a1, unsigned int a2)
{
    bool v2; // cf@1
    int result; // eax@2

    v2 = HIBYTE(a1) < (unsigned char)a1;
    HIBYTE(a1) -= a1;
    if ( v2 || HIBYTE(a1) == 0 )
    {
        LOBYTE(a1) = HIBYTE(a1) + a1;
        result = sub_54AABC(a1, a2 >> a1);
    }
    return result;
}

int sub_54AB24(short a1, unsigned int a2)
{
    LOBYTE(a1) = HIBYTE(a1);
    return sub_54AABC(a1, a2 >> SHIBYTE(a1));
}

unsigned int sub_54AB34(short a1, unsigned int a2)
{
    unsigned int result; // eax@2
    bool v3; // cf@2
    short v4; // cx@5
    char v5; // t0@5
    unsigned int v6; // edx@5
    unsigned int v7; // edx@5
    char v8; // ch@5
    short v9; // cx@5

    if ( (unsigned char)a1 > 8u )
    {
        v5 = a1 - 8;
        LOBYTE(v4) = HIBYTE(a1);
        HIBYTE(v4) = v5;
        result = sub_54AABC(v4, a2 >> v4);
        v7 = v6 >> (8 - BYTE1(result));
        LOBYTE(v9) = v8;
        HIBYTE(v9) = BYTE1(result);
        BYTE1(result) = v7 & ((1 << v9) - 1);
        v3 = HIBYTE(v9) < (unsigned char)v9;
        HIBYTE(v9) -= v9;
        if ( v3 || HIBYTE(v9) == 0 )
        {
            LOBYTE(v9) = HIBYTE(v9) + v9;
            result = sub_54AABC(v9, v7 >> v9);
        }
    }
    else
    {
        result = a2 & ((1 << a1) - 1);
        v3 = HIBYTE(a1) < (unsigned char)a1;
        HIBYTE(a1) -= a1;
        if ( v3 || HIBYTE(a1) == 0 )
        {
            LOBYTE(a1) = HIBYTE(a1) + a1;
            result = sub_54AABC(a1, a2 >> a1);
        }
    }
    return result;
}

unsigned int sub_54AB98(unsigned char a1, short a2, int a3)
{
    unsigned int v3; // ebx@1
    unsigned int result; // eax@2
    unsigned int v5; // edx@3
    int v6; // ecx@3
    int v7; // ebx@4
    unsigned char v8; // of@4
    char v9; // cf@6

    v3 = *(DWORD *)(a3 + 4 * a1 + 35776);
    if ( *(DWORD *)(a3 + 4 * a1 + 35776) < 0 )
    {
        sub_54AB24(a2, a1);
        do
        {
            v7 = ~v3;
            v8 = __OFSUB__(BYTE1(v6)--, 1);
            if ( (SBYTE1(v6) < 0) ^ v8 )
            {
                sub_54AABC(v6, v5);
                BYTE1(v6) = 7;
            }
            v9 = v5 & 1;
            v5 >>= 1;
            LOBYTE(v7) = v9 + v7;
            v3 = *(DWORD *)(a3 + 4 * v7 + 36800);
        }
        while ( (v3 & 0x80000000) != 0 );
        result = v3 >> 2;
    }
    else
    {
        LOBYTE(a2) = *(BYTE *)(v3 + a3 + 34624);
        result = sub_54AB0C(a2, a1);
    }
    return result;
}

unsigned int sub_54ABE4(unsigned char a1, short a2, int a3)
{
    unsigned int v3; // ebx@1
    unsigned int result; // eax@2
    unsigned int v5; // edx@3
    int v6; // ecx@3
    int v7; // ebx@4
    unsigned char v8; // of@4
    char v9; // cf@6

    v3 = *(DWORD *)(a3 + 4 * a1 + 39360);
    if ( *(DWORD *)(a3 + 4 * a1 + 39360) < 0 )
    {
        sub_54AB24(a2, a1);
        do
        {
            v7 = ~v3;
            v8 = __OFSUB__(BYTE1(v6)--, 1);
            if ( (SBYTE1(v6) < 0) ^ v8 )
            {
                sub_54AABC(v6, v5);
                BYTE1(v6) = 7;
            }
            v9 = v5 & 1;
            v5 >>= 1;
            LOBYTE(v7) = v9 + v7;
            v3 = *(DWORD *)(a3 + 4 * v7 + 40384);
        }
        while ( (v3 & 0x80000000) != 0 );
        result = v3 >> 2;
    }
    else
    {
        LOBYTE(a2) = *(BYTE *)(v3 + a3 + 39232);
        result = sub_54AB0C(a2, a1);
    }
    return result;
}

int sub_54AC2D(int a1, int a2)
{
    int v2; // eax@1
    unsigned int v3; // eax@1
    unsigned int v4; // ecx@2
    BYTE *v5; // edi@4
    int result; // eax@6
    int v7; // [sp-8h] [bp-10h]@0
    int v8; // [sp-4h] [bp-Ch]@1
    int v9; // [sp+0h] [bp-8h]@0
    int v10; // [sp+4h] [bp-4h]@0

    v8 = a1;
    v2 = *(DWORD *)(a2 + 33280);
    *(DWORD *)(a2 + 33284) = v2;
    v3 = v2 - a2;
    do
    {
        v4 = v3;
        if ( v3 > *(DWORD *)(a2 + 33296) )
            v4 = *(DWORD *)(a2 + 33296);
        *(DWORD *)(a2 + 33296) -= v4;
        v5 = *(BYTE **)(a2 + 33292);
        sub_54AAA1(v4, v5, (BYTE *)a2);
        *(DWORD *)(a2 + 33292) = v5;
        if ( !*(DWORD *)(a2 + 33296) )
        {
            *(DWORD *)(a2 + 43352) = 2;
            sub_54A9DE(a2);
            sub_54AA0D(v7, v8, v9, v10);
            JUMPOUT(&loc_54B16F);
        }
    }
    while ( v3 );
    result = v10;
    *(DWORD *)(a2 + 33280) = a2;
    return result;
}

void sub_54AF80(unsigned int a1, short a2, unsigned int a3)
{
    bool v3; // cf@2
    unsigned int v4; // ebx@3
    unsigned int v5; // edx@3
    unsigned int v6; // ecx@3
    BYTE *v7; // edi@4
    short v8; // ax@7
    unsigned int v9; // eax@11
    unsigned char v10; // dl@11
    short v11; // cx@11
    unsigned int v12; // ebp@12
    short v13; // cx@12
    unsigned int v14; // edx@12
    unsigned int v15; // eax@12
    int v16; // ecx@12
    int v17; // ebp@12
    int v18; // et0@12
    unsigned int v19; // eax@16
    const void *v20; // et2@17
    unsigned int v21; // eax@18
    unsigned int v22; // edx@18
    short v23; // cx@18
    unsigned int v24; // eax@19
    unsigned int v25; // edx@19
    short v26; // cx@19
    unsigned int v27; // edx@20
    short v28; // cx@20
    unsigned int v29; // ebp@20
    int *v30; // ebx@20
    unsigned int v31; // edx@22
    short v32; // cx@22
    unsigned int v33; // ebp@23
    unsigned int *v34; // edi@23
    unsigned int v35; // ebx@24
    unsigned int v36; // eax@24
    unsigned int v37; // eax@28
    unsigned int v38; // ebx@28
    unsigned int v39; // eax@33
    unsigned int v40; // ebx@33
    unsigned int v41; // ett@33
    unsigned int v42; // ST00_4@36
    int v43; // ecx@36
    void *v44; // edi@36
    const void *v45; // esi@36
    int v46; // edx@41
    int v47; // ecx@41
    int v48; // eax@41
    int v49; // edx@41
    int v50; // ecx@41
    BYTE *i; // edi@42
    int v52; // ecx@43
    int v53; // edx@46
    int v54; // ecx@46
    short v55; // cx@1
    unsigned int v56; // edx@1
    unsigned int v57; // edx@1
    short v58; // cx@1

    LOBYTE(a2) = 1;
    *(DWORD *)(a3 + 44420) = sub_54AB34(a2, a1);
    LOBYTE(v55) = 2;
    switch ( sub_54AB34(v55, v56) )
    {
        case 0u:
            if ( HIBYTE(v58) != 8 )
            {
                LOBYTE(v58) = HIBYTE(v58);
                sub_54AB0C(v58, v57);
            }
            sub_54AABC((unsigned short)v57, v57);
            v48 = sub_54AABC(v47, v46);
            BYTE1(v48) = BYTE1(v49);
            LOWORD(v48) = ~(WORD)v48;
            if ( v48 == v50 )
            {
                for ( i = *(BYTE **)(a3 + 33280); v50; v50 = v52 - 1 )
                {
                    sub_54AABC(v50, v49);
                    *i++ = BYTE1(v49);
                    if ( (unsigned int)i >= *(DWORD *)(a3 + 33288) )
                    {
                        *(DWORD *)(a3 + 33280) = i;
                        sub_54AC2D(v52, a3);
                        i = *(BYTE **)(a3 + 33280);
                    }
                }
                *(DWORD *)(a3 + 33280) = i;
                sub_54AABC(v50, 0);
                LOBYTE(v53) = BYTE1(v53);
                sub_54AABC(v54, v53);
            }
            return;
        case 1u:
            memset32((void *)(a3 + 34624), 8, 0x90u);
            memset32((void *)(a3 + 35200), 9, 0x70u);
            memset32((void *)(a3 + 35648), 7, 0x18u);
            memset32((void *)(a3 + 35744), 8, 8u);
            memset32((void *)(a3 + 39232), 5, 0x20u);
            goto LABEL_2;
        case 2u:
            memset((void *)(a3 + 34624), 0, 0x480u);
            memset((void *)(a3 + 39232), 0, 0x80u);
            memset((void *)(a3 + 40716), 0, 0x4Cu);
            LOBYTE(v58) = 5;
            v21 = sub_54AB34(v58, v57) + 257;
            *(DWORD *)(a3 + 33464) = v21;
            if ( v21 > 0x11E )
                return;
            LOBYTE(v23) = 5;
            v24 = sub_54AB34(v23, v22) + 1;
            *(DWORD *)(a3 + 33468) = v24;
            if ( v24 > 0x1E )
                return;
            LOBYTE(v26) = 4;
            v29 = sub_54AB34(v26, v25) + 4;
            v30 = dword_54A620;
            do
            {
                LOBYTE(v28) = 3;
                *(DWORD *)(a3 + 40716 + *v30) = sub_54AB34(v28, v27);
                ++v30;
                --v29;
            }
            while ( v29 );
            sub_54A870(a3 + 43312, a3);
            if ( v3 )
                return;
            v33 = *(DWORD *)(a3 + 33464) + *(DWORD *)(a3 + 33468);
            v34 = (unsigned int *)(a3 + 41968);
            break;
        case 3u:
            return;
    }
    do
    {
        while ( 1 )
        {
            v35 = *(DWORD *)(a3 + 4 * (unsigned char)v31 + 40792);
            LOBYTE(v32) = *(BYTE *)(v35 + a3 + 40716);
            sub_54AB0C(v32, v31);
            v36 = v35 >> 2;
            if ( (unsigned char)(v35 >> 2) > 0xFu )
                break;
            *v34 = v36;
            ++v34;
            if ( !--v33 )
                goto LABEL_36;
        }
        if ( (BYTE)v36 == 16 )
        {
            LOBYTE(v32) = 2;
            v37 = sub_54AB34(v32, v31) + 3;
            v38 = *(v34 - 1);
        }
        else
        {
            if ( (BYTE)v36 == 17 )
            {
                LOBYTE(v32) = 3;
                v37 = sub_54AB34(v32, v31) + 3;
            }
            else
            {
                LOBYTE(v32) = 7;
                v37 = sub_54AB34(v32, v31) + 11;
            }
            v38 = 0;
        }
        v41 = v37;
        v39 = v38;
        v40 = v41;
        v3 = v33 < v41;
        v33 -= v41;
        if ( v3 )
            return;
        do
        {
            *v34 = v39;
            ++v34;
            --v40;
        }
        while ( v40 );
    }
    while ( v33 );
LABEL_36:
    v42 = a3;
    v43 = *(DWORD *)(a3 + 33464);
    v44 = (void *)(a3 + 34624);
    v45 = (const void *)(a3 + 41968);
    qmemcpy(v44, v45, 4 * v43);
    qmemcpy((void *)(v42 + 39232), (char *)v45 + 4 * v43, 4 * *(DWORD *)(v42 + 33468));
    a3 = v42;
LABEL_2:
    sub_54A870(a3 + 43232, a3);
    if ( !v3 )
    {
        v4 = a3 + 43272;
        sub_54A870(a3 + 43272, a3);
        if ( !v3 )
        {
            v7 = *(BYTE **)(a3 + 33280);
            while ( 1 )
            {
                while ( 1 )
                {
                    v8 = sub_54AB98(v5, v6, a3);
                    if ( HIBYTE(v8) )
                        break;
                    *v7++ = v8;
                    if ( (unsigned int)v7 >= *(DWORD *)(a3 + 33288) )
                    {
                        *(DWORD *)(a3 + 33280) = v7;
                        sub_54AC2D(v6, a3);
                        v7 = *(BYTE **)(a3 + 33280);
                    }
                }
                if ( !(BYTE)v8 )
                {
                    *(DWORD *)(a3 + 33280) = v7;
                    return;
                }
                LOBYTE(v6) = *(BYTE *)(v4 + 5546600);
                v9 = *(DWORD *)((char *)&loc_54A2E4 + v4) + sub_54AB34(v6, v5);
                if ( v9 > 0x102 )
                    break;
                v12 = v9;
                sub_54ABE4(v10, v11, a3);
                LOBYTE(v13) = byte_54A764[v4];
                v15 = *(int *)((char *)&dword_54A7DC + v4) + sub_54AB34(v13, v14);
                v18 = v16;
                v6 = v12;
                v17 = v18;
                v4 = (unsigned int)&v7[-v15];
                if ( (unsigned int)v7 < v15 || v4 < a3 )
                {
                    v19 = a3 - v4;
                    v4 = *(DWORD *)(a3 + 33284) - (a3 - v4);
                    if ( v19 < v6 )
                    {
                        v20 = (const void *)v4;
                        v4 = a3;
                        qmemcpy(v7, v20, v19);
                        v7 += v19;
                        v6 -= v19;
                    }
                }
                qmemcpy(v7, (const void *)v4, v6);
                v7 += v6;
                LOWORD(v6) = v17;
                if ( (unsigned int)v7 >= *(DWORD *)(a3 + 33288) )
                {
                    *(DWORD *)(a3 + 33280) = v7;
                    sub_54AC2D(v17, a3);
                    v7 = *(BYTE **)(a3 + 33280);
                }
            }
            *(DWORD *)(a3 + 33280) = v7;
        }
    }
}

signed int Inf32BufSize()
{
    return 44432;
}

int Inf32Decode(int a1, int a2, int a3, int a4, int a5)
{
    int v5; // edx@2
    int v6; // ecx@2
    int result; // eax@2
    int v8; // edx@5
    int v9; // ecx@5
    unsigned int v10; // edx@5
    int v11; // ecx@5
    char v12; // cf@6
    int v13; // ebp@9
    unsigned int v14; // esi@1
    int v15; // [sp-10h] [bp-14h]@1
    int v16; // [sp-Ch] [bp-10h]@1
    int v17; // [sp-8h] [bp-Ch]@1
    int v18; // [sp-4h] [bp-8h]@1
    int v19; // [sp+0h] [bp-4h]@2
    int savedregs; // [sp+4h] [bp+0h]@2

    v18 = a2;
    v17 = a1;
    v16 = a5;
    v15 = a4;
    v14 = *(DWORD *)(a3 + 32);
    *(DWORD *)(v14 + 44424) = a3;
    *(DWORD *)(v14 + 44428) = &v15;
    *(DWORD *)(v14 + 33320) = *(DWORD *)(a3 + 8);
    *(DWORD *)(v14 + 33328) = *(DWORD *)(a3 + 12);
    *(DWORD *)(v14 + 33324) = **(DWORD **)(a3 + 16);
    *(DWORD *)(v14 + 33312) = *(DWORD *)(v14 + 33328) + *(DWORD *)(v14 + 33320);
    *(DWORD *)(v14 + 33316) = *(DWORD *)(v14 + 33324);
    *(DWORD *)(v14 + 33300) = *(DWORD *)(a3 + 20);
    *(DWORD *)(v14 + 33308) = *(DWORD *)(a3 + 24);
    *(DWORD *)(v14 + 33304) = **(DWORD **)(a3 + 28);
    *(DWORD *)(v14 + 33292) = *(DWORD *)(v14 + 33308) + *(DWORD *)(v14 + 33300);
    *(DWORD *)(v14 + 33296) = *(DWORD *)(v14 + 33304);
    *(DWORD *)(v14 + 44416) = *(DWORD *)(a3 + 36);

    switch ( *(DWORD *)(v14 + 43352) ){

    case 0:
        *(DWORD *)(v14 + 43232) = 288;
        *(DWORD *)(v14 + 43236) = v14 + 33472;
        *(DWORD *)(v14 + 43240) = v14 + 34624;
        *(DWORD *)(v14 + 43244) = v14 + 35776;
        *(DWORD *)(v14 + 43248) = v14 + 36800;
        *(DWORD *)(v14 + 43272) = 32;
        *(DWORD *)(v14 + 43276) = v14 + 39104;
        *(DWORD *)(v14 + 43280) = v14 + 39232;
        *(DWORD *)(v14 + 43284) = v14 + 39360;
        *(DWORD *)(v14 + 43288) = v14 + 40384;
        *(DWORD *)(v14 + 43312) = 19;
        *(DWORD *)(v14 + 43316) = v14 + 40640;
        *(DWORD *)(v14 + 43320) = v14 + 40716;
        *(DWORD *)(v14 + 43324) = v14 + 40792;
        *(DWORD *)(v14 + 43328) = v14 + 41816;
        *(DWORD *)(v14 + 33284) = v14 + 0x8000;
        *(DWORD *)(v14 + 33288) = v14 + 0x8000;
        *(DWORD *)(v14 + 33280) = v14;
        sub_54AABC(a2, 0);
        LOBYTE(v8) = BYTE1(v8);
        sub_54AABC(v9, v8);
        BYTE1(v11) = 8;
        while ( 1 )
        {
            sub_54AF80(v10, v11, v14);
            if ( v12 )
                break;
            if ( *(DWORD *)(v14 + 44420) == 1 )
            {
                sub_54AC2D(v11, v14);
                sub_54A9DE(v14);
                JUMPOUT(&loc_54B171);
            }
        }
        sub_54AC2D(v11, v14);
        v13 = *(DWORD *)(v14 + 44424);
        **(DWORD **)(v13 + 16) = *(DWORD *)(v14 + 33324);
        **(DWORD **)(v13 + 28) = *(DWORD *)(v14 + 33304) - *(DWORD *)(v14 + 33296);
        JUMPOUT(&loc_54B171);
        return result;
    case 1:
        sub_54AA5D(v15, v16, v17, v18, v19, savedregs);
        return sub_54AABC(v6, v5);
    case 2:
        sub_54AA5D(v15, v16, v17, v18, v19, savedregs);
        JUMPOUT(&loc_54AC77);
        return result;
    }
}
