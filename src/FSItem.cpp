/**
 * @file FSItem.cpp
 * @author Rafal Grzeszczuk
 * @copyright (C) 2018 ACK CYFRONET AGH
 * @copyright This software is released under the Apache 2.0 license cited in
 * 'LICENSE.txt'
 */
#include "FSItem.h"

FSItem::FSItem(std::string itemName){
	this->name=itemName;
	this->finfo=std::make_unique<FSFileInfo>();
}
std::shared_ptr<FSItem> FSItem::getFile(std::string name){
	return this->flist.at(name);
}
std::shared_ptr<FSFileInfo> FSItem::getMeta(){
	return this->finfo;
}
std::map<std::string, std::shared_ptr<FSItem> > FSItem::getFlist(){
	return this->flist;
}

