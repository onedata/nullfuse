#define FUSE_USE_VERSION 30
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
	public:
	FileSystem(int,char**);
	~FileSystem();
	static std::shared_ptr<FSItem> getFileHandle(std::string);
	
};
