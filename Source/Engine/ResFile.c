
/**
 * @file    Engine\ResFile.c
 * @author  Yvan Burrie
 * @date    2018/07/29
 * @version 1.0
 */

char aErrorOpen_ne_1[] = "Error: Open_new_ResFile, file %s not Found."; // idb
char aErrorOpen_re_1[] = "Error: Open_ResFile, Resfile not correct."; // idb
char aErrorOpen_resf[] = "Error: Open_ResFile, Corruption detected in resfile."; // idb
char aErrorReading_1[] = "Error: Reading resfile header data."; // idb
char aErrorReadingRe[] = "Error: Reading resfile header."; // idb
char aErrorOutOfMemo[] = "Error: Out of memory in Open_resfile."; // idb
char aErrorOpen_ma_1[] = "Error: Open_Mapped_ResFile, Could not map file to addr."; // idb
char aErrorOpen_mapp[] = "Error: Open_Mapped_ResFile, Could not map file(1)."; // idb
char Caption[] = "RESOURCE ERROR"; // idb
char aErrorOpen_new_[51] = "Error: Open_new_ResFile, mapped file %s not Found."; // weak
char aErrorUnableToR[] = "Error: unable to read resource"; // idb
char aErrorOutOfMe_1[] = "Error: Out of memory in res_read_bin."; // idb
char PrefixString[] = "temp"; // idb
char a__1[2] = "."; // weak
char aErrorWriting_1[46] = "Error writing resource file header: type node"; // weak
char aErrorWriting_2[] = "Error writing resource file data"; // idb
char aErrorWriting_5[] = "Error writing resource file data: pos out of sync 2"; // idb
char aErrorWriting_3[] = "Error writing resource file header: id node"; // idb
char aErrorWriting_4[47] = "Error writing resource file: pos out of sync 1"; // weak
char aErrorWritingRe[35] = "Error writing resource file header"; // weak
char aErrorUnableToC[] = "Error: unable to create resource file file: %s"; // idb
char aErrorErrorRead[30] = "Error: error reading file: %s"; // weak
char aErrorOutOfMe_2[24] = "Error: out of memory #3"; // weak
char aErrorFileIsEmp[30] = "Error: file is empty/NULL: %s"; // weak
char aErrorOutOfMe_0[24] = "Error: out of memory #2"; // weak
char aErrorDuplicate[] = "Error: duplicate resources: %s & %s"; // idb
char aErrorOutOfMe_4[24] = "Error: out of memory #1"; // weak
char aErrorCouldNotD[] = "Error: could not determine file type of: %s"; // idb
char aErrorUnableToO[] = "Error: unable to open file: %s"; // idb
char aSS_9[] = "%s %s"; // idb
char aErrorCouldNotF[] = "Error: could not find resource build file: %s"; // idb

ResFileHdr *Res_Files;

int resource_missing_flag;

////////////////////////////////////////////////////////////////////////////////////////////////////

