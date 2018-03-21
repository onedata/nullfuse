#include "FileSystem.h"
#include "FSFile.h"
#include <iostream>
#include <memory>

int main(int argc, char * argv [] ){
	auto fs = std::make_unique<FileSystem>(argc,argv);
	return 0;
}
