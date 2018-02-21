
int compression_point[129];
int current_handle;
char flags[12];
char *buffers;
int dword_86B274;
char *current;
size_t file_size;
char *file_buffers;
bool rge_write_error;

int rge_fake_open(int file_handle, int fake_size)
{
    if ( file_handle >= 0 )
    {
        flags[0] = 2;

        *(_DWORD *)&flags[4] = 0;

        buffers = (char *)calloc(0x10000u, 1u);

        current = buffers;

        file_buffers = 0;

        *(_DWORD *)&flags[8] = 0;

        current_handle = file_handle;

        file_size = fake_size;
    }

    return file_handle;
}

int rge_open(char *filename, int flag)
{
    int v2 = _open(filename, flag);

    if ( v2 >= 0 )
    {
        flags[0] = 2;
        *(_DWORD *)&flags[4] = 0;
        buffers = (char *)calloc(0x10000u, 1u);
        current = buffers;
        file_buffers = 0;
        *(_DWORD *)&flags[8] = 0;
        current_handle = v2;
        lseek(v2, 0, 2);
        file_size = _tell(v2);
        dword_86B274 = 0;
        lseek(v2, 0, 0);
    }

    return v2;
}

int rge_open(char *filename, int flag, int pmode)
{
    int v3 = _open(filename, flag, pmode);

    if ( v3 >= 0 )
    {
        flags[0] = 2;
        *(_DWORD *)&flags[4] = 0;
        buffers = (char *)calloc(0x10000u, 1u);
        current = buffers;
        file_buffers = 0;
        *(_DWORD *)&flags[8] = 0;
        current_handle = v3;
        lseek(v3, 0, 2);
        file_size = _tell(v3);
        dword_86B274 = 0;
        lseek(v3, 0, 0);
    }

    return v3;
}

int rge_fake_close(int handle)
{
    if ( handle >= 0 && handle == current_handle )
    {
        if ( buffers )
        {
            free(buffers);
            buffers = 0;
        }
        if ( *(_DWORD *)&flags[8] )
        {
            free(*(void **)&flags[8]);
            *(_DWORD *)&flags[8] = 0;
        }
        if ( file_buffers )
        {
            free(file_buffers);
            file_buffers = 0;
        }
        current_handle = -1;
    }
    return handle;
}

int rge_close(int handle)
{
    int v1 = handle;

    if ( handle >= 0 && handle == current_handle )
    {
        if ( flags[0] == 1 && *(_DWORD *)&flags[8] )
        {
            if ( deflate_data(*(int *)&flags[8], 0, 0, 1) == 2 )
                rge_write_error = true;
            
            deflate_deinit(*(int *)&flags[8]);
        }
        current_handle = -1;

        if ( buffers )
        {
            free(buffers);
            buffers = 0;
        }
        if ( *(_DWORD *)&flags[8] )
        {
            free(*(void **)&flags[8]);
            *(_DWORD *)&flags[8] = 0;
        }
        if ( file_buffers )
        {
            delete file_buffers;
            file_buffers = 0;
        }
        v1 = close(handle);
    }

    return v1;
}

void rge_read_uncompressed(int handle, void *data, int size)
{
    if ( handle >= 0 && handle == current_handle )
    {
        read(handle, data, size);
        file_size -= size;
    }
}

void rge_write_uncompressed(int handle, void *data, int size)
{
    if ( handle >= 0 && handle == current_handle && _write(handle, data, size) <= 0 )
        rge_write_error = true;
}

void rge_read(int handle, int temp_max, int size)
{
	if ( ENABLE_COMPRESSION )
	{
		if ( handle >= 0 && handle == current_handle )
		{
			if ( flags[0] )
			{
				*(_DWORD *)&flags[8] = calloc(Inf32BufSize(), 1u);
				file_buffers = (char *)calloc(file_size, 1u);
				
				read(handle, file_buffers, file_size);
				
				compression_point[0] = 0;
				
				temp_max = 0x10000;

				Inf32Decode((int)buffers, (int)file_buffers, a1, a2, file_size);
				
				compression_point[0] += file_size;
				
				flags[0] = 0;
			}
			v8 = size;
			v9 = *(_DWORD *)&flags[4];
			v10 = current;

			if ( size + *(_DWORD *)&flags[4] >= 0x10000 )
			{
				do
				{
					v11 = (char *)data;

					v12 = 0x10000 - v9;

					v13 = (unsigned int)(0x10000 - v9) >> 2;

					qmemcpy(data, v10, 4 * v13);

					v15 = &v10[4 * v13];
					v14 = &v11[4 * v13];

					v16 = -(char)v9 & 3;

					qmemcpy(v14, v15, v16);
					
					file_size = file_size;
					
					temp_max = 0x10000;
					
					Inf32Decode(compression_point[0], (int)&file_size, 0x10000 - v9, (int)&v14[v16], (int)&v15[v16]);
					
					v10 = buffers;
					
					v8 -= v12;
					
					v9 = 0;
					
					compression_point[0] += handle;
					
					*(_DWORD *)&flags[4] = 0;
					
					data = (char *)data + v12;
					
					current = buffers;
				}
				while ( v8 >= 0x10000 );
			}
			if ( v8 > 0 )
			{
				qmemcpy(data, v10, v8);
				*(_DWORD *)&flags[4] += v8;
				current += v8;
			}
		}
	}
	else if ( handle >= 0 && handle == current_handle )
	{
		read(handle, data, size);
		file_size -= size;
		dword_86B274 += size;
	}
}

int rge_buffer_full(char *out_buf_ofs, int out_buf_size)
{
    if ( _write(current_handle, out_buf_ofs, out_buf_size) <= 0 )
        rge_write_error = true;
    
    return 0;
}

void rge_write(int handle, void *data, int size)
{
    if ( ENABLE_COMPRESSION )
    {
        if ( handle >= 0 && handle == current_handle )
        {
            if ( flags[0] != 1 )
            {
                flags[0] = 1;
                *(_DWORD *)&flags[8] = calloc(deflate_buf_size(), 1u);
                deflate_init(*(int *)&flags[8], 75, 2, 1, (int)buffers, 0x10000, (int)rge_buffer_full);
            }
            if ( deflate_data(*(int *)&flags[8], (int)data, size, 0) == 2 )
                rge_write_error = true;
        }
    }
    else if ( handle >= 0 && handle == current_handle && _write(handle, data, size) <= 0 )
    {
        rge_write_error = true;
    }
}
