#pragma once
#include <fuse.h>
#include <map>
#include <string>
#include <unistd.h>
#include <memory>
#include "FSFileInfo.h"
#include <iostream>

class FSItem {
	protected:
	std::string name;
	std::shared_ptr<FSFileInfo> finfo;
	std::map<std::string, std::shared_ptr<FSItem> > flist;
	public:
	FSItem(std::string itemName);
	std::shared_ptr<FSItem> getFile(std::string name);
	std::shared_ptr<FSFileInfo> getMeta();
	std::map<std::string, std::shared_ptr<FSItem> > getFlist();
	
};
