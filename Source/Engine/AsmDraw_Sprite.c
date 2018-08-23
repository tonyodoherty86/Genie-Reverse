
_ASMDraw_Sprite proc near

    asm("arg_0        = dword    ptr  8");
    asm("arg_4        = dword    ptr  0Ch");
    asm("arg_8        = dword    ptr  10h");
    asm("arg_C        = dword    ptr  14h");
    asm("arg_10        = dword    ptr  18h");
    asm("arg_14        = dword    ptr  1Ch");
    asm("arg_18        = dword    ptr  20h");
    asm("arg_1C        = dword    ptr  24h");

    asm("push    ebp");
    asm("mov    ebp, esp");
    asm("push    ebx");
    asm("push    esi");
    asm("push    edi");
    asm("mov    eax, [ebp+arg_8]");
    asm("mov    ecx, [ebp+arg_10]");
    asm("xor    edx, edx");
    asm("lea    ebx, [ecx+eax-1]");
    asm("cmp    ebx, ds:ASMMinLine");
    asm("jl    loc_56D2F4");
    asm("cmp    eax, ds:ASMMaxLine");
    asm("jg    loc_56D2F4");
    asm("cmp    eax, ds:ASMMinLine");
    asm("jge    short loc_56C9E4");
    asm("mov    edx, ds:ASMMinLine");
    asm("sub    edx, eax");
    asm("xor    eax, eax");
    asm("sub    ecx, edx");
    asm("shl    edx, 2");
    asm("mov    [ebp+arg_8], eax");

loc_56C9E4:
    asm("cmp    ebx, ds:ASMMaxLine");
    asm("jle    short loc_56C9F4");
    asm("sub    ebx, ds:ASMMaxLine");
    asm("sub    ecx, ebx");

loc_56C9F4:
    asm("mov    [ebp+arg_10], ecx");
    asm("xor    ebx, ebx");
    asm("mov    ds:ASMDrawYOffset, ebx");
    asm("mov    eax, [ebp+arg_4]");
    asm("mov    ds:dword_88C024, eax");
    asm("cmp    eax, ds:ASMMaxSpanPx");
    asm("jg    loc_56D2F4");
    asm("add    eax, [ebp+arg_C]");
    asm("dec    eax");
    asm("mov    ds:dword_88C028, eax");
    asm("cmp    eax, ds:ASMMinSpanPx");
    asm("jl    loc_56D2F4");
    asm("mov    eax, [ebp+arg_14]");
    asm("add    eax, [ebp+arg_0]");
    asm("add    eax, edx");
    asm("mov    ds:dword_88C00C, eax");
    asm("mov    eax, [ebp+arg_18]");
    asm("add    eax, [ebp+arg_0]");
    asm("add    eax, edx");
    asm("mov    ds:dword_88C010, eax");
    asm("mov    eax, [ebp+arg_1C]");
    asm("xor    ecx, ecx");
    asm("test    eax, 1");
    asm("jz    short loc_56CA55");
    asm("mov    ecx, 80h");
    asm("jmp    short loc_56CA71");

loc_56CA55:
    asm("mov    ebx, ds:ASMColorXForm1");
    asm("mov    ds:dword_88C030, ecx");
    asm("mov    ds:dword_88C02C, 0FFFFFFFFh");
    asm("mov    ds:dword_88C034, ebx");

loc_56CA71:
    asm("mov    ds:dword_88C048, ecx");
    asm("test    eax, 2");
    asm("jnz    loc_56D300");
    asm("mov    eax, eax");

loc_56CAA0:
    asm("mov    eax, [ebp+arg_8]");
    asm("mov    ebx, ds:ASMDrawYOffset");
    asm("add    eax, ebx");
    asm("mov    esi, ds:ASMLineHeadPtrs");
    asm("mov    edi, [esi+eax*4]");
    asm("or    edi, edi");
    asm("jz    loc_56D2E0");
    asm("mov    ds:ASMCurrentLineHead, edi");
    asm("test    byte ptr ds:dword_88C048, 80h");
    asm("jz    short loc_56CAF6");
    asm("and    eax, 3");
    asm("mov    edx, ds:ASMShadowing2A[eax*4]");
    asm("mov    ecx, ds:ASMShadowing1A[eax*4]");
    asm("mov    eax, ds:ASMColorXForm1");
    asm("mov    ds:dword_88C030, edx");
    asm("mov    ds:dword_88C02C, ecx");
    asm("and    eax, ecx");
    asm("or    eax, edx");
    asm("mov    ds:dword_88C034, eax");

loc_56CAF6:
    asm("mov    esi, ds:dword_88C010");
    asm("xor    eax, eax");
    asm("mov    ax, [esi+ebx*4]");
    asm("mov    edx, ds:dword_88C024");
    asm("test    eax, 8000h");
    asm("jnz    loc_56D2E0");
    asm("add    edx, eax");
    asm("mov    ax, [esi+ebx*4+2]");
    asm("mov    ecx, ds:dword_88C028");
    asm("sub    ecx, eax");
    asm("mov    esi, ds:ASMRenderOffsets");
    asm("mov    eax, [ebp+arg_8]");
    asm("add    eax, ebx");
    asm("mov    eax, [esi+eax*4]");
    asm("mov    ds:ASMCurrentRenderYOffset, eax");
    asm("add    eax, edx");
    asm("mov    ds:ASMCurrentRenderXOffset, eax");
    asm("mov    esi, ds:dword_88C00C");
    asm("mov    eax, [esi+ebx*4]");
    asm("add    eax, [ebp+arg_0]");
    asm("mov    ds:dword_88C018, eax");

loc_56CB4D:
    asm("cmp    ecx, [edi+8]");
    asm("jl    loc_56D2E0");
    asm("cmp    edx, [edi+0Ch]");
    asm("jle    short loc_56CB66");
    asm("mov    edi, [edi]");
    asm("or    edi, edi");
    asm("jnz    short loc_56CB4D");
    goto loc_56D2E0;

loc_56CB66:
    asm("cmp    edx, [edi+8]");
    asm("jl    short loc_56CB8B");
    asm("cmp    ecx, [edi+0Ch]");
    asm("jg    short loc_56CB8B");
    asm("mov    eax, offset loc_56D0A0");
    asm("mov    ds:ASMLocation,    eax");
    asm("mov    edi, ds:ASMCurrentRenderXOffset");
    asm("mov    esi, ds:dword_88C018");
    goto loc_56D0A0;

