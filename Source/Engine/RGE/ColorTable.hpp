
/**
 * @file    Engine\RGE\ColorTable.hpp
 * @author  Yvan Burrie
 * @date    2018/07/04
 * @version 1.0
 */

#ifndef RGE_COLOR_TABLE_NAME_EXISTS
    #define RGE_COLOR_TABLE_NAME_EXISTS FALSE
#endif

#ifndef RGE_COLOR_TABLE_RESOURCE_EXISTS
    #define RGE_COLOR_TABLE_RESOURCE_EXISTS FALSE
#endif

#ifndef RGE_COLOR_TABLE_ID_LONG
    #define RGE_COLOR_TABLE_ID_LONG FALSE
#endif

#ifndef RGE_COLOR_TABLE_EXTRAS_EXIST
    #define RGE_COLOR_TABLE_EXTRAS_EXIST FALSE
#endif

#ifndef RGE_COLOR_TABLE_PALETTE_POINTER
    #define RGE_COLOR_TABLE_PALETTE_POINTER FALSE
#endif

#ifndef RGE_COLOR_TABLE_TEXT_EXIST
    #define RGE_COLOR_TABLE_TEXT_EXIST FALSE
#endif

class RGE_Color_Table
{
public:

#if RGE_COLOR_TABLE_NAME_EXISTS
    char color_table_name[30];
#endif

#if RGE_COLOR_TABLE_RESOURCE_EXISTS
    short resource_id = -1;
#endif

    char type;

    char map_color;

#if RGE_COLOR_TABLE_ID_LONG
    int id = -1;
#else
    short id = -1;
#endif

#if RGE_COLOR_TABLE_TEXT_EXIST
    int text_color_id;
#endif

#if RGE_COLOR_TABLE_PALETTE_POINTER
    void *table;
#else
    char table[256];
#endif

#if RGE_COLOR_TABLE_EXTRAS_EXIST

    int base_color_index        = -1;
    int outline_color_index     = -1;
    int selection_color_index_1 = -1;
    int selection_color_index_2 = -1;
    int mini_map_color_index_1  = -1;
    int mini_map_color_index_2  = -1;
    int mini_map_color_index_3  = -1;
    int text_color_table_id     = -1;

    int unk1;
    int unk2;

    char unk3;
    char unk4;
    char unk5;
    char unk6;

#endif // RGE_COLOR_TABLE_EXTRAS_EXIST

    RGE_Color_Table(
        int infile);

    RGE_Color_Table(
        char *filename);

    RGE_Color_Table(
        TDrawArea *surface,
        int amount,
        PALETTEENTRY *in_color,
        PALETTEENTRY *palette1);

    ~RGE_Color_Table();

    int get_text_id();

    int get_id();

    save(
        int outfile);
};

void RGE_translate_palette(
    PALETTEENTRY *palette1,
    PALETTEENTRY *palette2,
    PALETTEENTRY color,
    int amount,
    int ignore_color1,
    int ignore_color2);

void RGE_fade_palette(
    TDrawArea *surface,
    PALETTEENTRY color,
    float fade_time,
    char direction,
    PALETTEENTRY *new_palette,
    int ignore_color1,
    int ignore_color2);

void color_log(
    char c1,
    char c2,
    int pos);
