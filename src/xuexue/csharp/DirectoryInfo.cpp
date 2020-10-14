#include "DirectoryInfo.h"
#include "Poco/File.h"
#include "Poco/Path.h"

namespace xuexue {
namespace csharp {

DirectoryInfo::DirectoryInfo(const std::string& originalPath)
{

    OriginalPath = originalPath;
    Poco::Path path(OriginalPath);
    if (!path.isDirectory())
        FullPath = path.absolute().makeDirectory().toString();
    else
        FullPath = path.absolute().toString();
}

DirectoryInfo::~DirectoryInfo()
{
}

std::string DirectoryInfo::FullName()
{
    return FullPath;
}

std::string DirectoryInfo::Name()
{
    Poco::Path path(FullPath);
    if (path.depth() >= 1)
        return path.directory(path.depth() - 1);
    else
        return "";
}

bool DirectoryInfo::Exists()
{
    return Poco::File(FullPath).exists();
}

void DirectoryInfo::Delete()
{
    Poco::File(FullPath).remove(true);
}

DirectoryInfo DirectoryInfo::Parent()
{
    Poco::Path path(FullPath);
    return DirectoryInfo(path.parent().makeDirectory().toString());
}

DirectoryInfo DirectoryInfo::Root()
{
    std::string device = Poco::Path(FullPath).getDevice();
#if _WIN32
    //windows上C#返回如下
    return DirectoryInfo(device + ":\\");
#else
    //mac下返回这个，其他系统可能也是
    return DirectoryInfo("/");
#endif
}

void DirectoryInfo::Create(bool recursive)
{
    Poco::File file(FullPath);
    if (recursive)
        file.createDirectories();
    else
        file.createDirectory();
}

} // namespace csharp
} // namespace xuexue