
RGE_Dialog_List::RGE_Dialog_List( char *name )
{
    TListDialog::TListDialog(name);
}

int RGE_Dialog_List::setup(
    TScreenPanel *parent_screen,
    char *info_file_in,
    int info_id_in,
    int list_type_in,
    char *title_in )
{
    RGE_Dialog_List *v6; // ebx@1
    int v7; // esi@1
    int v8; // eax@1
    int result; // eax@2
    char **v10; // eax@4
    signed int v11; // ebp@6
    char *v12; // edx@9
    const char *v13; // edi@10
    int list_type_ina; // [sp+20h] [bp+10h]@7

    v6 = this;
    v7 = 0;
    this->list_type = list_type_in;
    v8 = this->error_code;
    this->list_info = 0;
    this->list_text = 0;
    if( v8 )
    {
        result = 0;
    }
    else
    {
        result = ((int (*)(void))this->vfptr[1].handle_key_down)();
        if( result )
        {
            RGE_Dialog_List::sort_list(v6);
            RGE_Dialog_List::calc_list_line(v6);
            v10 = (char **)calloc(v6->list_size, 4u);
            v6->list_text = v10;
            if( v10 )
            {
                v11 = 0;
                if( v6->list_size <= 0 )
                {
LABEL_11:
                    LOWORD(v10) = v6->list_size;
                    result = TListDialog::setup(
                                         (TListDialog *)&v6->vfptr,
                                         (TPanel *)&parent_screen->vfptr,
                                         info_file_in,
                                         info_id_in,
                                         310,
                                         400,
                                         10,
                                         10,
                                         290,
                                         25,
                                         title_in,
                                         10,
                                         45,
                                         290,
                                         305,
                                         v6->list_text,
                                         (int)v10,
                                         v6->list_line,
                                         10,
                                         160,
                                         360,
                                         140,
                                         30) != 0;
                }
                else
                {
                    for( list_type_ina = 0; ; v7 = list_type_ina )
                    {
                        v6->list_text[v11] = (char *)calloc(strlen((const char *)v6->list_info + v7) + 1, 1u);
                        v12 = v6->list_text[v11];
                        if( !v12 )
                            break;
                        v13 = &v6->list_info->text[v7];
                        v10 = (char **)(strlen(v13) + 1);
                        qmemcpy(v12, v13, (unsigned int)v10);
                        ++v11;
                        list_type_ina += 102;
                        if( v11 >= v6->list_size )
                            goto LABEL_11;
                    }
                    result = 0;
                }
            }
            else
            {
                result = 0;
            }
        }
    }
    return result;
}

