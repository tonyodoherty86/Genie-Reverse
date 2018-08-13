
/**
 * @file    Engine\Shape.hpp
 * @author  Yvan Burrie
 * @date    2018/07/29
 * @version 1.0
 */

#ifndef SHAPE_SLP_AVAILABLE
    #define SHAPE_SLP_AVAILABLE TRUE
#endif

#define SHAPE_HEADER_VERSION "1.10"

/**
 *
 */
class TShape
{
public:

    struct Shape_Load *shape;

    int load_type = -1;

    int load_size = 0;

    struct Shape_Header *shape_header;

    struct Shape_File_Header *head;

    struct Shape_Offsets *offsets;

//#if SHAPE_SLP_AVAILABLE
    struct SLhape_File_Header *FShape;
//#endif

    struct Shape_Info *shape_info;

    TShape( char *filename, int resource_file_id );

    ~TShape();

    /**
     * @brief Determines if a shape is valid
     * @param int shape_num
     * @return bool Returns TRUE if the shape is invalid, otherwise FALSE.
    */
    bool Check_shape( int shape_num );

    /**
     * @brief Determines whether the Shape was loaded.
     * @return bool
     */
    bool is_loaded();

    /**
     * @param int shape_num Determines the ID of the Shape.
     * @param short *width Obtains the X-dimension of the Shape.
     * @param short *height Obtains the Y-dimension of the Shape.
     * @return bool
     */
    bool shape_bounds( int shape_num, short *width, short *height );

    /**
     * @brief Obtains the total number of shapes.
     * @return int
     */
    int shape_count();

    /**
     *
     */
    bool shape_minmax(
        int *x_min,
        int *y_min,
        int *x_max,
        int *y_max,
        int shape_num );

    bool shape_check( int check_x, int check_y, int shape_num );

public:

    bool shape_draw(
        TDrawArea *drawarea,
        int x,
        int y,
        int shape_num,
        char flags,
        char *color_table );

protected:

    bool shape_draw_unclipped(
        TDrawArea *drawarea,
        int shape_x0,
        int shape_y0,
        int shape_num );

    bool shape_color_trans_unclipped(
        TDrawArea *drawarea,
        int shape_x0,
        int shape_y0,
        int shape_num,
        char *color_table );

    bool shape_shadow_unclipped(
        TDrawArea *drawarea,
        int shape_x0,
        int shape_y0,
        char *color_table );

    bool shape_draw_clipped(
        TDrawArea *drawarea,
        int shape_x0,
        int shape_y0,
        int clip_x0,
        int clip_y0,
        int clip_x1,
        int clip_y1 );

    bool shape_color_trans_clipped(
        TDrawArea *drawarea,
        int shape_x0,
        int shape_y0,
        int shape_num,
        int clip_x0,
        int clip_y0,
        int clip_x1,
        int clip_y1,
        char *color_table );

    bool shape_shadow_clipped(
        TDrawArea *drawarea,
        int shape_x0,
        int shape_y0,
        int clip_x0,
        int clip_y0,
        int clip_x1,
        int clip_y1,
        char *color_table );

public:

    bool shape_mirror(
        TDrawArea *drawarea,
        int x,
        int y,
        int shape_num,
        char flags,
        char *color_table );

protected:

    bool shape_mirror_unclipped(
        TDrawArea *drawarea,
        int shape_x1,
        int shape_y0 );

    bool shape_mirror_color_trans_unclipped(
        TDrawArea *drawarea,
        int shape_x1,
        int shape_y0,
        int shape_num,
        char *color_table );

    bool shape_mirror_shadow_unclipped(
        TDrawArea *drawarea,
        int shape_x1,
        int shape_y0,
        char *color_table );

    bool shape_mirror_clipped(
        TDrawArea *drawarea,
        int shape_x1,
        int shape_y0,
        int clip_x0,
        int clip_y0,
        int clip_x1,
        int clip_y1 );

    bool shape_mirror_color_trans_clipped(
        TDrawArea *drawarea,
        int shape_x1,
        int shape_y0,
        int shape_num,
        int clip_x0,
        int clip_y0,
        int clip_x1,
        int clip_y1,
        char *color_table );

    bool shape_mirror_shadow_clipped(
        TDrawArea *drawarea,
        int shape_x1,
        int shape_y0,
        int clip_x0,
        int clip_y0,
        int clip_x1,
        int clip_y1,
        char *color_table );

public:

    bool shape_dither(
        TDrawArea *drawarea,
        int x,
        int y,
        int shape_num,
        int dx,
        int dy );

protected:

    bool shape_dithered_unclipped(
        TDrawArea *drawarea,
        int shape_x0,
        int shape_y0,
        int dx,
        int dy );

    bool shape_dithered_clipped(
        TDrawArea *drawarea,
        int shape_x0,
        int shape_y0,
        int clip_x0,
        int clip_y0,
        int clip_x1,
        int clip_y1,
        int dx,
        int dy );
};

struct Shape_Info
{
    unsigned int Shape_Data_Offsets;

    unsigned int Shape_Outline_Offset;

    int Reserved1, Reserved2;

    int Width, Height;

    int Hotspot_X, Hotspot_Y;
};

//#if SHAPE_SLP_AVAILABLE
struct SLhape_File_Header
{
    char Version[4];

    int Num_Shapes;

    char Comment[24];
};
//#endif

struct Shape_Offsets
{
    int shape;

    int palette;
};

struct Shape_File_Header
{
    int version;

    int shape_num;
};

struct Shape_Header
{
    int bounds;

    int origin;

    int xmin, ymin, xmax, ymax;
};

struct Shape_Load
{
    char version[4];

    int num_shapes;

    Shape_Offsets *offsets;

    int gap1[4];

    /**
     * Offset: 32.
     */
    Shape_Info *info;
};
