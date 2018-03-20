#include "FSItem.h"

FSItem::FSItem(std::string itemName){
	this->name=itemName;
	this->finfo=std::make_unique<FSFileInfo>();
	
}
std::shared_ptr<FSItem> FSItem::getFile(std::string name){
	try{
		return this->flist.at(name);
	} catch(const std::exception& e){
		return std::make_shared<FSItem>(nullptr);
	}
}
std::shared_ptr<FSFileInfo> FSItem::getMeta(){
	try{
		return this->finfo;
	} catch(std::exception &e){
		return std::make_shared<FSFileInfo>(nullptr);
	}
}
std::map<std::string, std::shared_ptr<FSItem> > FSItem::getFlist(){
	return this->flist;
}
