/**
 * @file FSDir.cpp
 * @author Rafal Grzeszczuk
 * @copyright (C) 2018 ACK CYFRONET AGH
 * @copyright This software is released under the Apache 2.0 license cited in
 * 'LICENSE.txt'
 */
#include "FSDir.h"
#include "FSFile.h"

FSDir::FSDir(std::string path):FSItem(path){
	this->finfo.get()->st->st_mode = S_IFDIR | 0755;
	this->finfo.get()->st->st_nlink = 1;
	this->finfo->st->st_mtime = time( nullptr );
}
void FSDir::createFile(std::string fname){
	this->flist.emplace(fname,std::make_shared<FSFile>(fname));
}
void FSDir::createFile(std::string fname, std::string contents){
	this->flist.emplace(fname,std::make_shared<FSFile>(fname,contents));
}
void FSDir::createDir(std::string fname){
	this->flist.emplace(fname,std::make_shared<FSDir>(fname));
}
bool FSDir::subFileExists(std::string fname){
	auto mapIterator = this->flist.find(fname);
	return mapIterator != this->flist.end();
}