void RESFILE_open_new_resource_file(
    char *resFileName,
    char *password,
    char *path,
    int open_mode = 0 )
{
    HANDLE v4; // eax@2
    void *v5; // esi@2
    HANDLE v6; // ebx@4
    ResFileHdr *v7; // ebx@9
    char *v8; // eax@12
    int v9; // esi@13
    int v10; // ST10_4@13
    int v11; // eax@15
    ResFileHdr *v12; // ecx@17
    ResFileHdr *i; // eax@19
    resfile_header *v14; // edi@22
    char resFile[260]; // [sp+Ch] [bp-19Ch]@1
    char error_msg[80]; // [sp+110h] [bp-98h]@3
    resfile_header rHeader; // [sp+160h] [bp-48h]@13
    int fHandle; // [sp+1A0h] [bp-8h]@1
    char *mapped_file_data; // [sp+1A4h] [bp-4h]@1

    mapped_file_data = 0;
    fHandle = -1;
    sprintf(resFile, aSS, path, resFileName);
    if( open_mode )
    {
        fHandle = _open(resFile, 0x8000);
        if( fHandle == -1 )
        {
            sprintf(error_msg, aErrorOpen_ne_1, resFileName);
            goto LABEL_29;
        }
    }
    else
    {
        v4 = CreateFileA(resFile, 0x80000000, 1u, 0, 4u, 0x80u, 0);
        v5 = v4;
        if( v4 == (HANDLE)-1 )
        {
            sprintf(error_msg, aErrorOpen_new_, resFileName);
LABEL_29:
            MessageBoxA(0, error_msg, Caption, 0x30u);
            return;
        }
        v6 = CreateFileMappingA(v4, 0, 2u, 0, 0, 0);
        CloseHandle(v5);
        if( !v6 )
        {
            MessageBoxA(0, aErrorOpen_mapp, Caption, 0x30u);
            return;
        }
        mapped_file_data = (char *)MapViewOfFile(v6, 4u, 0, 0, 0);
        if( !mapped_file_data )
        {
            MessageBoxA(0, aErrorOpen_ma_1, Caption, 0x30u);
            return;
        }
        CloseHandle(v6);
    }
    v7 = (ResFileHdr *)malloc(0x114u);
    if( !v7 )
    {
        MessageBoxA(0, aErrorOutOfMemo, Caption, 0x30u);
        return;
    }
    strcpy(v7->res_name, resFileName);
    v7->next = 0;
    if( open_mode )
    {
        v9 = fHandle;
        v10 = fHandle;
        v7->handle = fHandle;
        v7->mapped_file = 0;
        lseek(v10, 0, 1);
        if( read(v9, &rHeader, 0x40u) != 64 )
        {
            __debugbreak();
            MessageBoxA(0, aErrorReadingRe, Caption, 0x30u);
            return;
        }
        v7->header = (resfile_header *)malloc(rHeader.directory_size);
        lseek(v9, 0, 0);
        v11 = read(v9, v7->header, rHeader.directory_size);
        if( v11 != rHeader.directory_size )
        {
            MessageBoxA(0, aErrorReading_1, Caption, 0x30u);
            return;
        }
    }
    else
    {
        v8 = mapped_file_data;
        v7->handle = -1;
        v7->mapped_file = v8;
        v7->header = (resfile_header *)v8;
    }
    v12 = Res_Files;
    if( Res_Files )
    {
        for( i = Res_Files->next; i; i = i->next )
            v12 = i;
        v12->next = v7;
    }
    else
    {
        Res_Files = v7;
    }
    v14 = v7->header;
    if( !strcmp(v14->password, password) )
    {
        if( strncmp(v14->version, a1_00, 4u) )
            MessageBoxA(0, aErrorOpen_re_1, Caption, 0x30u);
    }
    else
    {
        MessageBoxA(0, aErrorOpen_resf, Caption, 0x30u);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void RESFILE_close_new_resource_file( char *res_file )
{
    /* find the file by its name and return nothing if unfound: */
    for( ResFileHdr *Res_File = Res_Files; true; Res_File = Res_File->next ){

        if( Res_File == NULL ){
            return;
        }

        if( !strcmp(res_file, Res_File->res_name) ){
            break;
        }

        ResFileHdr *Res_Prev = Res_File;
    }

    if( Res_File->mapped_file == NULL ){
        free(Res_File->header);
    }

    if( Res_Prev ){
        Res_Prev->next = Res_File->next;
    }else{
        Res_Files = Res_File->next;
    }

    if( Res_File->handle != -1 ){
        close(Res_File->handle);
    }

    if( Res_File->mapped_file ){
        UnmapViewOfFile(Res_File->mapped_file);
    }

    free(Res_File);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

bool RESFILE_locate_resource(
    unsigned int rType,
    unsigned int rId,
    int *file,
    int *offset,
    char **mapped_file,
    int *size )
{
    unsigned int v7; // ebp@2
    resfile_header *v8; // ebx@3
    char *v9; // edi@4
    int v10; // eax@6
    char *v11; // esi@7
    int result; // eax@13
    int v13; // eax@14
    ResFileHdr *p; // [sp+10h] [bp-4h]@1
    unsigned int rIda; // [sp+1Ch] [bp+8h]@3

    *file        = -1;
    *offset      = 0;
    *mapped_file = 0;
    *size        = 0;

    p = Res_File;

    ResFileHdr *Res_File = Res_Files;
    if( Res_File == NULL ){
        return false;
    }

    v7 = rId;
    while( true ){
        v8 = Res_File->header;
        rIda = 0;
        if( v8->num_res_types > 0 ) break;
        LABEL_12:
        Res_File = Res_File->next;
        p = Res_File;
        if( Res_File == NULL )
            return false;
    }
    v9 = &v8[1].banner_msg[8];
    while( 1 )
    {
        if( *((_DWORD *)v9 - 2) == rType )
        {
            v10 = 0;
            if( *(_DWORD *)v9 > 0 )
                break;
        }
LABEL_11:
        v9 += 12;
        if( (signed int)++rIda >= v8->num_res_types )
            goto LABEL_12;
    }
    v11 = &v8->banner_msg[*((_DWORD *)v9 - 1)];
    while( *(_DWORD *)v11 != v7 )
    {
        ++v10;
        v11 += 12;
        if( v10 >= *(_DWORD *)v9 )
        {
            Res_File = p;
            goto LABEL_11;
        }
    }
    v13 = (int)v8 + 12 * v10 + *((_DWORD *)v9 - 1);

    *file        = p->handle;
    *offset      = *(_DWORD *)(v13 + 4);
    *mapped_file = p->mapped_file;
    *size        = *(_DWORD *)(v13 + 8);

    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

char *RESFILE_load(
    char *rType,
    unsigned int rId,
    int *rLoadType,
    int *rDataSize )
{
    unsigned int v4; // ebx@1
    unsigned int v5; // ebp@1
    int *v6; // esi@1
    int *v7; // edi@1
    unsigned int v8; // ST04_4@1
    unsigned int v10; // eax@4
    int *v11; // ecx@5
    int *v12; // edx@5
    int *v13; // eax@6
    void *v14; // esi@6
    int *v15; // eax@8


    unsigned int res_orig_id = rId;
    signed int res_orig_type = rType;
    v6 = rLoadType;
    v7 = rDataSize;
    v8 = rId;

    *rLoadType = -1;

    *v7 = 0;

    bool res_located = RESFILE_locate_resource(
       res_orig_type,
       v8,
       &rId,
       &rDataSize,
       &rType,
       &rLoadType);

    if( !res_located ){
        if( resource_missing_flag ){

            char error_string[100];
            sprintf(error_string, "ERROR: res_read_bin, resource type %4.4c , id %d, not found", res_orig_type, res_orig_id);

            MessageBox(
                NULL,
                error_string,
                Caption,
                0x30u);
        }
        return NULL;
    }

    v10 = rType;
    if( rType )
    {
        v11 = rDataSize;
        v12 = rLoadType;
        *v6 = 0;
        *v7 = (int)v12;
        return (char *)v11 + v10;
    }
    v13 = rLoadType;
    *v6 = 1;
    v14 = malloc((size_t)v13);
    *v7 = (int)rLoadType;
    if( !v14 )
    {
        MessageBoxA(0, aErrorOutOfMe_1, Caption, 0x30u);
        return 0;
    }
    lseek(rId, (__int32)rDataSize, 0);
    v15 = (int *)read(rId, v14, (unsigned int)rLoadType);
    if( v15 != rLoadType )
    {
        MessageBoxA(0, aErrorUnableToR, Caption, 0x30u);
        return 0;
    }
    return (char *)v14;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

char *RESFILE_Extract_to_File(
    unsigned int rType,
    unsigned int rId,
    char *file_name,
    FILE **file )
{
    char *result; // eax@1
    char *v5; // ebp@1
    _iobuf *v6; // eax@5
    int rLoadType; // [sp+8h] [bp-10Ch]@1
    int rDataSize; // [sp+Ch] [bp-108h]@1
    char temp_path[260]; // [sp+10h] [bp-104h]@2

    *file = 0;
    result = RESFILE_load(rType, rId, &rLoadType, &rDataSize);
    v5 = result;
    if( result )
    {
        if( !GetTempPathA(0x104u, temp_path) )
            strcpy(temp_path, a__1);
        if( GetTempFileNameA(temp_path, PrefixString, 0, file_name) )
        {
            v6 = fopen(file_name, "w+");
            *file = v6;
            if( v6 )
            {
                if( rDataSize > 0 )
                {
                    fwrite(v5, rDataSize, 1u, v6);
                    fseek(*file, 0, 0);
                }
            }
        }
        if( rLoadType == 1 )
            free(v5);
        result = (char *)(*file != 0);
    }
    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void RESFILE_Set_Missing_Flag( int FlagVal )
{
    resource_missing_flag = FlagVal;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

bool RESFILE_Decommit_Mapped_Memory( char *ResData, int resSize )
{
    if( ResData && resSize > 0 ){
        return VirtualFree(ResData, resSize, MEM_DECOMMIT);
    }else{
        return false;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

bool RESFILE_build_res_file( char *build_list_file, char *source_path, char *target_path )
{
    FILE *v3; // eax@1
    FILE *v4; // esi@1
    int result; // eax@2
    unsigned int v6; // esi@6
    BuildRes_type_node *v7; // edi@7
    BuildRes_type_node *v8; // ebp@7
    BuildRes_type_node *v9; // eax@7
    BuildRes_id_node *v10; // eax@20
    void *v11; // ebx@25
    int v12; // edi@26
    __int32 v13; // esi@31
    void *v14; // eax@32
    int v15; // ebx@42
    BuildRes_type_node *v16; // esi@45
    int v17; // edx@45
    BuildRes_type_node *i; // eax@45
    int v19; // ecx@46
    int v20; // ecx@47
    BuildRes_id_node *j; // eax@48
    int v22; // edi@49
    BuildRes_type_node *v23; // esi@53
    signed int v24; // ebp@53
    BuildRes_type_node *v25; // edi@56
    BuildRes_id_node *v26; // esi@58
    BuildRes_type_node *v27; // esi@66
    BuildRes_type_node *v28; // ebx@66
    BuildRes_id_node *v29; // esi@67
    int v30; // edi@69
    BuildRes_type_node *v31; // ebp@77
    BuildRes_id_node *v32; // esi@78
    BuildRes_id_node *v33; // edi@81
    BuildRes_type_node *v34; // esi@82
    BuildRes_type_node *ID_List; // [sp+10h] [bp-4A4h]@1
    BuildRes_id_node *iq; // [sp+14h] [bp-4A0h]@20
    _iobuf *buildFile; // [sp+18h] [bp-49Ch]@1
    _iobuf *buildFilea; // [sp+18h] [bp-49Ch]@42
    int numResTypes; // [sp+1Ch] [bp-498h]@1
    unsigned int rId; // [sp+20h] [bp-494h]@5
    resfile_id_dir_node idDirNode; // [sp+24h] [bp-490h]@59
    resfile_type_dir_node typeDirNode; // [sp+30h] [bp-484h]@54
    resfile_header theHeader; // [sp+3Ch] [bp-478h]@51
    char rPassword[40]; // [sp+7Ch] [bp-438h]@3
    char data_filename[260]; // [sp+A4h] [bp-410h]@6
    char temp_filename[260]; // [sp+1A8h] [bp-30Ch]@3
    char resource_filename[260]; // [sp+2ACh] [bp-208h]@3
    char build_filename[260]; // [sp+3B0h] [bp-104h]@1

    ID_List = 0;
    numResTypes = 0;
    sprintf(build_filename, aSS, source_path, build_list_file);
    v3 = fopen(build_filename, Mode);
    v4 = v3;
    buildFile = v3;
    if( !v3 )
    {
        TDebuggingLog::Log(L, aErrorCouldNotF, build_list_file);
        return 0;
    }
    fscanf(v3, aSS_9, temp_filename, rPassword);
    sprintf(resource_filename, aSS, target_path, temp_filename);
    while( fscanf(v4, aS_2, temp_filename) != -1 && fscanf(v4, aD_3, &rId) != -1 )
    {
        sprintf(data_filename, aSS, source_path, temp_filename);
        v6 = BUILDRES_get_files_resource_type(temp_filename);
        if( !v6 )
        {
            TDebuggingLog::Log(L, aErrorCouldNotD, temp_filename);
            return 0;
        }
        v7 = 0;
        v8 = 0;
        v9 = ID_List;
        if( ID_List )
        {
            while( v9->type != v6 )
            {
                if( v9->type < v6 )
                    v7 = v9;
                v9 = v9->next;
                if( !v9 )
                    goto LABEL_14;
            }
            v8 = v9;
        }
LABEL_14:
        if( !v8 )
        {
            v8 = (BuildRes_type_node *)operator new(0x14u);
            if( !v8 )
            {
                TDebuggingLog::Log(L, aErrorOutOfMe_4);
                return 0;
            }
            v8->type = v6;
            v8->idOffset = 0;
            v8->nIds = 0;
            v8->idList = 0;
            v8->next = 0;
            if( v7 )
            {
                v8->next = v7->next;
                v7->next = v8;
            }
            else
            {
                v8->next = ID_List;
                ID_List = v8;
            }
            ++numResTypes;
        }
        v10 = v8->idList;
        iq = 0;
        if( v10 )
        {
            while( v10->id != rId )
            {
                if( v10->id < rId )
                    iq = v10;
                v10 = v10->next;
                if( !v10 )
                    goto LABEL_25;
            }
            TDebuggingLog::Log(L, aErrorDuplicate, v10->fName, data_filename);
            return 0;
        }
LABEL_25:
        v11 = operator new(0x118u);
        if( !v11 )
        {
            TDebuggingLog::Log(L, aErrorOutOfMe_0);
            goto LABEL_76;
        }
        *(_DWORD *)v11 = rId;
        *((_DWORD *)v11 + 1) = 0;
        *((_DWORD *)v11 + 2) = 0;
        *((_DWORD *)v11 + 3) = 0;
        *((_DWORD *)v11 + 4) = 0;
        strcpy((char *)v11 + 20, data_filename);
        v12 = _open(data_filename, 0x8000);
        if( v12 == -1 )
        {
            TDebuggingLog::Log(L, aErrorUnableToO, data_filename);
            operator delete(v11);
            v4 = buildFile;
        }
        else
        {
            if( iq )
            {
                *((_DWORD *)v11 + 4) = iq->next;
                iq->next = (BuildRes_id_node *)v11;
            }
            else
            {
                *((_DWORD *)v11 + 4) = v8->idList;
                v8->idList = (BuildRes_id_node *)v11;
            }
            ++v8->nIds;
            v13 = lseek(v12, 0, 2);
            lseek(v12, 0, 0);
            if( v13 <= 0 )
            {
                TDebuggingLog::Log(L, aErrorFileIsEmp, data_filename);
                return 0;
            }
            v14 = malloc(v13);
            *((_DWORD *)v11 + 2) = v14;
            if( !v14 )
            {
                TDebuggingLog::Log(L, aErrorOutOfMe_2);
                goto LABEL_76;
            }
            *((_DWORD *)v11 + 3) = v13;
            if( read(v12, v14, v13) != v13 )
            {
                TDebuggingLog::Log(L, aErrorErrorRead, data_filename);
                return 0;
            }
            _close(v12);
            v4 = buildFile;
        }
    }
    fclose(v4);
    v15 = _open(resource_filename, 33537, 384);
    buildFilea = (_iobuf *)v15;
    if( v15 == -1 )
    {
        TDebuggingLog::Log(L, aErrorUnableToC, resource_filename);
        return 0;
    }
    v16 = ID_List;
    v17 = 12 * numResTypes + 64;
    for( i = ID_List; i; v17 += 12 * v19 )
    {
        v19 = i->nIds;
        i->idOffset = v17;
        i = i->next;
    }
    v20 = v17;
    if( ID_List )
    {
        do
        {
            for( j = v16->idList; j; v20 += v22 )
            {
                v22 = j->resSize;
                j->dataOffset = v20;
                j = j->next;
            }
            v16 = v16->next;
        }
        while( v16 );
    }
    memset(&theHeader, 0, sizeof(theHeader));
    strcpy(theHeader.banner_msg, (const char *)&header_message);
    strcpy(theHeader.version, a1_00);
    strcpy(theHeader.password, rPassword);
    theHeader.num_res_types = numResTypes;
    theHeader.directory_size = v17;
    if( _write(v15, &theHeader, 0x40u) != 64 )
    {
        TDebuggingLog::Log(L, aErrorWritingRe);
        return 0;
    }
    v23 = ID_List;
    v24 = 64;
    if( ID_List )
    {
        while( 1 )
        {
            typeDirNode.type = v23->type;
            typeDirNode.dirOffset = v23->idOffset;
            typeDirNode.numID = v23->nIds;
            if( _write(v15, &typeDirNode, 0xCu) != 12 )
                break;
            v23 = v23->next;
            v24 += 12;
            if( !v23 )
                goto LABEL_56;
        }
        TDebuggingLog::Log(L, aErrorWriting_1);
        return 0;
    }
LABEL_56:
    v25 = ID_List;
    if( ID_List )
    {
        while( 1 )
        {
            if( v24 != v25->idOffset )
            {
                TDebuggingLog::Log(L, aErrorWriting_4);
                goto LABEL_76;
            }
            v26 = v25->idList;
            if( v26 )
                break;
LABEL_61:
            v25 = v25->next;
            if( !v25 )
            {
                v25 = ID_List;
                goto LABEL_66;
            }
        }
        while( 1 )
        {
            idDirNode.id = v26->id;
            idDirNode.itemOffset = v26->dataOffset;
            idDirNode.itemSize = v26->resSize;
            if( _write(v15, &idDirNode, 0xCu) != 12 )
                break;
            v26 = v26->next;
            v24 += 12;
            if( !v26 )
                goto LABEL_61;
        }
        TDebuggingLog::Log(L, aErrorWriting_3);
        return 0;
    }
LABEL_66:
    v27 = ID_List;
    v28 = v25;
    if( ID_List )
    {
        while( 1 )
        {
            v29 = v28->idList;
            if( v29 )
                break;
LABEL_71:
            v28 = v28->next;
            if( !v28 )
            {
                v27 = ID_List;
                goto LABEL_77;
            }
        }
        while( 1 )
        {
            if( v24 != v29->dataOffset )
            {
                TDebuggingLog::Log(L, aErrorWriting_5);
                return 0;
            }
            v30 = v29->resSize;
            if( _write((int)buildFilea, v29->resData, v29->resSize) != v30 )
                break;
            v29 = v29->next;
            v24 += v30;
            if( !v29 )
                goto LABEL_71;
        }
        TDebuggingLog::Log(L, aErrorWriting_2);
LABEL_76:
        result = 0;
    }
    else
    {
LABEL_77:
        _close((int)buildFilea);
        v31 = v27;
        if( v27 )
        {
            do
            {
                v32 = v31->idList;
                if( v32 )
                {
                    do
                    {
                        if( v32->resData )
                            free(v32->resData);
                        v33 = v32->next;
                        operator delete(v32);
                        v32 = v33;
                    }
                    while( v33 );
                }
                v34 = v31->next;
                operator delete(v31);
                v31 = v34;
            }
            while( v34 );
        }
        result = 1;
    }
    return result;
}

int BUILDRES_get_files_resource_type(char *filename)
{
    char *v1; // edx@1
    int v2; // ecx@1
    unsigned int v3; // kr04_4@1
    int v4; // eax@3
    bool v5; // zf@3
    int v6; // ecx@8
    signed int v7; // esi@9
    int v8; // ebp@10
    char v9; // bl@11
    int v10; // edi@11
    char *v11; // esi@15
    size_t v12; // edi@16
    int v13; // eax@18
    signed int result; // eax@19
    char extension[8]; // [sp+10h] [bp-8h]@13
    char *filenamea; // [sp+1Ch] [bp+4h]@8

    v1 = filename;
    v3 = strlen(filename) + 1;
    v2 = v3 - 1;
    if( (signed int)(v3 - 1) < 5 || v2 >= 260 )
        goto LABEL_24;
    v4 = v3 - 2;
    v5 = v2 == 1;
    if( (signed int)(v3 - 2) > 0 )
    {
        do
        {
            if( filename[v4] == 46 )
                break;
            --v4;
        }
        while( v4 > 0 );
        v5 = v4 == 0;
    }
    if( v5 || (v6 = v2 - v4 - 1, filenamea = (char *)v6, v6 > 3) )
    {
LABEL_24:
        result = 0;
    }
    else
    {
        v7 = 0;
        if( v6 >= 0 )
        {
            v8 = (int)&v1[v4 + 1];
            do
            {
                v9 = *(_BYTE *)(v7 + v8);
                v10 = *(_BYTE *)(v7 + v8);
                if( isupper(v10) )
                    v9 = tolower(v10);
                extension[v7++] = v9;
            }
            while( v7 <= (signed int)filenamea );
            v6 = (int)filenamea;
        }
        v11 = res_extension_table;
        if( dword_585524 )
        {
            v12 = v6 + 1;
            while( strncmp(v11, extension, v12) )
            {
                v13 = *((_DWORD *)v11 + 3);
                v11 += 8;
                if( !v13 )
                    goto LABEL_19;
            }
            result = *((_DWORD *)v11 + 1);
        }
        else
        {
LABEL_19:
            result = 1651076705;
        }
    }
    return result;
}
