
/**
 * @file    Compress.hpp
 * @author  Yvan Burrie
 * @date    2018/08/21
 * @version 1.0
 */

int deflate_data( void *info_data, void *data, int a3, int a4 );

int deflate_deinit( int a1 );

int deflate_init( void *a1, int a2, int a3, int a4, void *a5, int a6, int a7 );

int deflate_buf_size();

int Inf32BufSize();

int Inf32Decode( int Offset, int Size, int Flags );
