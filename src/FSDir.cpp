#include "FSDir.h"
#include "FSFile.h"
#include <iostream>
FSDir::FSDir(std::string path):FSItem(path){
	this->finfo.get()->st.get()->st_mode = S_IFDIR | 0755;
	this->finfo.get()->st.get()->st_nlink = 1;
	this->finfo.get()->st.get()->st_size=0;
	this->finfo->st->st_atime = time( NULL );
	this->finfo->st->st_mtime = time( NULL );
	
}
void FSDir::createFile(std::string fname){
	std::shared_ptr<FSFile> f = std::make_shared<FSFile>(fname);
	this->flist.insert(std::pair<std::string,std::shared_ptr<FSFile> >(fname,f));
}
void FSDir::createFile(std::string fname, std::string contents){
	std::shared_ptr<FSFile> f = std::make_shared<FSFile>(fname,contents);
	this->flist.insert(std::pair<std::string,std::shared_ptr<FSFile> >(fname,f));
}
void FSDir::createDir(std::string fname){
	std::shared_ptr<FSDir> f = std::make_shared<FSDir>(fname);
	this->flist.insert(std::pair<std::string,std::shared_ptr<FSDir> >(fname,f));
}
void FSDir::ls(){
	std::map<std::string,std::shared_ptr<FSItem> >::iterator it;
	for(it = this->flist.begin(); it != this->flist.end(); it++)
		std::cout<<it->first <<"\n";
}
bool FSDir::subFileExists(std::string fname){
	//std::shared_ptr<FSFile> f = std::make_shared<FSFile>(fname);
	auto mapIterator = this->flist.find(fname);
	return mapIterator != this->flist.end();
}
