
/**
 * @file    Engine\RGE\Picture.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

class TPicture
{
public:

	BITMAPINFOHEADER *Dib;
	BITMAPINFO256 *BitmapInfo;
	char *Bits;
	TRANSINFO *TransInfo;

	int OwnMemory;
	int Width;
	int Height;
	short Orien = 1;

	TPicture(char *FileName, int res_id, int UseTrans, void *MapToPal, int ZeroIsTrans);
	TPicture(int infile, int UseTrans);

	~TPicture();

	void Save(int outfile);

	void Load(char *FileName, int res_id, int UseTrans, void *MapToPal, int ZeroIsTrans);

	void Init(BITMAPINFO256 *FromInfo, char *FromBits, TRANSINFO *FromTrans);

	char AlignedWidth();

	void Draw(TDrawArea *DrawArea, int DestX, int DestY, int Mirror, int Flip);

	int Tile(TDrawArea *DrawArea, int DestX, int DestY, int DestWid, int DestHgt, int BlockWid, int BlockHgt, int SrcX, int SrcY, int SrcWid, int SrcHgt);

	char GetPixel(int x, int y, int Mirror, int Flip);
};
