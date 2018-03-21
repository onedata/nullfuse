/**
 * @file FSFile.h
 * @author Rafal Grzeszczuk
 * @copyright (C) 2018 ACK CYFRONET AGH
 * @copyright This software is released under the Apache 2.0 license cited in
 * 'LICENSE.txt'
 */
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
