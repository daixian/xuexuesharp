#include "FileInfo.h"
#include "Poco/File.h"
#include "Poco/Path.h"

namespace xuexue {
namespace csharp {

class FileInfo::Impl
{
  public:
    Impl(const std::string& fileName) : path(fileName), file(fileName)
    {}
    ~Impl() {}

    Poco::Path path;
    Poco::File file;

  private:
};

FileInfo::FileInfo(const std::string& fileName)
{
    _impl = new Impl(fileName);
    OriginalPath = fileName;
    FullPath = _impl->path.absolute().toString();
}

FileInfo::~FileInfo()
{
    delete _impl;
}

std::string FileInfo::FullName()
{
    return FullPath;
}

std::string FileInfo::Extension()
{
    return _impl->path.getExtension();
}

bool FileInfo::Exists()
{
    return _impl->file.exists();
}

std::string FileInfo::Name()
{
    //FileName是带扩展名的
    return _impl->path.getFileName();
}

std::string FileInfo::BaseName()
{
    return _impl->path.getBaseName();
}

void FileInfo::Delete()
{
    _impl->file.remove();
}

} // namespace csharp
} // namespace xuexue