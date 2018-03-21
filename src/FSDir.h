/**
 * @file FSDir.h
 * @author Rafal Grzeszczuk
 * @copyright (C) 2018 ACK CYFRONET AGH
 * @copyright This software is released under the Apache 2.0 license cited in
 * 'LICENSE.txt'
 */
#include "FSItem.h"
class FSDir : public FSItem {
	public:
	FSDir(std::string path);
	bool subFileExists(std::string name);
	void createFile(std::string fname);
	void createFile(std::string fname, std::string contents);
	void createDir(std::string fname);
	void ls();
};
