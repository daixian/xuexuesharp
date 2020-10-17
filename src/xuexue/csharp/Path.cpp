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

namespace xuexue {
namespace csharp {

//只需要使用api获得一次就行了
std::string moduleDir;

#if defined(_WIN32) || defined(_WIN64)

std::string Path::ModuleDir()
{
    if (!moduleDir.empty()) {
        return moduleDir; //只要有记录了就直接使用
    }
    else {
        char exeFullPath[MAX_PATH]; // Full path
        std::string strPath = "";

        GetModuleFileNameA(NULL, exeFullPath, MAX_PATH);

        strPath = std::string(exeFullPath); // Get full path of the file
        size_t pos = strPath.find_last_of('\\', strPath.length());
        moduleDir = strPath.substr(0, pos); // Return the directory without the file name
        return moduleDir;
    }
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
    if (!moduleDir.empty()) {
        return moduleDir; //只要有记录了就直接使用
    }
    else {
        char arg1[32];
        char exepath[512 + 1] = {0};
        snprintf(arg1, sizeof(arg1), "/proc/%d/exe", getpid());
        readlink(arg1, exepath, sizeof(exepath));
        std::string exeStr = std::string(exepath);
        size_t pos = exeStr.find_last_of('/', exeStr.length());
        moduleDir = exeStr.substr(0, pos); // Return the directory without the file name
        return moduleDir;
    }
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

} // namespace csharp
} // namespace xuexue