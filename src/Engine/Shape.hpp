
/**
 * @file    Engine\Shape.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

class TShape
{
public:

	char *shape;

	int load_type = -1;
	int load_size = 0;

	struct Shape_Header *shape_header;

	struct Shape_File_Header *head;

	struct Shape_Offsets *offsets;

	struct SLhape_File_Header *FShape;

	struct Shape_Info *shape_info;

	TShape();
	TShape(char *filename, int resource_file_id);

	~TShape();

	char Check_shape(int shape_num, char *proc);

	int is_loaded();

	char shape_bounds(int shape_num, short *width, short *height);

	int shape_count();

	char shape_minmax(int *x_min, int *y_min, int *x_max, int *y_max, int shape_num);

	char shape_check(int check_x, int check_y, int shape_num);

	char shape_draw(TDrawArea *drawarea, int x, int y, int shape_num, char flags, char *color_table);
	char shape_draw_unclipped(TDrawArea *drawarea, int shape_x0, int shape_y0, int shape_num);
	char shape_color_trans_unclipped(TDrawArea *drawarea, int shape_x0, int shape_y0, int shape_num, char *color_table);
	char shape_shadow_unclipped(TDrawArea *drawarea, int shape_x0, int shape_y0, char *color_table);
	char shape_draw_clipped(TDrawArea *drawarea, int shape_x0, int shape_y0, int clip_x0, int clip_y0, int clip_x1, int clip_y1);
	char shape_color_trans_clipped(TDrawArea *drawarea, int shape_x0, int shape_y0, int shape_num, int clip_x0, int clip_y0, int clip_x1, int clip_y1, char *color_table);
	char shape_shadow_clipped(TDrawArea *drawarea, int shape_x0, int shape_y0, int clip_x0, int clip_y0, int clip_x1, int clip_y1, char *color_table);

	char shape_mirror(TDrawArea *drawarea, int x, int y, int shape_num, char flags, char *color_table);
	char shape_mirror_unclipped(TDrawArea *drawarea, int shape_x1, int shape_y0);
	char shape_mirror_color_trans_unclipped(TDrawArea *drawarea, int shape_x1, int shape_y0, int shape_num, char *color_table);
	char shape_mirror_shadow_unclipped(TDrawArea *drawarea, int shape_x1, int shape_y0, char *color_table);
	char shape_mirror_clipped(TDrawArea *drawarea, int shape_x1, int shape_y0, int clip_x0, int clip_y0, int clip_x1, int clip_y1);
	char shape_mirror_color_trans_clipped(TDrawArea *drawarea, int shape_x1, int shape_y0, int shape_num, int clip_x0, int clip_y0, int clip_x1, int clip_y1, char *color_table);
	char shape_mirror_shadow_clipped(TDrawArea *drawarea, int shape_x1, int shape_y0, int clip_x0, int clip_y0, int clip_x1, int clip_y1, char *color_table);

	char shape_dither(TDrawArea *drawarea, int x, int y, int shape_num, int dx, int dy);

	char shape_dithered_unclipped(TDrawArea *drawarea, int shape_x0, int shape_y0, int dx, int dy);
	char shape_dithered_clipped(TDrawArea *drawarea, int shape_x0, int shape_y0, int clip_x0, int clip_y0, int clip_x1, int clip_y1, int dx, int dy);
};

struct Shape_Info
{
	unsigned int Shape_Data_Offsets;
	unsigned int Shape_Outline_Offset;

	int Reserved1;
	int Reserved2;

	int Width;
	int Height;

	int Hotspot_X;
	int Hotspot_Y;
};

struct SLhape_File_Header
{
	char Version[4];

	int Num_Shapes;

	char Comment[24];
};

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

	int xmin;
	int ymin;
	int xmax;
	int ymax;
};
