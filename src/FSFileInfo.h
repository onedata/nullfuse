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