loc_56CB8B:
    asm("mov    eax, offset loc_56CC20");
    asm("mov    ds:ASMLocation,    eax");
    asm("mov    ds:ASMCurrentLineHead, edi");
    asm("mov    edi, ds:ASMCurrentRenderXOffset");
    asm("mov    esi, ds:dword_88C018");
    goto loc_56CC20;

loc_56CBC0:
    asm("mov    esi, ds:dword_88C050");
    asm("mov    edi, ds:dword_88C054");
    asm("mov    ebx, ds:ASMCurrentLineHead");
    asm("mov    ebx, [ebx]");
    asm("or    ebx, ebx");
    asm("jz    loc_56D2E0");
    asm("mov    ds:ASMLocation,    offset loc_56CC20");
    asm("xor    eax, eax");
    asm("mov    al, [esi]");
    asm("sub    edi, ds:ASMCurrentRenderYOffset");
    asm("mov    ecx, eax");
    asm("inc    esi");
    asm("and    eax, 0Fh");
    asm("mov    ds:ASMCurrentLineHead, ebx");
    asm("jmp    ds:off_56B400[eax*4]");

loc_56CC20:
    asm("mov    ds:dword_88C050, esi");
    asm("xor    eax, eax");
    asm("mov    ds:dword_88C054, edi");
    asm("mov    al, [esi]");
    asm("sub    edi, ds:ASMCurrentRenderYOffset");
    asm("mov    ecx, eax");
    asm("inc    esi");
    asm("and    eax, 0Fh");
    asm("mov    ebx, ds:ASMCurrentLineHead");
    asm("jmp    ds:off_56B400[eax*4]");

loc_56CC60:
    asm("mov    eax, ecx");
    asm("shr    eax, 4");
    asm("jmp    ds:off_56B480[eax*4]");

loc_56CC80:
    asm("shr    ecx, 2");
    asm("jmp    short loc_56CC8B");

loc_56CC85:
    asm("shl    ecx, 4");
    asm("mov    cl, [esi]");
    asm("inc    esi");

loc_56CC8B:
    asm("mov    edx, edi");
    asm("add    edx, ecx");
    asm("dec    edx");

loc_56CC90:
    asm("cmp    edx, [ebx+8]");
    asm("jl    short loc_56CCF2");
    asm("cmp    edi, [ebx+0Ch]");
    asm("jg    short loc_56CD01");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+8]");
    asm("jge    short loc_56CCAA");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edi");
    asm("add    esi, eax");
    asm("sub    ecx, eax");

loc_56CCAA:
    asm("mov    ds:ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+0Ch]");
    asm("jle    short loc_56CCC5");
    asm("mov    eax, edx");
    asm("sub    eax, [ebx+0Ch]");
    asm("sub    ecx, eax");
    asm("mov    ds:ASMLocation,    offset loc_56CBC0");

loc_56CCC5:
    asm("mov    edi, ds:dword_88C054");
    asm("xor    ebx, ebx");
    asm("add    edi, ds:ASMCurrentLineHeadPx");
    asm("sub    bl, ch");
    asm("mov    eax, edi");
    asm("and    bl, 80h");
    asm("and    eax, 3");
    asm("or    bl, cl");
    asm("or    al, byte ptr ds:dword_88C048");
    asm("or    al, ds:byte_56B300[ebx]");
    asm("jmp    ds:off_56A300[eax*4]");

loc_56CCF2:
    asm("mov    edi, ds:dword_88C054");
    asm("add    esi, ecx");
    asm("add    edi, ecx");
    goto loc_56CC20;

loc_56CD01:
    asm("mov    ebx, [ebx]");
    asm("or    ebx, ebx");
    asm("jnz    short loc_56CC90");
    goto loc_56D2E0;

loc_56CD20:
    asm("shr    ecx, 2");
    asm("mov    edi, ds:dword_88C054");
    asm("add    edi, ecx");
    asm("jmp    ds:ASMLocation");

loc_56CD31:
    asm("shl    ecx, 4");
    asm("mov    edi, ds:dword_88C054");
    asm("mov    cl, [esi]");
    asm("inc    esi");
    asm("add    edi, ecx");
    asm("jmp    ds:ASMLocation");

loc_56CD60:
    asm("shr    ecx, 4");
    asm("jnz    short loc_56CD68");
    asm("mov    cl, [esi]");
    asm("inc    esi");

loc_56CD68:
    asm("mov    edx, edi");
    asm("add    edx, ecx");
    asm("dec    edx");

loc_56CD6D:
    asm("cmp    edx, [ebx+8]");
    asm("jl    short loc_56CDCC");
    asm("cmp    edi, [ebx+0Ch]");
    asm("jg    short loc_56CDDB");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+8]");
    asm("jge    short loc_56CD87");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edi");
    asm("add    esi, eax");
    asm("sub    ecx, eax");

loc_56CD87:
    asm("mov    ds:ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+0Ch]");
    asm("jle    short loc_56CDA2");
    asm("mov    eax, edx");
    asm("sub    eax, [ebx+0Ch]");
    asm("sub    ecx, eax");
    asm("mov    ds:ASMLocation,    offset loc_56CBC0");

loc_56CDA2:
    asm("mov    edi, ds:dword_88C054");
    asm("add    edi, ds:ASMCurrentLineHeadPx");
    asm("mov    eax, edi");
    asm("and    eax, 3");
    asm("or    al, ds:byte_56B300[ecx]");
    asm("mov    ebx, ds:ASMColorXForm1");
    asm("or    al, byte ptr ds:dword_88C048");
    asm("jmp    ds:off_56AB00[eax*4]");

loc_56CDCC:
    asm("mov    edi, ds:dword_88C054");
    asm("add    esi, ecx");
    asm("add    edi, ecx");
    goto loc_56CC20;

loc_56CDDB:
    asm("mov    ebx, [ebx]");
    asm("or    ebx, ebx");
    asm("jnz    short loc_56CD6D");
    goto loc_56D2E0;

loc_56CE00:
    asm("shr    ecx, 4");
    asm("jnz    short loc_56CE08");
    asm("mov    cl, [esi]");
    asm("inc    esi");

