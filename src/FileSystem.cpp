#include "FileSystem.h"
std::shared_ptr<FSDir> FileSystem::root=nullptr;
FileSystem::FileSystem(int argc, char ** argv){
	
	FileSystem::root=std::make_unique<FSDir>("/");
	/*DEBUG directories
	((FSDir*)getFileHandle("/").get())->createDir("BDMV");
	((FSDir*)getFileHandle("/").get())->createDir("AACS");
	((FSDir*)getFileHandle("/").get())->createFile("test","ala ma kota");
	*/
	//Set up C library callbacks...
	static struct fuse_operations operations{};
		operations.getattr = do_getattr;
		operations.readdir = do_readdir;
		operations.read    = do_read;
		operations.create  = do_create;
		operations.mkdir   = do_mkdir;
		operations.utimens = do_times;
		operations.write   = do_write;
	fuse_main(argc,argv,&operations, NULL);
	
}
FileSystem::~FileSystem(){

}
//Traverse the tree and return a shared pointer to the desired file, or NULLPTR if the file doesn't exist
std::shared_ptr<FSItem> FileSystem::getFileHandle(std::string path){
	std::shared_ptr<FSItem> currentFile = root;
	if(path.compare("/")==0) return root;
	std::stringstream ss(path);
	std::string item;
	//tokenize the path and traverse the tree
	while(std::getline(ss, item, '/')){
		if(item.length()==0) continue;
		try{
			currentFile=currentFile->getFile(item);
		} catch(const std::exception &e){
			return std::shared_ptr<FSItem>(nullptr);
		}
	}
	return currentFile;
	
} 
int FileSystem::do_getattr(const char * path, struct stat *st){
	auto fileHandle = getFileHandle(std::string(path));
	if(fileHandle==nullptr) return -ENOENT;
	std::memcpy(st,  fileHandle->getMeta()->getStat(),  sizeof(struct stat));
	return 0;
	
}
int FileSystem::do_readdir(const char * path, void *buffer, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi){
	auto fileHandle = getFileHandle(std::string(path));
	std::map<std::string,std::shared_ptr<FSItem> >::iterator it;
	//the filler function is given to us by FUSE. It fills the directory listings with the contents we want to.
	if(filler(buffer,".",NULL,0)!=0 || filler(buffer,".",NULL,0)!=0) 
		return -1;
	for(auto const& fileItem : fileHandle->getFlist()){
		if(filler(buffer,fileItem.first.c_str(),NULL,0)!=0) 
			return -ENOENT;
	}
	return 0;
}
int FileSystem::do_read(const char *path, char *buffer, size_t size, off_t offset, struct fuse_file_info *fi){
	auto fileHandle = getFileHandle(std::string(path));
	auto str = ((FSFile*)fileHandle.get())->getFileContents(offset);
	try{
		memcpy(buffer, str->c_str(), size);
		return size;
	} catch(std::exception &ex){
		std::cerr<<ex.what()<<std::endl;
		return 0;	
	}
	
	
}
int FileSystem::do_create(const char * path, mode_t mode, struct fuse_file_info *finfo){
	std::stringstream ss(path);	
	std::cerr<<path;
	std::string item;
	std::shared_ptr<FSItem> currentFile = root;
	std::shared_ptr<FSItem> prevFile = root;
	//tokenize the path and traverse the tree
	while(std::getline(ss, item, '/')){
		if(item.length()==0) continue;
		try{
			if(((FSDir*)currentFile.get())->subFileExists(item))
				currentFile=currentFile->getFile(item);
			else break;	 
		} catch(std::exception &e){
			std::cerr<<"cannot create file: " << e.what();
			return -EIO;
		}
	}
	//If we exited the traversal, but have not reached the end of the path, then at some point we hit a nonexistent dir. Return error.
	if(std::getline(ss,item,'/')) return -ENOENT;
	((FSDir*)currentFile.get())->createFile(item);
	return 0;
}
int FileSystem::do_times(const char * path, const struct timespec tv[2]){
	return 0; //mock function.
}
int FileSystem::do_mkdir(const char * path, mode_t mode){
	std::stringstream ss(path);
	std::string item;
	std::shared_ptr<FSItem> currentFile = root;
	std::shared_ptr<FSItem> prevFile = root;
	//tokenize the path and traverse the tree
	while(std::getline(ss, item, '/')){
		if(item.length()==0) continue;
		//attempt to create the directory. Works as mkdir -p.
		try{
			if(((FSDir*)currentFile.get())->subFileExists(item))
				currentFile=currentFile->getFile(item);
			else ((FSDir*)currentFile.get())->createDir(item);	 
		} catch(std::exception &e){
			return -EIO;
		}
	}
	((FSDir*)currentFile.get())->createFile(item);
	
	return 0;
}
int FileSystem::do_write(const char *path, const char *buffer, size_t size, off_t offset, struct fuse_file_info *fi){
	try{
		auto f = getFileHandle(std::string(path)); 
		//auto str = std::make_shared<std::string>(size+offset,'x');
		((FSFile*)f.get())->setFileContents(size+offset);
	}
	catch (std::exception &e){
		return -EIO;
	}
	return size;
	
}
