/**
 * @file FSFile.cpp
 * @author Rafal Grzeszczuk
 * @copyright (C) 2018 ACK CYFRONET AGH
 * @copyright This software is released under the Apache 2.0 license cited in
 * 'LICENSE.txt'
 */
#include "FSFile.h"
//Set some arbitrary values
FSFile::FSFile(std::string path):FSItem(path){
	this->finfo->st->st_mode = S_IFREG | 0644;
	this->finfo->st->st_nlink = 1;
	this->finfo->st->st_size=0;
	this->finfo->st->st_uid=getuid();
	this->finfo->st->st_gid=getgid();
	this->finfo->st->st_atime = time( nullptr );
	this->finfo->st->st_mtime = time( nullptr );
}
FSFile::FSFile(std::string path, std::string contents):FSFile(path){
	this->fileContents=contents;
	this->finfo->st->st_size=contents.length();
}
std::shared_ptr<std::string> FSFile::getFileContents(){
	return this->getFileContents(0);
}
std::shared_ptr<std::string> FSFile::getFileContents(int offset){
	this->finfo->st->st_atime = time( nullptr );
		auto str = std::make_shared<std::string>(this->finfo->st->st_size-1, 'x');
		return str;
}
void FSFile::setFileContents(int in){
	this->finfo->st->st_atime = time( nullptr );
	this->finfo->st->st_mtime = time( nullptr );
	this->finfo->st->st_size=in;
}
