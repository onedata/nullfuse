#pragma once
#include "FSItem.h"
class FSFile : public FSItem {
	std::string fileContents;
	public:
	FSFile(std::string path);
	FSFile(std::string path, std::string initial_contents);
	std::string *getFileContents();
	void setFileContents(char* in);

};
