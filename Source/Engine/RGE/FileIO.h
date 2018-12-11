#pragma once

/**
 * @file    Engine\RGE\FileIO.h
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 *
 * This is the input-output file system used by the RGE components for serializing data.
 * Most of the serialized data is compressed by ZLib technology.
 */

#include <cstddef>

int rge_fake_open(int file_handle, size_t fake_size);

int rge_open(char *filename, int flag);

int rge_open(char *filename, int flag, int pmode);

int rge_fake_close(int handle);

int rge_close(int handle);

void rge_read_uncompressed(int handle, void *data, size_t size);

void rge_write_uncompressed(int handle, void *data, size_t size);

void rge_read(int handle, void *data, size_t size);

int rge_buffer_full(char *out_buf_ofs, size_t out_buf_size);

void rge_write(int handle, void *data, size_t size);
