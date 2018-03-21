/**
 * @file main.cpp
 * @author Rafal Grzeszczuk
 * @copyright (C) 2018 ACK CYFRONET AGH
 * @copyright This software is released under the Apache 2.0 license cited in
 * 'LICENSE.txt'
 */
#include "FileSystem.h"
#include "FSFile.h"
#include <iostream>
#include <memory>

int main(int argc, char * argv [] ){
	auto fs = std::make_unique<FileSystem>(argc,argv);
	return 0;
}