loc_56CE08:
    asm("mov    edx, edi");
    asm("add    edx, ecx");
    asm("dec    edx");

loc_56CE0D:
    asm("cmp    edx, [ebx+8]");
    asm("jl    short loc_56CE7C");
    asm("cmp    edi, [ebx+0Ch]");
    asm("jg    short loc_56CE8A");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+8]");
    asm("jge    short loc_56CE25");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edi");
    asm("sub    ecx, eax");

loc_56CE25:
    asm("mov    ds:ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+0Ch]");
    asm("jle    short loc_56CE40");
    asm("mov    eax, edx");
    asm("sub    eax, [ebx+0Ch]");
    asm("sub    ecx, eax");
    asm("mov    ds:ASMLocation,    offset loc_56CBC0");

loc_56CE40:
    asm("mov    edi, ds:dword_88C054");
    asm("mov    al, [esi]");
    asm("add    edi, ds:ASMCurrentLineHeadPx");
    asm("mov    ah, al");
    asm("mov    ebx, edi");
    asm("shl    eax, 10h");
    asm("and    ebx, 3");
    asm("mov    al, [esi]");
    asm("or    bl, ds:byte_56B300[ecx]");
    asm("mov    ah, al");
    asm("or    bl, byte ptr ds:dword_88C048");
    asm("and    eax, ds:dword_88C02C");
    asm("or    eax, ds:dword_88C030");
    asm("inc    esi");
    asm("jmp    ds:off_56A700[ebx*4]");

loc_56CE7C:
    asm("mov    edi, ds:dword_88C054");
    asm("inc    esi");
    asm("add    edi, ecx");
    goto loc_56CC20;

loc_56CE8A:
    asm("mov    ebx, [ebx]");
    asm("or    ebx, ebx");
    asm("jnz    loc_56CE0D");
    goto loc_56D2E0;

loc_56CEA0:
    asm("shr    ecx, 4");
    asm("jnz    short loc_56CEA8");
    asm("mov    cl, [esi]");
    asm("inc    esi");

loc_56CEA8:
    asm("mov    edx, edi");
    asm("add    edx, ecx");
    asm("dec    edx");

loc_56CEAD:
    asm("cmp    edx, [ebx+8]");
    asm("jl    short loc_56CF1C");
    asm("cmp    edi, [ebx+0Ch]");
    asm("jg    short loc_56CF2A");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+8]");
    asm("jge    short loc_56CEC5");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edi");
    asm("sub    ecx, eax");

loc_56CEC5:
    asm("mov    ds:ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+0Ch]");
    asm("jle    short loc_56CEE0");
    asm("mov    eax, edx");
    asm("sub    eax, [ebx+0Ch]");
    asm("sub    ecx, eax");
    asm("mov    ds:ASMLocation,    offset loc_56CBC0");

loc_56CEE0:
    asm("mov    edi, ds:dword_88C054");
    asm("mov    al, [esi]");
    asm("add    edi, ds:ASMCurrentLineHeadPx");
    asm("mov    ah, al");
    asm("mov    ebx, edi");
    asm("shl    eax, 10h");
    asm("and    ebx, 3");
    asm("mov    al, [esi]");
    asm("or    bl, ds:byte_56B300[ecx]");
    asm("mov    ah, al");
    asm("or    bl, byte ptr ds:dword_88C048");
    asm("inc    esi");
    asm("and    eax, ds:dword_88C02C");
    asm("or    eax, ds:dword_88C034");
    asm("jmp    ds:off_56A700[ebx*4]");

loc_56CF1C:
    asm("mov    edi, ds:dword_88C054");
    asm("inc    esi");
    asm("add    edi, ecx");
    goto loc_56CC20;

loc_56CF2A:
    asm("mov    ebx, [ebx]");
    asm("or    ebx, ebx");
    asm("jnz    loc_56CEAD");
    goto loc_56D2E0;

loc_56CF40:
    asm("shr    ecx, 4");
    asm("jnz    short loc_56CF48");
    asm("mov    cl, [esi]");
    asm("inc    esi");

loc_56CF48:
    asm("mov    edx, edi");
    asm("add    edx, ecx");
    asm("dec    edx");

loc_56CF4D:
    asm("cmp    edx, [ebx+8]");
    asm("jl    short loc_56CFAC");
    asm("cmp    edi, [ebx+0Ch]");
    asm("jg    short loc_56CFB9");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+8]");
    asm("jge    short loc_56CF65");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edi");
    asm("sub    ecx, eax");

loc_56CF65:
    asm("mov    ds:ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+0Ch]");
    asm("jle    short loc_56CF80");
    asm("mov    eax, edx");
    asm("sub    eax, [ebx+0Ch]");
    asm("sub    ecx, eax");
    asm("mov    ds:ASMLocation,    offset loc_56CBC0");

loc_56CF80:
    asm("mov    edi, ds:dword_88C054");
    asm("add    edi, ds:ASMCurrentLineHeadPx");
    asm("mov    eax, edi");
    asm("and    eax, 3");
    asm("xor    edx, edx");
    asm("or    al, ds:byte_56B300[ecx]");
    asm("mov    ebx, ds:ASMXlate");
    asm("or    al, byte ptr ds:dword_88C048");
    asm("jmp    ds:off_56AF00[eax*4]");

loc_56CFAC:
    asm("mov    edi, ds:dword_88C054");
    asm("add    edi, ecx");
    goto loc_56CC20;

loc_56CFB9:
    asm("mov    ebx, [ebx]");
    asm("or    ebx, ebx");
    asm("jnz    short loc_56CF4D");
    goto loc_56D2E0;

loc_56CFE0:
    asm("mov    cl, [esi]");
    asm("inc    esi");
    asm("jnz    short loc_56CFEA");

loc_56CFE5:
    asm("mov    ecx, 1");

loc_56CFEA:
    asm("cmp    ds:dword_88C058, 0");
    asm("jz    short loc_56D060");
    asm("mov    edx, edi");
    asm("add    edx, ecx");
    asm("dec    edx");

loc_56CFF8:
    asm("cmp    edx, [ebx+8]");
    asm("jl    short loc_56D060");
    asm("cmp    edi, [ebx+0Ch]");
    asm("jg    short loc_56D06D");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+8]");
    asm("jge    short loc_56D010");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edi");
    asm("sub    ecx, eax");

