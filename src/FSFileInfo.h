/**
 * @file FSFileInfo.h
 * @author Rafal Grzeszczuk
 * @copyright (C) 2018 ACK CYFRONET AGH
 * @copyright This software is released under the Apache 2.0 license cited in
 * 'LICENSE.txt'
 */
#ifndef FSFileInfo_h
#define FSFileInfo_h
#include <cstdlib>
#include <memory>
#include <sys/stat.h>
#include <sys/types.h>
#include <cstring>
class FSFileInfo{
	public:
	std::shared_ptr<struct stat> st;
	FSFileInfo();
	FSFileInfo(std::shared_ptr<FSFileInfo> src);
	struct stat * getStat();
};
#endif
