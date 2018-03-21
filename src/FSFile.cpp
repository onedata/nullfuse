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
std::shared_ptr<std::string> FSFile::getFileContents(){
	return this->getFileContents(0);

}
std::shared_ptr<std::string> FSFile::getFileContents(int offset){
	this->finfo->st->st_atime = time( NULL );
	try{
		auto str = std::make_shared<std::string>(this->finfo->st->st_size-1, 'x');
		return str;
	} catch(std::exception &ex){
		return nullptr;
		
	}
	
}
void FSFile::setFileContents(int in){
	this->finfo->st->st_atime = time( NULL );
	this->finfo->st->st_mtime = time( NULL );
	this->finfo->st->st_size=in;
	//the line below can be used to actually copy some useful data. Disabled for benchmarking. Also, needs some type modifications
	//this->fileContents=std::string(in);
}