loc_56D010:
    asm("mov    ds:ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+0Ch]");
    asm("jle    short loc_56D02B");
    asm("mov    eax, edx");
    asm("sub    eax, [ebx+0Ch]");
    asm("sub    ecx, eax");
    asm("mov    ds:ASMLocation,    offset loc_56CBC0");

loc_56D02B:
    asm("mov    edi, ds:dword_88C054");
    asm("mov    eax, ds:dword_88C05C");
    asm("add    edi, ds:ASMCurrentLineHeadPx");
    asm("and    eax, ds:dword_88C02C");
    asm("mov    ebx, edi");
    asm("or    eax, ds:dword_88C030");
    asm("and    ebx, 3");
    asm("or    bl, ds:byte_56B300[ecx]");
    asm("or    bl, byte ptr ds:dword_88C048");
    asm("jmp    ds:off_56A700[ebx*4]");

loc_56D060:
    asm("mov    edi, ds:dword_88C054");
    asm("add    edi, ecx");
    goto loc_56CC20;

loc_56D06D:
    asm("mov    ebx, [ebx]");
    asm("or    ebx, ebx");
    asm("jnz    short loc_56CFF8");
    goto loc_56D2E0;

loc_56D080:
    asm("mov    al, [esi]");
    asm("call    loc_56DB60");
    asm("add    edi, ecx");
    goto loc_56CC20;

loc_56D0A0:
    asm("xor    eax, eax");
    asm("mov    al, [esi]");
    asm("mov    ecx, eax");
    asm("and    eax, 0Fh");
    asm("inc    esi");
    asm("jmp    ds:off_56B440[eax*4]");

loc_56D0C0:
    asm("mov    eax, ecx");
    asm("shr    eax, 4");
    asm("jmp    ds:off_56B4C0[eax*4]");

loc_56D0E0:
    asm("shr    ecx, 2");
    asm("mov    eax, edi");
    asm("and    eax, 3");
    asm("or    al, ds:byte_56B300[ecx]");
    asm("or    al, byte ptr ds:dword_88C048");
    asm("jmp    ds:off_56A300[eax*4]");

loc_56D100:
    asm("shl    ecx, 4");
    asm("xor    ebx, ebx");
    asm("mov    cl, [esi]");
    asm("sub    bl, ch");
    asm("mov    eax, edi");
    asm("and    bl, 80h");
    asm("and    eax, 3");
    asm("or    bl, cl");
    asm("or    al, byte ptr ds:dword_88C048");
    asm("or    al, ds:byte_56B300[ebx]");
    asm("inc    esi");
    asm("jmp    ds:off_56A300[eax*4]");

loc_56D140:
    asm("shr    ecx, 2");
    asm("add    edi, ecx");
    asm("jmp    ds:ASMLocation");

loc_56D14B:
    asm("shl    ecx, 4");
    asm("mov    cl, [esi]");
    asm("inc    esi");
    asm("add    edi, ecx");
    asm("jmp    ds:ASMLocation");

loc_56D160:
    asm("shr    ecx, 4");
    asm("jnz    short loc_56D168");
    asm("mov    cl, [esi]");
    asm("inc    esi");

loc_56D168:
    asm("mov    eax, edi");
    asm("and    eax, 3");
    asm("or    al, ds:byte_56B300[ecx]");
    asm("mov    ebx, ds:ASMColorXForm1");
    asm("or    al, byte ptr ds:dword_88C048");
    asm("jmp    ds:off_56AB00[eax*4]");

loc_56D1A0:
    asm("shr    ecx, 4");
    asm("jnz    short loc_56D1A8");
    asm("mov    cl, [esi]");
    asm("inc    esi");

loc_56D1A8:
    asm("mov    al, [esi]");
    asm("mov    ebx, edi");
    asm("mov    ah, al");
    asm("and    ebx, 3");
    asm("shl    eax, 10h");
    asm("or    bl, ds:byte_56B300[ecx]");
    asm("mov    al, [esi]");
    asm("or    bl, byte ptr ds:dword_88C048");
    asm("inc    esi");
    asm("mov    ah, al");
    asm("and    eax, ds:dword_88C02C");
    asm("or    eax, ds:dword_88C030");
    asm("jmp    ds:off_56A700[ebx*4]");

loc_56D1E0:
    asm("shr    ecx, 4");
    asm("jnz    short loc_56D1E8");
    asm("mov    cl, [esi]");
    asm("inc    esi");

loc_56D1E8:
    asm("mov    al, [esi]");
    asm("mov    ebx, edi");
    asm("mov    ah, al");
    asm("and    ebx, 3");
    asm("shl    eax, 10h");
    asm("or    bl, ds:byte_56B300[ecx]");
    asm("mov    al, [esi]");
    asm("or    bl, byte ptr ds:dword_88C048");
    asm("inc    esi");
    asm("mov    ah, al");
    asm("and    eax, ds:dword_88C02C");
    asm("or    eax, ds:dword_88C034");
    asm("jmp    ds:off_56A700[ebx*4]");

loc_56D220:
    asm("shr    ecx, 4");
    asm("jnz    short loc_56D228");
    asm("mov    cl, [esi]");
    asm("inc    esi");

loc_56D228:
    asm("mov    eax, edi");
    asm("and    eax, 3");
    asm("or    al, ds:byte_56B300[ecx]");
    asm("mov    ebx, ds:ASMXlate");
    asm("or    al, byte ptr ds:dword_88C048");
    asm("xor    edx, edx");
    asm("jmp    ds:off_56AF00[eax*4]");

loc_56D260:
    asm("mov    cl, [esi]");
    asm("inc    esi");
    asm("jmp    short loc_56D26A");

loc_56D265:
    asm("mov    ecx, 1");

loc_56D26A:
    asm("cmp    ds:dword_88C058, 0");
    asm("jz    short loc_56D29C");
    asm("mov    eax, ds:dword_88C05C");
    asm("mov    ebx, edi");
    asm("and    eax, ds:dword_88C02C");
    asm("and    ebx, 3");
    asm("or    eax, ds:dword_88C030");
    asm("or    bl, ds:byte_56B300[ecx]");
    asm("or    bl, byte ptr ds:dword_88C048");
    asm("jmp    ds:off_56A700[ebx*4]");

