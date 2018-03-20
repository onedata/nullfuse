#pragma once
#include "FSItem.h"
class FSFile : public FSItem {
	std::string fileContents;
	public:
	FSFile(std::string path);
	FSFile(std::string path, std::string initial_contents);
	std::shared_ptr<std::string> getFileContents(int);
	std::shared_ptr<std::string> getFileContents();
	void setFileContents(int in);

};
