
/**
 * @file    Engine\RGE\ColorTable.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

class RGE_Color_Table
{
public:

    char color_table_name[30];

    short resource_id;

    char type;

    char map_color;

    short id;

    char table[256];

    RGE_Color_Table(int infile);
    RGE_Color_Table(char *filename);
    RGE_Color_Table(TDrawArea *surface, int amount, PALETTEENTRY *in_color, PALETTEENTRY *palette1);

    ~RGE_Color_Table();

    save(int outfile);
};

void color_log(char c1, char c2, int pos);
