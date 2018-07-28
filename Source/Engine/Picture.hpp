
/**
 * @file    Engine\RGE\Picture.hpp
 * @author  Yvan Burrie
 * @date    2018/07/01
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

    int Width  = 0,
        Height = 0;

    enum Orientation
    {
        None = -1,
        Zero = 0,
        One = 1,
    };

    short Orien = TPicture::Orientation::One;

    TPicture(
        char *FileName,
        int res_id,
        bool UseTrans,
        HPALETTE *MapToPal,
        bool ZeroIsTrans);

    TPicture(
        int infile,
        bool UseTrans);

    ~TPicture();

    void Save(
        int outfile);

    void Load(
        char *FileName,
        int res_id,
        bool UseTrans,
        HPALETTE *MapToPal,
        bool ZeroIsTrans);

    void Init(
        BITMAPINFO256 *FromInfo,
        char *FromBits,
        TRANSINFO *FromTrans);

    int AlignedWidth();

    void Draw(
        TDrawArea *DrawArea,
        int DestX, int DestY,
        bool Mirror,
        bool Flip);

    int Tile(
        TDrawArea *DrawArea,
        int DestX,    int DestY,
        int DestWid,  int DestHgt,
        int BlockWid, int BlockHgt,
        int SrcX,     int SrcY,
        int SrcWid,   int SrcHgt);

    char GetPixel(
        int x, int y,
        bool Mirror,
        bool Flip);
};