loc_56D29C:
    asm("add    edi, ecx");
    asm("jmp    ds:ASMLocation");

loc_56D2C0:
    asm("mov    al, [esi]");
    asm("call    loc_56DB60");
    asm("add    edi, ecx");
    goto loc_56D0A0;

//byte_56D2CE    db 0CCh

    asm("jmp    ds:ASMLocation");

loc_56D2E0:
    asm("mov    eax, ds:ASMDrawYOffset");
    asm("inc    eax");
    asm("mov    ds:ASMDrawYOffset, eax");
    asm("cmp    eax, [ebp+arg_10]");
    asm("jl    loc_56CAA0");

loc_56D2F4:
    asm("pop    edi");
    asm("pop    esi");
    asm("pop    ebx");
    asm("pop    ebp");
    asm("retn");

loc_56D300:
    asm("mov    eax, [ebp+arg_8]");
    asm("mov    ebx, ds:ASMDrawYOffset");
    asm("add    eax, ebx");
    asm("mov    esi, ds:ASMLineTailPtrs");
    asm("mov    edi, [esi+eax*4]");
    asm("or    edi, edi");
    asm("jz    loc_56DB40");
    asm("mov    ds:ASMCurrentLineHead, edi");
    asm("test    byte ptr ds:dword_88C048, 80h");
    asm("jz    short loc_56D356");
    asm("and    eax, 3");
    asm("mov    edx, ds:ASMShadowing2A[eax*4]");
    asm("mov    ecx, ds:ASMShadowing1A[eax*4]");
    asm("mov    eax, ds:ASMColorXForm1");
    asm("mov    ds:dword_88C030, edx");
    asm("mov    ds:dword_88C02C, ecx");
    asm("and    eax, ecx");
    asm("or    eax, edx");
    asm("mov    ds:dword_88C034, eax");

loc_56D356:
    asm("mov    esi, ds:dword_88C010");
    asm("xor    eax, eax");
    asm("mov    ax, [esi+ebx*4+2]");
    asm("mov    edx, ds:dword_88C024");
    asm("test    eax, 8000h");
    asm("jnz    loc_56DB40");
    asm("add    edx, eax");
    asm("mov    ax, [esi+ebx*4]");
    asm("mov    ecx, ds:dword_88C028");
    asm("sub    ecx, eax");
    asm("mov    esi, ds:ASMRenderOffsets");
    asm("mov    eax, [ebp+arg_8]");
    asm("add    eax, ebx");
    asm("mov    eax, [esi+eax*4]");
    asm("mov    ds:ASMCurrentRenderYOffset, eax");
    asm("add    eax, ecx");
    asm("mov    ds:ASMCurrentRenderXOffset, eax");
    asm("mov    esi, ds:dword_88C00C");
    asm("mov    eax, [esi+ebx*4]");
    asm("add    eax, [ebp+arg_0]");
    asm("mov    ds:dword_88C018, eax");

loc_56D3AD:
    asm("cmp    edx, [edi+0Ch]");
    asm("jg    loc_56DB40");
    asm("cmp    ecx, [edi+8]");
    asm("jge    short loc_56D3C7");
    asm("mov    edi, [edi+4]");
    asm("or    edi, edi");
    asm("jnz    short loc_56D3AD");
    goto loc_56DB40;

loc_56D3C7:
    asm("cmp    edx, [edi+8]");
    asm("jl    short loc_56D3E9");
    asm("cmp    ecx, [edi+0Ch]");
    asm("jg    short loc_56D3E9");
    asm("mov    eax, offset loc_56D420");
    asm("mov    ds:ASMLocation,    eax");
    asm("mov    edi, ds:ASMCurrentRenderXOffset");
    asm("mov    esi, ds:dword_88C018");
    asm("jmp    short loc_56D420");

loc_56D3E9:
    asm("mov    eax, offset loc_56D6C0");
    asm("mov    ds:ASMLocation,    eax");
    asm("mov    ds:ASMCurrentLineHead, edi");
    asm("mov    edi, ds:ASMCurrentRenderXOffset");
    asm("mov    esi, ds:dword_88C018");
    goto loc_56D6C0;

loc_56D420:
    asm("xor    eax, eax");
    asm("mov    al, [esi]");
    asm("mov    ecx, eax");
    asm("and    eax, 0Fh");
    asm("inc    esi");
    asm("jmp    ds:off_56B540[eax*4]");

loc_56D440:
    asm("mov    eax, ecx");
    asm("shr    eax, 4");
    asm("jmp    ds:off_56B5C0[eax*4]");

loc_56D460:
    asm("shr    ecx, 2");
    asm("mov    eax, edi");
    asm("and    eax, 3");
    asm("or    al, ds:byte_56B300[ecx]");
    asm("or    al, byte ptr ds:dword_88C048");
    asm("jmp    ds:off_56B600[eax*4]");

loc_56D480:
    asm("shl    ecx, 4");
    asm("xor    ebx, ebx");
    asm("mov    cl, [esi]");
    asm("sub    bl, ch");
    asm("mov    eax, edi");
    asm("and    bl, 80h");
    asm("and    eax, 3");
    asm("or    bl, cl");
    asm("or    al, byte ptr ds:dword_88C048");
    asm("or    al, ds:byte_56B300[ebx]");
    asm("inc    esi");
    asm("jmp    ds:off_56B600[eax*4]");

loc_56D4C0:
    asm("shr    ecx, 2");
    asm("sub    edi, ecx");
    asm("jmp    ds:ASMLocation");

loc_56D4CB:
    asm("shl    ecx, 4");
    asm("mov    cl, [esi]");
    asm("inc    esi");
    asm("sub    edi, ecx");
    asm("jmp    ds:ASMLocation");

loc_56D4E0:
    asm("shr    ecx, 4");
    asm("jnz    short loc_56D4E8");
    asm("mov    cl, [esi]");
    asm("inc    esi");

loc_56D4E8:
    asm("mov    eax, edi");
    asm("and    eax, 3");
    asm("or    al, ds:byte_56B300[ecx]");
    asm("mov    ebx, ds:ASMColorXForm1");
    asm("or    al, byte ptr ds:dword_88C048");
    asm("jmp    ds:off_56BE00[eax*4]");

