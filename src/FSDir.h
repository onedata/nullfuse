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
