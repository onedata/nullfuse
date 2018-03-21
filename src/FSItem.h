/**
 * @file FSItem.h
 * @author Rafal Grzeszczuk
 * @copyright (C) 2018 ACK CYFRONET AGH
 * @copyright This software is released under the Apache 2.0 license cited in
 * 'LICENSE.txt'
 */
#ifndef FSItem_h
#define FSItem_h
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
	virtual ~FSItem()=default;
	public:
	FSItem(std::string itemName);
	std::shared_ptr<FSItem> getFile(std::string name);
	std::shared_ptr<FSFileInfo> getMeta();
	std::map<std::string, std::shared_ptr<FSItem> > getFlist();
	
};
#endif