loc_56D520:
    asm("shr    ecx, 4");
    asm("jnz    short loc_56D528");
    asm("mov    cl, [esi]");
    asm("inc    esi");

loc_56D528:
    asm("mov    al, [esi]");
    asm("mov    ebx, edi");
    asm("mov    ah, al");
    asm("and    ebx, 3");
    asm("shl    eax, 10h");
    asm("or    bl, ds:byte_56B300[ecx]");
    asm("mov    al, [esi]");
    asm("or    bl, byte ptr ds:dword_88C048");
    asm("inc    esi");
    asm("mov    ah, al");
    asm("and    eax, ds:dword_88C02C");
    asm("or    eax, ds:dword_88C030");
    asm("jmp    ds:off_56BA00[ebx*4]");

loc_56D560:
    asm("shr    ecx, 4");
    asm("jnz    short loc_56D568");
    asm("mov    cl, [esi]");
    asm("inc    esi");

loc_56D568:
    asm("mov    al, [esi]");
    asm("mov    ebx, edi");
    asm("mov    ah, al");
    asm("and    ebx, 3");
    asm("shl    eax, 10h");
    asm("or    bl, ds:byte_56B300[ecx]");
    asm("mov    al, [esi]");
    asm("or    bl, byte ptr ds:dword_88C048");
    asm("inc    esi");
    asm("mov    ah, al");
    asm("and    eax, ds:dword_88C02C");
    asm("or    eax, ds:dword_88C034");
    asm("jmp    ds:off_56BA00[ebx*4]");

loc_56D5A0:
    asm("shr    ecx, 4");
    asm("jnz    short loc_56D5A8");
    asm("mov    cl, [esi]");
    asm("inc    esi");

loc_56D5A8:
    asm("mov    eax, edi");
    asm("and    eax, 3");
    asm("or    al, ds:byte_56B300[ecx]");
    asm("mov    ebx, ds:ASMXlate");
    asm("or    al, byte ptr ds:dword_88C048");
    asm("xor    edx, edx");
    asm("jmp    ds:off_56C200[eax*4]");

loc_56D5E0:
    asm("mov    cl, [esi]");
    asm("inc    esi");
    asm("jmp    short loc_56D5EA");

loc_56D5E5:
    asm("mov    ecx, 1");

loc_56D5EA:
    asm("cmp    ds:dword_88C058, 0");
    asm("jz    short loc_56D61C");
    asm("mov    eax, ds:dword_88C05C");
    asm("mov    ebx, edi");
    asm("and    eax, ds:dword_88C02C");
    asm("and    ebx, 3");
    asm("or    eax, ds:dword_88C030");
    asm("or    bl, ds:byte_56B300[ecx]");
    asm("or    bl, byte ptr ds:dword_88C048");
    asm("jmp    ds:off_56BA00[ebx*4]");

loc_56D61C:
    asm("sub    edi, ecx");
    asm("jmp    ds:ASMLocation");

loc_56D640:
    asm("mov    al, [esi]");
    asm("call    loc_56DB60");
    asm("add    edi, ecx");
    goto loc_56D420;

loc_56D660:
    asm("mov    esi, ds:dword_88C050");
    asm("mov    edi, ds:dword_88C054");
    asm("mov    ebx, ds:ASMCurrentLineHead");
    asm("mov    ebx, [ebx+4]");
    asm("or    ebx, ebx");
    asm("jz    loc_56DB40");
    asm("mov    ds:ASMLocation,    offset loc_56D6C0");
    asm("xor    eax, eax");
    asm("mov    al, [esi]");
    asm("sub    edi, ds:ASMCurrentRenderYOffset");
    asm("mov    ecx, eax");
    asm("inc    esi");
    asm("and    eax, 0Fh");
    asm("mov    ds:ASMCurrentLineHead, ebx");
    asm("jmp    ds:off_56B500[eax*4]");

loc_56D6C0:
    asm("mov    ds:dword_88C050, esi");
    asm("xor    eax, eax");
    asm("mov    ds:dword_88C054, edi");
    asm("mov    al, [esi]");
    asm("sub    edi, ds:ASMCurrentRenderYOffset");
    asm("mov    ecx, eax");
    asm("inc    esi");
    asm("and    eax, 0Fh");
    asm("mov    ebx, ds:ASMCurrentLineHead");
    asm("jmp    ds:off_56B500[eax*4]");

loc_56D700:
    asm("mov    eax, ecx");
    asm("shr    eax, 4");
    asm("jmp    ds:off_56B580[eax*4]");

loc_56D720:
    asm("shr    ecx, 2");
    asm("jmp    short loc_56D72B");

loc_56D725:
    asm("shl    ecx, 4");
    asm("mov    cl, [esi]");
    asm("inc    esi");

loc_56D72B:
    asm("mov    edx, edi");
    asm("sub    edx, ecx");
    asm("inc    edx");

loc_56D730:
    asm("cmp    edx, [ebx+0Ch]");
    asm("jg    short loc_56D792");
    asm("cmp    edi, [ebx+8]");
    asm("jl    short loc_56D7A1");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+0Ch]");
    asm("jle    short loc_56D74A");
    asm("mov    eax, edi");
    asm("sub    eax, [ebx+0Ch]");
    asm("add    esi, eax");
    asm("sub    ecx, eax");

loc_56D74A:
    asm("mov    ds:ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+8]");
    asm("jge    short loc_56D765");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edx");
    asm("sub    ecx, eax");
    asm("mov    ds:ASMLocation,    offset loc_56D660");

loc_56D765:
    asm("mov    edi, ds:dword_88C054");
    asm("xor    ebx, ebx");
    asm("sub    edi, ds:ASMCurrentLineHeadPx");
    asm("sub    bl, ch");
    asm("mov    eax, edi");
    asm("and    bl, 80h");
    asm("and    eax, 3");
    asm("or    bl, cl");
    asm("or    al, byte ptr ds:dword_88C048");
    asm("or    al, ds:byte_56B300[ebx]");
    asm("jmp    ds:off_56B600[eax*4]");

loc_56D792:
    asm("mov    edi, ds:dword_88C054");
    asm("add    esi, ecx");
    asm("sub    edi, ecx");
    goto loc_56D6C0;

loc_56D7A1:
    asm("mov    ebx, [ebx+4]");
    asm("or    ebx, ebx");
    asm("jnz    short loc_56D730");
    goto loc_56DB40;

