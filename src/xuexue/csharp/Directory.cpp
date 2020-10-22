#include "Directory.h"
#include "Poco/File.h"
#include "Poco/Path.h"
#include <regex>
#include <deque>

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

std::string Directory::GetCurrentDirectory()
{
    return Poco::Path::current();
}

std::vector<std::string> Directory::GetFiles(const std::string& path)
{
    std::vector<std::string> result;
    //这里必须要手动转成绝对路径，否则在mac下无法获得文件
    Poco::File dir(Poco::Path(path).absolute().makeDirectory().toString());

    std::vector<Poco::File> vFiles;
    dir.list(vFiles);

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
    std::vector<std::string> result;
    //这里必须要手动转成绝对路径，否则在mac下无法获得文件
    Poco::File dir(Poco::Path(path).absolute().makeDirectory().toString());

    std::vector<Poco::File> vFiles;
    dir.list(vFiles);

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

std::vector<std::string> Directory::GetFiles(const std::string& path, const std::string& searchPattern, SearchOption searchOption)
{
    std::vector<std::string> result;

    if (searchOption == SearchOption::TopDirectoryOnly) {
        //如果只搜索顶层
        //这里必须要手动转成绝对路径，否则在mac下无法获得文件
        Poco::File dir(Poco::Path(path).absolute().makeDirectory().toString());
        std::vector<Poco::File> vFiles;
        dir.list(vFiles);

        for (size_t i = 0; i < vFiles.size(); i++) {
            Poco::File& file = vFiles[i];
            if (file.isFile() && file.exists()) {
                //如果文件存在并且是文件
                Poco::Path filePath(vFiles[i].path());

                std::smatch sm;
                const std::regex pattern(searchPattern);
                //getFileName()是带扩展名的文件名
                if (std::regex_search(filePath.getFileName(), sm, pattern)) {
                    //添加绝对路径到结果
                    result.push_back(filePath.absolute().makeFile().toString());
                }
            }
        }
    }
    else {
        //如果是所有层级搜索
        std::deque<std::string> que;
        //添加进去起始根目录
        que.push_back(Poco::Path(path).absolute().makeDirectory().toString());
        while (!que.empty()) {
            Poco::File dir(que.front());
            que.pop_front();

            std::vector<Poco::File> vFiles;
            dir.list(vFiles);

            for (size_t i = 0; i < vFiles.size(); i++) {
                Poco::File& file = vFiles[i];
                if (file.exists()) {
                    if (file.isFile()) {
                        //如果文件存在并且是文件
                        Poco::Path filePath(file.path());

                        std::smatch sm;
                        const std::regex pattern(searchPattern);
                        //getFileName()是带扩展名的文件名
                        if (std::regex_search(filePath.getFileName(), sm, pattern)) {
                            //添加绝对路径到结果
                            result.push_back(filePath.absolute().makeFile().toString());
                        }
                    }
                    else if (file.isDirectory()) {
                        //如果是文件夹,那么就添加到队列里去
                        que.push_back(Poco::Path(file.path()).absolute().makeDirectory().toString());
                    }
                }
            }
        }
    }
    return result;
}

std::vector<std::string> Directory::GetDirectories(const std::string& path, const std::string& searchPattern, SearchOption searchOption)
{
    std::vector<std::string> result;

    if (searchOption == SearchOption::TopDirectoryOnly) {
        //如果只搜索顶层
        //这里必须要手动转成绝对路径，否则在mac下无法获得文件
        Poco::File dir(Poco::Path(path).absolute().makeDirectory().toString());
        std::vector<Poco::File> vFiles;
        dir.list(vFiles);

        for (size_t i = 0; i < vFiles.size(); i++) {
            Poco::File& file = vFiles[i];
            if (file.isDirectory() && file.exists()) {
                //如果文件存在并且是文件夹
                Poco::Path filePath(vFiles[i].path());

                std::smatch sm;
                const std::regex pattern(searchPattern);
                //getFileName()是带扩展名的文件名
                if (std::regex_search(filePath.getFileName(), sm, pattern)) {
                    //添加绝对路径到结果
                    result.push_back(filePath.absolute().makeFile().toString());
                }
            }
        }
    }
    else {
        //如果是所有层级搜索
        std::deque<std::string> que;
        //添加进去起始根目录
        que.push_back(Poco::Path(path).absolute().makeDirectory().toString());
        while (!que.empty()) {
            Poco::File dir(que.front());
            que.pop_front();

            std::vector<Poco::File> vFiles;
            dir.list(vFiles);

            for (size_t i = 0; i < vFiles.size(); i++) {
                Poco::File& file = vFiles[i];
                if (file.exists()) {
                    if (file.isDirectory()) {
                        //如果存在并且是文件夹
                        Poco::Path filePath(file.path());
                        //如果是文件夹,那么就添加到队列里去
                        que.push_back(filePath.absolute().makeDirectory().toString());

                        std::smatch sm;
                        const std::regex pattern(searchPattern);
                        //getFileName()是带扩展名的文件名
                        if (std::regex_search(filePath.getFileName(), sm, pattern)) {
                            //添加绝对路径到结果
                            result.push_back(filePath.absolute().makeFile().toString());
                        }
                    }
                }
            }
        }
    }
    return result;
}

} // namespace csharp
} // namespace xuexue
