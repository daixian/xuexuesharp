#include "Path.h"

#if defined(_WIN32) || defined(_WIN64)
#    include <windows.h>
#    include <ShlObj.h> //SHGetSpecialFolderPath
//#elif defined(__linux__)
#else
#    include <unistd.h>
#    include <sys/types.h>
#    include <pwd.h>
#endif

#include "Poco/Path.h"
#include "String.h"

namespace xuexue {
namespace csharp {

#if defined(_WIN32) || defined(_WIN64)

std::string Path::ModuleDir(void* handle)
{
    std::string moduleDir;
    wchar_t exeFullPath[MAX_PATH]; // Full path
    // 这里如果用A函数那么会返回GBK的路径,然后GBK的路径在conan中会失败,所以必须要使用W的函数
    GetModuleFileNameW((HMODULE)handle, exeFullPath, MAX_PATH);

    std::string strPath = "";
    strPath = String::UTF16ToUTF8(std::wstring(exeFullPath)); //转成UTF8的路径
    // 这个是exe的路径,要裁剪成dir
    size_t pos = strPath.find_last_of('\\', strPath.length());
    moduleDir = strPath.substr(0, pos); // Return the directory without the file name
    return moduleDir;
}
#elif __APPLE__
#    include "TargetConditionals.h"
#    if TARGET_IPHONE_SIMULATOR
// iOS Simulator

#    elif TARGET_OS_IPHONE
// iOS device

#    elif TARGET_OS_MAC
// Other kinds of Mac OS

std::string Path::ModuleDir()
{
    //算了mac下就用这个随便返回一下算了
    return Poco::Path::current();
}

#    else
#        error "Unknown Apple platform"
#    endif

#elif __ANDROID__
// android

#elif __linux__
// linux

std::string Path::ModuleDir()
{
    std::string moduleDir;
    char arg1[32];
    char exepath[512 + 1] = {0};
    snprintf(arg1, sizeof(arg1), "/proc/%d/exe", getpid());
    readlink(arg1, exepath, sizeof(exepath));
    std::string exeStr = std::string(exepath);
    size_t pos = exeStr.find_last_of('/', exeStr.length());
    moduleDir = exeStr.substr(0, pos); // Return the directory without the file name
    return moduleDir;
}

#elif __unix__ // all unices not caught above
// Unix

#elif defined(_POSIX_VERSION)

// POSIX
#endif

std::string Path::DataHome()
{
    return Poco::Path::dataHome();
}

std::string Path::Current()
{
    return Poco::Path::current();
}

std::string Path::Home()
{
    return Poco::Path::home();
}

std::string Path::Temp()
{
    return Poco::Path::temp();
}

std::string Path::Combine(const std::string& path1, const std::string& path2)
{
    Poco::Path p1(path1);
    Poco::Path p2(path2);
    Poco::Path p3 = Poco::Path(p1.makeDirectory(), p2);
    return p3.toString();
}

std::string Path::Combine(const std::string& path1, const std::string& path2, const std::string& path3)
{
    Poco::Path p = Poco::Path(Poco::Path(path1).makeDirectory(), Poco::Path(path2));
    p = Poco::Path(p.makeDirectory(), Poco::Path(path3));
    return p.toString();
}

std::string Path::Combine(const std::string& path1, const std::string& path2, const std::string& path3, const std::string& path4)
{
    Poco::Path p = Poco::Path(Poco::Path(path1).makeDirectory(), Poco::Path(path2));
    p = Poco::Path(p.makeDirectory(), Poco::Path(path3));
    p = Poco::Path(p.makeDirectory(), Poco::Path(path4));
    return p.toString();
}

std::string Path::Combine(const std::vector<std::string>& paths)
{
    if (paths.size() == 0) {
        return "";
    }
    Poco::Path p(paths[0]);
    for (size_t i = 0; i < paths.size() - 1; i++) {
        p = Poco::Path(p.makeDirectory(), Poco::Path(paths[i + 1]));
    }
    return p.toString();
}

std::string Path::ToRelative(const std::string& path)
{
    return String::TrimStart(path, {'\\', '/'});
}

bool Path::IsPathFullyQualified(const std::string& path)
{
    Poco::Path p(path);
#if WIN32
    //在windows下如果是相对地址,或者是没有盘符
    if (p.isRelative() || p.getDevice().empty()) {
        return false;
    }
#else
    if (p.isRelative()) {
        return false;
    }
#endif
    else {
        return true;
    }
}

bool Path::IsPathRooted(const std::string& path)
{
    Poco::Path p(path);
    return p.isAbsolute();
}

std::string Path::GetPathRoot(const std::string& path)
{
    if (path.empty()) {
        return "";
    }

    //如果开头是绝对符号那么按照.net的api返回这个
    char c0 = path.at(0);
    if (c0 == '\\' || c0 == '/') {
        std::string s;
        s.push_back(c0);
        return s;
    }
    Poco::Path p(path);
    // windows下这函数返回的是C
#if WIN32
    if (!p.getDevice().empty())
        return p.getDevice() + ":\\";
    return "";
#else
    return p.getDevice();
#endif
}

std::string Path::GetDirectoryName(const std::string& path)
{
    Poco::Path p(path);
    if (p.isFile()) {
        if (p.depth() == 0) {
            // 此时返回根目录盘符
            return p.parent().toString();
        }
        return String::TrimEnd(p.parent().toString(), {'\\', '/'});
    }
    else if (p.isDirectory()) {
        if (p.depth() == 0) {
            // 此时是根目录盘符
            return "";
        }
        return String::TrimEnd(path, {'\\', '/'});
    }
    return "";
}

std::string Path::GetExtension(const std::string& path)
{
    Poco::Path p(path);
    std::string ext = p.getExtension();
    if (!ext.empty()) {
        return "." + ext;
    }
    return "";
}

} // namespace csharp
} // namespace xuexue