loc_56D7C0:
    asm("shr    ecx, 2");
    asm("mov    edi, ds:dword_88C054");
    asm("sub    edi, ecx");
    asm("jmp    ds:ASMLocation");

loc_56D7D1:
    asm("shl    ecx, 4");
    asm("mov    edi, ds:dword_88C054");
    asm("mov    cl, [esi]");
    asm("inc    esi");
    asm("sub    edi, ecx");
    asm("jmp    ds:ASMLocation");

loc_56D800:
    asm("shr    ecx, 4");
    asm("jnz    short loc_56D808");
    asm("mov    cl, [esi]");
    asm("inc    esi");

loc_56D808:
    asm("mov    edx, edi");
    asm("sub    edx, ecx");
    asm("inc    edx");

loc_56D80D:
    asm("cmp    edx, [ebx+0Ch]");
    asm("jg    short loc_56D86C");
    asm("cmp    edi, [ebx+8]");
    asm("jl    short loc_56D87B");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+0Ch]");
    asm("jle    short loc_56D827");
    asm("mov    eax, edi");
    asm("sub    eax, [ebx+0Ch]");
    asm("add    esi, eax");
    asm("sub    ecx, eax");

loc_56D827:
    asm("mov    ds:ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+8]");
    asm("jge    short loc_56D842");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edx");
    asm("sub    ecx, eax");
    asm("mov    ds:ASMLocation,    offset loc_56D660");

loc_56D842:
    asm("mov    edi, ds:dword_88C054");
    asm("sub    edi, ds:ASMCurrentLineHeadPx");
    asm("mov    eax, edi");
    asm("and    eax, 3");
    asm("or    al, ds:byte_56B300[ecx]");
    asm("mov    ebx, ds:ASMColorXForm1");
    asm("or    al, byte ptr ds:dword_88C048");
    asm("jmp    ds:off_56BE00[eax*4]");

loc_56D86C:
    asm("mov    edi, ds:dword_88C054");
    asm("add    esi, ecx");
    asm("sub    edi, ecx");
    goto loc_56D6C0;

loc_56D87B:
    asm("mov    ebx, [ebx+4]");
    asm("or    ebx, ebx");
    asm("jnz    short loc_56D80D");
    goto loc_56DB40;

loc_56D8A0:
    asm("shr    ecx, 4");
    asm("jnz    short loc_56D8A8");
    asm("mov    cl, [esi]");
    asm("inc    esi");

loc_56D8A8:
    asm("mov    edx, edi");
    asm("sub    edx, ecx");
    asm("inc    edx");

loc_56D8AD:
    asm("cmp    edx, [ebx+0Ch]");
    asm("jg    short loc_56D91C");
    asm("cmp    edi, [ebx+8]");
    asm("jl    short loc_56D92A");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+0Ch]");
    asm("jle    short loc_56D8C5");
    asm("mov    eax, edi");
    asm("sub    eax, [ebx+0Ch]");
    asm("sub    ecx, eax");

loc_56D8C5:
    asm("mov    ds:ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+8]");
    asm("jge    short loc_56D8E0");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edx");
    asm("sub    ecx, eax");
    asm("mov    ds:ASMLocation,    offset loc_56D660");

loc_56D8E0:
    asm("mov    edi, ds:dword_88C054");
    asm("mov    al, [esi]");
    asm("sub    edi, ds:ASMCurrentLineHeadPx");
    asm("mov    ah, al");
    asm("mov    ebx, edi");
    asm("shl    eax, 10h");
    asm("and    ebx, 3");
    asm("mov    al, [esi]");
    asm("or    bl, ds:byte_56B300[ecx]");
    asm("mov    ah, al");
    asm("or    bl, byte ptr ds:dword_88C048");
    asm("and    eax, ds:dword_88C02C");
    asm("or    eax, ds:dword_88C030");
    asm("inc    esi");
    asm("jmp    ds:off_56BA00[ebx*4]");

loc_56D91C:
    asm("mov    edi, ds:dword_88C054");
    asm("inc    esi");
    asm("sub    edi, ecx");
    goto loc_56D6C0;

loc_56D92A:
    asm("mov    ebx, [ebx+4]");
    asm("or    ebx, ebx");
    asm("jnz    loc_56D8AD");
    goto loc_56DB40;

loc_56D940:
    asm("shr    ecx, 4");
    asm("jnz    short loc_56D948");
    asm("mov    cl, [esi]");
    asm("inc    esi");

loc_56D948:
    asm("mov    edx, edi");
    asm("sub    edx, ecx");
    asm("inc    edx");

loc_56D94D:
    asm("cmp    edx, [ebx+0Ch]");
    asm("jg    short loc_56D9BC");
    asm("cmp    edi, [ebx+8]");
    asm("jl    short loc_56D9CA");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+0Ch]");
    asm("jle    short loc_56D965");
    asm("mov    eax, edi");
    asm("sub    eax, [ebx+0Ch]");
    asm("sub    ecx, eax");

loc_56D965:
    asm("mov    ds:ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+8]");
    asm("jge    short loc_56D980");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edx");
    asm("sub    ecx, eax");
    asm("mov    ds:ASMLocation,    offset loc_56D660");

loc_56D980:
    asm("mov    edi, ds:dword_88C054");
    asm("mov    al, [esi]");
    asm("sub    edi, ds:ASMCurrentLineHeadPx");
    asm("mov    ah, al");
    asm("mov    ebx, edi");
    asm("shl    eax, 10h");
    asm("and    ebx, 3");
    asm("mov    al, [esi]");
    asm("or    bl, ds:byte_56B300[ecx]");
    asm("mov    ah, al");
    asm("or    bl, byte ptr ds:dword_88C048");
    asm("inc    esi");
    asm("and    eax, ds:dword_88C02C");
    asm("or    eax, ds:dword_88C034");
    asm("jmp    ds:off_56BA00[ebx*4]");

loc_56D9BC:
    asm("mov    edi, ds:dword_88C054");
    asm("inc    esi");
    asm("sub    edi, ecx");
    goto loc_56D6C0;

loc_56D9CA:
    asm("mov    ebx, [ebx+4]");
    asm("or    ebx, ebx");
    asm("jnz    loc_56D94D");
    goto loc_56DB40;

