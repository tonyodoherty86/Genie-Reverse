#pragma once

/**
 * @file    Engine\ResFile.h
 * @author  Yvan Burrie
 * @date    2018/08/21
 * @version 1.0
 */


#include <stdio.h>
/**
 * Determines whether the current stream will have compression.
 */
int ENABLE_COMPRESSION = 0;

#if PROTOTYPE_SWGB
    #define RESFILE_HEADER_BANNER_LEN 60
#else
    #define RESFILE_HEADER_BANNER_LEN 40
#endif

struct resfile_header
{
    char banner_msg[RESFILE_HEADER_BANNER_LEN];
    char version[4];
    char password[12];
    int num_res_types;
    int directory_size;
};

struct ResFileHdr
{
    char *mapped_file;
    int handle;
    resfile_header *header;
    ResFileHdr *next;
    char res_name[260];
};

void RESFILE_open_new_resource_file(
    char *resFileName,
    char *password,
    char *path,
    int open_mode );

void RESFILE_close_new_resource_file(char *res_file);

bool RESFILE_locate_resource(char *rType, unsigned int rId, int *file, int *offset, char **mapped_file, int *size);

char *RESFILE_load(char *rType, unsigned int rId, int *rLoadType, int *rDataSize);

char *RESFILE_Extract_to_File(char *rType, unsigned int rId, char *file_name, FILE **file);

void RESFILE_Set_Missing_Flag(int FlagVal);

bool RESFILE_Decommit_Mapped_Memory(char *ResData, int resSize);

bool RESFILE_build_res_file(char *build_list_file, char *source_path, char *target_path);

int BUILDRES_get_files_resource_type(char *filename);

#define RES_FILE_TYPE_EXTENSION_BINARY 'bina'

struct res_file_type_info
{
    char extension[4];
    unsigned int rType;
};

struct resfile_type_dir_node
{
    unsigned int type;
    int dirOffset;
    int numID;
};

struct BuildRes_id_node
{
    unsigned int id;
    int dataOffset;
    char *resData;
    int resSize;
    BuildRes_id_node *next;
    char fName[260];
};

struct BuildRes_type_node
{
    unsigned int type;
    int idOffset;
    int nIds;
    BuildRes_id_node *idList;
    BuildRes_type_node *next;
};

struct resfile_id_dir_node
{
    unsigned int id;
    int itemOffset;
    int itemSize;
};
