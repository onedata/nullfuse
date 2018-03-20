#include "FSFile.h"
//Set some arbitrary values
FSFile::FSFile(std::string path):FSItem(path){
	this->finfo->st->st_mode = S_IFREG | 0644;
	this->finfo->st->st_nlink = 1;
	this->finfo->st->st_size=0;
	this->finfo->st->st_uid=getuid();
	this->finfo->st->st_gid=getgid();
	this->finfo->st->st_atime = time( NULL );
	this->finfo->st->st_mtime = time( NULL );
	
}
FSFile::FSFile(std::string path, std::string contents):FSFile(path){
	this->fileContents=std::string(contents);
	this->finfo->st->st_size=contents.length();
}

std::string * FSFile::getFileContents(){
	this->finfo->st->st_atime = time( NULL );
	std::string * str = new std::string(this->finfo->st->st_size-1, 'x');
	return str;
}
void FSFile::setFileContents(char* in){
	this->finfo->st->st_atime = time( NULL );
	this->finfo->st->st_mtime = time( NULL );
	this->finfo->st->st_size=std::strlen(in);
	//the line below can be used to actually copy some useful data. Disabled for benchmarking.
	//this->fileContents=std::string(in);
}