loc_56D9E0:
    asm("shr    ecx, 4");
    asm("jnz    short loc_56D9E8");
    asm("mov    cl, [esi]");
    asm("inc    esi");

loc_56D9E8:
    asm("mov    edx, edi");
    asm("sub    edx, ecx");
    asm("inc    edx");

loc_56D9ED:
    asm("cmp    edx, [ebx+0Ch]");
    asm("jg    short loc_56DA4C");
    asm("cmp    edi, [ebx+8]");
    asm("jl    short loc_56DA59");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+0Ch]");
    asm("jle    short loc_56DA05");
    asm("mov    eax, edi");
    asm("sub    eax, [ebx+0Ch]");
    asm("sub    ecx, eax");

loc_56DA05:
    asm("mov    ds:ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+8]");
    asm("jge    short loc_56DA20");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edx");
    asm("sub    ecx, eax");
    asm("mov    ds:ASMLocation,    offset loc_56D660");

loc_56DA20:
    asm("mov    edi, ds:dword_88C054");
    asm("sub    edi, ds:ASMCurrentLineHeadPx");
    asm("mov    eax, edi");
    asm("and    eax, 3");
    asm("or    al, ds:byte_56B300[ecx]");
    asm("mov    ebx, ds:ASMXlate");
    asm("or    al, byte ptr ds:dword_88C048");
    asm("xor    edx, edx");
    asm("jmp    ds:off_56C200[eax*4]");

loc_56DA4C:
    asm("mov    edi, ds:dword_88C054");
    asm("sub    edi, ecx");
    goto loc_56D6C0;

loc_56DA59:
    asm("mov    ebx, [ebx+4]");
    asm("or    ebx, ebx");
    asm("jnz    short loc_56D9ED");
    goto loc_56DB40;

loc_56DA80:
    asm("mov    cl, [esi]");
    asm("inc    esi");
    asm("jnz    short loc_56DA8A");

loc_56DA85:
    asm("mov    ecx, 1");

loc_56DA8A:
    asm("cmp    ds:dword_88C058, 0");
    asm("jz    short loc_56DB00");
    asm("mov    edx, edi");
    asm("sub    edx, ecx");
    asm("inc    edx");

loc_56DA98:
    asm("cmp    edx, [ebx+0Ch]");
    asm("jg    short loc_56DB00");
    asm("cmp    edi, [ebx+8]");
    asm("jl    short loc_56DB0D");
    asm("xor    eax, eax");
    asm("cmp    edi, [ebx+0Ch]");
    asm("jle    short loc_56DAB0");
    asm("mov    eax, edi");
    asm("sub    eax, [ebx+0Ch]");
    asm("sub    ecx, eax");

loc_56DAB0:
    asm("mov    ds:ASMCurrentLineHeadPx, eax");
    asm("cmp    edx, [ebx+8]");
    asm("jge    short loc_56DACB");
    asm("mov    eax, [ebx+8]");
    asm("sub    eax, edx");
    asm("sub    ecx, eax");
    asm("mov    ds:ASMLocation,    offset loc_56D660");

loc_56DACB:
    asm("mov    edi, ds:dword_88C054");
    asm("mov    eax, ds:dword_88C05C");
    asm("sub    edi, ds:ASMCurrentLineHeadPx");
    asm("and    eax, ds:dword_88C02C");
    asm("mov    ebx, edi");
    asm("or    eax, ds:dword_88C030");
    asm("and    ebx, 3");
    asm("or    bl, ds:byte_56B300[ecx]");
    asm("or    bl, byte ptr ds:dword_88C048");
    asm("jmp    ds:off_56BA00[ebx*4]");

loc_56DB00:
    asm("mov    edi, ds:dword_88C054");
    asm("sub    edi, ecx");
    goto loc_56D6C0;

loc_56DB0D:
    asm("mov    ebx, [ebx+4]");
    asm("or    ebx, ebx");
    asm("jnz    short loc_56DA98");
    asm("jmp    short loc_56DB40");

loc_56DB20:
    asm("mov    al, [esi]");
    asm("call    loc_56DB60");
    asm("add    edi, ecx");
    goto loc_56D6C0;

loc_56DB40:
    asm("mov    eax, ds:ASMDrawYOffset");
    asm("inc    eax");
    asm("mov    ds:ASMDrawYOffset, eax");
    asm("cmp    eax, [ebp+arg_10]");
    asm("jl    loc_56D300");
    asm("pop    edi");
    asm("pop    esi");
    asm("pop    ebx");
    asm("pop    ebp");
    asm("retn");

loc_56DB60:
    asm("xor    eax, eax");
    asm("mov    al, [esi]");
    asm("mov    ecx, eax");
    asm("inc    esi");
    asm("and    eax, 0Fh");
    asm("jmp    ds:off_56C600[eax*4]");

loc_56DB71:
    asm("shr    ecx, 2");
    asm("add    esi, ecx");
    asm("retn");

loc_56DB77:
    asm("shr    ecx, 2");
    asm("retn");

loc_56DB7B:
    asm("shl    ecx, 4");
    asm("mov    cl, [esi]");
    asm("inc    esi");
    asm("add    esi, ecx");
    asm("retn");

loc_56DB84:
    asm("shl    ecx, 4");
    asm("mov    cl, [esi]");
    asm("inc    esi");
    asm("retn");

loc_56DB8B:
    asm("shr    ecx, 4");
    asm("jnz    short loc_56DB93");
    asm("mov    cl, [esi]");
    asm("inc    esi");

loc_56DB93:
    asm("add    esi, ecx");
    asm("retn");

loc_56DB96:
    asm("shr    ecx, 4");
    asm("jnz    short loc_56DB9E");
    asm("mov    cl, [esi]");
    asm("inc    esi");

loc_56DB9E:
    asm("inc    esi");
    asm("retn");

loc_56DBA0:
    asm("shr    ecx, 4");
    asm("jnz    short locret_56DBA8");
    asm("mov    cl, [esi]");
    asm("inc    esi");

locret_56DBA8:
    asm("retn");

loc_56DBA9:
    asm("mov    eax, ecx");
    asm("shr    eax, 4");
    asm("jmp    ds:off_56C640[eax*4]");

loc_56DBB5:
    asm("mov    ecx, 0");
    asm("retn");

_ASMDraw_Sprite    endp