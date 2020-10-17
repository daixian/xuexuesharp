#include "Directory.h"
#include "Poco/File.h"
#include "Poco/Path.h"

namespace xuexue {
namespace csharp {

//这玩意跟windows.h冲突了
//#define CreateDirectory CreateDirectory

DirectoryInfo Directory::createDirectory(const std::string& path)
{
    Poco::File dir(Poco::Path(path).absolute().makeDirectory().toString());
    dir.createDirectories();
    return DirectoryInfo(path);
}

void Directory::Delete(const std::string& path, bool recursive)
{
    Poco::File dir(Poco::Path(path).absolute().makeDirectory().toString());
    dir.remove(recursive);
}

bool Directory::Exists(const std::string& path)
{
    Poco::File dir(Poco::Path(path).absolute().makeDirectory().toString());
    return dir.exists();
}

std::vector<std::string> Directory::GetFiles(const std::string& path)
{
    //这里必须要手动转成绝对路径，否则在mac下无法获得文件
    Poco::File dir(Poco::Path(path).absolute().makeDirectory().toString());

    std::vector<Poco::File> vFiles;
    dir.list(vFiles);

    std::vector<std::string> result;
    for (size_t i = 0; i < vFiles.size(); i++) {
        Poco::File& file = vFiles[i];
        if (file.isFile() && file.exists()) {
            Poco::Path filePath(vFiles[i].path());
            //添加绝对路径到结果
            result.push_back(filePath.absolute().makeFile().toString());
        }
    }
    return result;
}

std::vector<std::string> Directory::GetDirectories(const std::string& path)
{
    //这里必须要手动转成绝对路径，否则在mac下无法获得文件
    Poco::File dir(Poco::Path(path).absolute().makeDirectory().toString());

    std::vector<Poco::File> vFiles;
    dir.list(vFiles);

    std::vector<std::string> result;
    for (size_t i = 0; i < vFiles.size(); i++) {
        Poco::File& file = vFiles[i];
        if (file.isDirectory() && file.exists()) {
            Poco::Path filePath(vFiles[i].path());
            //添加绝对路径到结果
            result.push_back(filePath.absolute().makeDirectory().toString());
        }
    }
    return result;
}

} // namespace csharp
} // namespace xuexue
