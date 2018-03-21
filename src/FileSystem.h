/**
 * @file FileSystem.h
 * @author Rafal Grzeszczuk
 * @copyright (C) 2018 ACK CYFRONET AGH
 * @copyright This software is released under the Apache 2.0 license cited in
 * 'LICENSE.txt'
 */
#include <fuse.h>
#include <cstdlib>
#include <unistd.h>
#include <map>
#include <sstream>
#include <iostream>
#include <vector>
#include <memory>
#include "FSDir.h"
#include "FSFile.h"


class FileSystem {
	static std::shared_ptr<FSDir> root;
	static int do_getattr(const char * path, struct stat *st);
	static int do_readdir(const char * path, void *buffer, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi);
	static int do_read(const char *path, char *buffer, size_t size, off_t offset, struct fuse_file_info *fi);
	static int do_create(const char * path, mode_t mode, struct fuse_file_info *);
	static int do_mkdir(const char* path, mode_t mode);
	static int do_times(const char *, const struct timespec tv[2]);
	static int do_write(const char *path, const char *buffer, size_t size, off_t offset, struct fuse_file_info *fi);
	static int do_open(const char* path, struct fuse_file_info *finfo);
	static int do_truncate(const char* path, off_t off);
	public:
	FileSystem(int,char**);
	~FileSystem();
	static std::shared_ptr<FSItem> getFileHandle(std::string);
};
