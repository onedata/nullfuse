#include "FileSystem.h"
#include "FSFile.h"
#include <iostream>
#include <memory>

int main(int argc, char * argv [] ){
	auto fs = std::make_unique<FileSystem>(argc,argv);
	
	/*
	((FSDir*)fs.get()->getFileHandle("/").get())->createDir("test");
	((FSDir*)fs.get()->getFileHandle("/").get())->createFile("test2","testowycontent");
	((FSDir*)fs.get()->getFileHandle("/").get())->ls();
	std::cout<<((FSFile*)fs.get()->getFileHandle("/test2").get())->getMeta().get()->getStat()->st_size;
	std::cout<<((FSFile*)fs.get()->getFileHandle("/test2").get())->getFileContents()->c_str();
	*/
}
