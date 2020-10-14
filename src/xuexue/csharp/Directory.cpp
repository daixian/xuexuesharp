#include "Directory.h"
#include "Poco/File.h"
#include "Poco/Path.h"

namespace xuexue {
namespace csharp {

//这玩意跟windows.h冲突了
//#define CreateDirectory CreateDirectory

DirectoryInfo Directory::createDirectory(const std::string& path)
{
    Poco::File dir(path);
    dir.createDirectories();
    return DirectoryInfo(path);
}

void Directory::Delete(const std::string& path, bool recursive)
{
    Poco::File dir(Poco::Path(path).makeDirectory().toString());
    dir.remove(recursive);
}

bool Directory::Exists(const std::string& path)
{
    Poco::File dir(Poco::Path(path).makeDirectory().toString());
    return dir.exists();
}

} // namespace csharp
} // namespace xuexue