#include "FileInfo.h"
#include "Poco/File.h"
#include "Poco/Path.h"

namespace xuexue {
namespace csharp {

FileInfo::FileInfo()
{
}

FileInfo::FileInfo(const std::string& fileName)
{
    OriginalPath = fileName;
    Poco::Path path(OriginalPath);
    FullPath = path.absolute().makeFile().toString();
}

FileInfo::~FileInfo()
{
}

std::string FileInfo::FullName()
{
    return FullPath;
}

bool FileInfo::Exists()
{
    return Poco::File(FullPath).exists();
}

std::string FileInfo::Name()
{
    //FileName是带扩展名的
    return Poco::Path(FullPath).getFileName();
}

void FileInfo::Delete()
{
    Poco::File(FullPath).remove();
}

std::string FileInfo::BaseName()
{
    return Poco::Path(FullPath).getBaseName();
}

std::string FileInfo::Extension()
{
    return Poco::Path(FullPath).getExtension();
}

std::string FileInfo::DirectoryName()
{
    return Poco::Path(FullPath).parent().makeDirectory().toString();
}

} // namespace csharp
} // namespace xuexue
