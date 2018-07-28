
/**
 * @file    Engine\RGE\FileIO.c
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

int compression_point[129];

int current_handle = -1;

struct Compression_Info
{
    int state;
    size_t size;
    void *data;
};
Compression_Info *flags;

void *buffers;

int dword_86B274;

void *current;

size_t file_size;

void *file_buffers;

bool rge_write_error = FALSE;

int rge_fake_open(int file_handle, size_t fake_size)
{
    if( file_handle >= 0 ){

        flags->state = 2;
        flags->size = 0;
        buffers = calloc(0x10000u, 1);
        current = buffers;
        file_buffers = NULL;
        flags->data = NULL;
        current_handle = file_handle;
        file_size = fake_size;
    }
    return file_handle;
}

int rge_open(char *filename, int flag)
{
    int cur_h = open(filename, flag);
    if( cur_h >= 0 ){

        flags->state = 2;
        flags->size = 0;
        buffers = calloc(0x10000u, 1u);
        current = buffers;
        file_buffers = NULL;
        flags->data = NULL;
        current_handle = cur_h;
        lseek(cur_h, 0, SEEK_END);
        file_size = tell(cur_h);
        dword_86B274 = 0;
        lseek(cur_h, 0, SEEK_SET);
    }
    return cur_h;
}

int rge_open(char *filename, int flag, int pmode)
{
    int cur_h = open(filename, flag, pmode);
    if( cur_h >= 0 ){

        flags->state = 2;
        flags->size = 0;
        buffers = calloc(0x10000u, 1);
        current = buffers;
        file_buffers = NULL;
        flags->data = NULL;
        current_handle = cur_h;
        lseek(cur_h, 0, SEEK_END);
        file_size = tell(cur_h);
        dword_86B274 = 0;
        lseek(cur_h, 0, SEEK_SET);
    }
    return cur_h;
}

int rge_fake_close(int handle)
{
    if( handle >= 0 &&
        handle == current_handle ){

        if( buffers ){
            free(buffers);
            buffers = NULL;
        }
        if( flags->data ){
            free(flags->data);
            flags->data = NULL;
        }
        if( file_buffers ){
            free(file_buffers);
            file_buffers = NULL;
        }
        current_handle = -1;
    }
    return handle;
}

int rge_close(int handle)
{
    int result = handle;

    if( handle >= 0 &&
        handle == current_handle ){

        if( flags->state == 1 &&
            flags->data ){
            if( deflate_data(flags->data, 0, 0, 1) == 2 ){
                rge_write_error = TRUE;
            }
            deflate_deinit((int)flags->data);
        }
        current_handle = -1;

        if( buffers ){
            free(buffers);
            buffers = NULL;
        }
        if( flags->data ){
            free(flags->data);
            flags->data = NULL;
        }
        if( file_buffers ){
            free(file_buffers);
            file_buffers = NULL;
        }
        result = close(handle);
    }
    return result;
}

void rge_read_uncompressed(int handle, void *data, size_t size)
{
    if( handle >= 0 &&
        handle == current_handle ){

        read(handle, data, size);
        file_size -= size;
    }
}

void rge_write_uncompressed(int handle, void *data, size_t size)
{
    if( handle >= 0 &&
        handle == current_handle &&
        write(handle, data, size) <= 0 ){

        rge_write_error = TRUE;
    }
}

void rge_read(int handle, void *data, size_t size)
{
    int temp_max;

	if( ENABLE_COMPRESSION ){
		if( handle >= 0 &&
            handle == current_handle ){
			if( flags->state ){
				flags->data = calloc(Inf32BufSize(), 1u);
				file_buffers = calloc(file_size, 1u);
				read(handle, file_buffers, file_size);
				compression_point[0] = 0;
				temp_max = 0x10000;
				Inf32Decode((int)buffers, (int)file_buffers, file_size);
				compression_point[0] += file_size;
				flags->state = 0;
			}
			int v8 = size;
			int v9 = flags->size;
			void *v10 = current;

			if( size + flags->size >= 0x10000 ){
				do{
					void *v11 = data;
					int v12 = 0x10000 - v9;
					size_t v13 = (unsigned int)(0x10000 - v9) >> 2;
					memcpy(data, v10, 4 * v13);
					//void *v15 = v10[4 * v13];
					//void *v14 = v11[4 * v13];
					size_t v16 = -(char)v9 & 3;
					//memcpy(v14, v15, v16);
					file_size = file_size;
					temp_max = 0x10000;
					//Inf32Decode(compression_point[0], (int)&file_size, 0x10000 - v9, (int)&v14[v16], (int)&v15[v16]);
					v10 = buffers;
					v8 -= v12;
					v9 = 0;
					compression_point[0] += handle;
					flags->size = 0;
					data = (char *)data + v12;
					current = buffers;
				}
				while( v8 >= 0x10000 );
			}
			if( v8 > 0 ){
				memcpy(data, v10, v8);
				flags->size += v8;
				current += v8;
			}
		}
	}else if( handle >= 0 && handle == current_handle ){
		read(handle, data, size);
		file_size -= size;
		dword_86B274 += size;
	}
}

int rge_buffer_full(char *out_buf_ofs, size_t out_buf_size)
{
    if( write(current_handle, out_buf_ofs, out_buf_size) <= 0 ){
        rge_write_error = TRUE;
    }
    return 0;
}

void rge_write(int handle, void *data, size_t size)
{
    if( ENABLE_COMPRESSION ){
        if( handle >= 0 &&
            handle == current_handle ){

            if( flags->state != 1 ){
                flags->state = 1;
                flags->data = calloc(deflate_buf_size(), 1u);
                //deflate_init(flags->data, 75, 2, 1, buffers, 0x10000, rge_buffer_full);
            }
            if( deflate_data(flags->data, data, size, 0) == 2 ){
                rge_write_error = TRUE;
            }
        }
    }else{
        if( handle >= 0 &&
            handle == current_handle &&
            write(handle, data, size) <= 0 ){

            rge_write_error = TRUE;
        }
    }
}