RGE_Dialog_List::~RGE_Dialog_List()
{
    RGE_Dialog_List *v1; // esi@1
    char **v2; // eax@1
    signed int v3; // edi@2

    v1 = this;
    v2 = this->list_text;
    this->vfptr = (TPanelVtbl *)&RGE_Dialog_List::`vftable';
    if( v2 )
    {
        v3 = 0;
        if( this->list_size > 0 )
        {
            do
            {
                if( v1->list_text[v3] )
                    free(v1->list_text[v3]);
                ++v3;
            }
            while( v3 < v1->list_size );
        }
        free(v1->list_text);
        v1->list_text = 0;
    }
    if( v1->list_info )
    {
        free(v1->list_info);
        v1->list_info = 0;
    }
    TListDialog::~TListDialog((TListDialog *)&v1->vfptr);
}

short RGE_Dialog_List::get_list_id()
{
    short result; // ax@1

    result = this->list_id;
    if( result != -1 )
        result = this->list_info[result].id;
    return result;
}

RGE_Player *RGE_Dialog_List::create_list()
{
    switch( this->list_type ){

    case 1:
        return this->create_object_list();

    default:
        return nullptr;
    }
}

RGE_Player *RGE_Dialog_List::create_object_list()
{
    RGE_Dialog_List *v1; // ebx@1
    RGE_Player *result; // eax@1
    signed short v3; // bp@2
    int v4; // edx@3
    int v5; // esi@3
    RGE_Master_Static_Object *v6; // ecx@4
    short v7; // ax@8
    int v8; // esi@11
    int v9; // ebp@12
    RGE_Master_Static_Object *v10; // eax@13
    int v11; // eax@15
    RGE_Master_Static_Object *v12; // ecx@15
    short v13; // dx@15
    signed short j; // [sp+10h] [bp-10h]@11
    int i; // [sp+14h] [bp-Ch]@11
    RGE_Player *player; // [sp+18h] [bp-8h]@1
    signed short end_i; // [sp+1Ch] [bp-4h]@2

    v1 = this;
    result = (RGE_Player *)RGE_Base_Game::get_player(rge_base_game);
    player = result;
    if( result )
    {
        v1->list_size = 1;
        v3 = result->master_object_num;
        end_i = v3;
        if( v3 > 0 )
        {
            v4 = 0;
            v5 = v3;
            do
            {
                v6 = result->master_objects[v4];
                if( v6 && !v6->hide_in_scenario_editor )
                    ++v1->list_size;
                ++v4;
                --v5;
            }
            while( v5 );
        }
        v7 = v1->list_size;
        if( v7 )
        {
            result = (RGE_Player *)calloc(v7, 0x66u);
            v1->list_info = (rdlg_list_info *)result;
            if( result )
            {
                LOWORD(result->tile_list.collapse_list) = -1;
                j = 1;
                strcpy(v1->list_info->text, aNone_1);
                v8 = 0;
                i = 0;
                if( v3 > 0 )
                {
                    v9 = 0;
                    do
                    {
                        v10 = player->master_objects[v9];
                        if( v10 && !v10->hide_in_scenario_editor )
                        {
                            v11 = j;
                            v1->list_info[v11].id = v8;
                            v12 = player->master_objects[v9];
                            v13 = v12->string_id;
                            if( v13 <= 0 )
                                strcpy(v1->list_info[v11].text, v12->name);
                            else
                                (*(void (__stdcall **)(signed int, _DWORD, int, signed int))&rge_base_game->vfptr->gap8[20])(
                                    2,
                                    v13,
                                    (int)&v1->list_info[v11],
                                    100);
                            v8 = i;
                            ++j;
                        }
                        ++v8;
                        ++v9;
                        i = v8;
                    }
                    while( (signed short)v8 < end_i );
                }
                result = (RGE_Player *)1;
            }
        }
        else
        {
            result = 0;
        }
    }
    return result;
}

int rdlg_list_compare(void *arg1, void *arg2)
{
    int v2; // eax@1
    int result; // eax@2

    v2 = CompareStringA(0x400u, 1u, (PCNZCH)arg1, -1, (PCNZCH)arg2, -1);
    if( v2 == 1 )
        result = -1;
    else
        result = v2 == 3;
    return result;
}

void RGE_Dialog_List::sort_list()
{
    qsort(this->list_info, this->list_size, 0x66u, (int (__cdecl *)(const void *, const void *))rdlg_list_compare);
}

void RGE_Dialog_List::calc_list_line()
{
    RGE_Dialog_List *v1; // ebx@1
    TPanelVtbl *v2; // eax@1
    short v3; // ax@1
    short v4; // bp@2
    short v5; // si@2

    v1 = this;
    v2 = this->vfptr;
    this->list_line = -1;
    v3 = ((int (*)(void))v2[1].handle_char)();
    if( v3 != -1 )
    {
        v4 = v1->list_size;
        v5 = 0;
        if( v4 > 0 )
        {
            while( v1->list_info[v5].id != v3 )
            {
                if( ++v5 >= v4 )
                    goto LABEL_7;
            }
            v1->list_line = v5;
        }
    }
LABEL_7:
    if( v1->list_line == -1 )
        v1->list_line = 0;
}

short RGE_Dialog_List::get_cur_id()
{
    short result; // ax@2

    if( this->list_type == 1 )
        result = rge_base_game->master_obj_id;
    else
        result = -1;
    return result;
}
