#pragma once
#include <vector>
#include <string>
#include <memory>

#include "FileInfo.h"

namespace xuexue {
namespace csharp {

class DirectoryInfo : FileSystemInfo
{
  public:
    //必须要有一个默认构造函数,用来拷贝,否则有些STL模板可能使用不了.
    DirectoryInfo();
    DirectoryInfo(const std::string& path);
    ~DirectoryInfo();

    /**
     * 获取目录的完整路径.
     * 在C#中 D:/test/12233234 会返回 D:\\test\\12233234
     * 同时,D:/test/12233234/ 会返回 D:\\test\\12233234\\
     * C#中这存在两种情况。
     * 在这个函数中一定会返回D:\\test\\12233234\\，即最后会带上斜杠。
     *
     * @author daixian
     * @date 2020/9/26
     *
     * @returns A std::string.
     */
    virtual std::string FullName();

    //
    // 摘要:
    //     Gets a value indicating whether the directory exists.
    //
    // 返回结果:
    //     true if the directory exists; otherwise, false.
    virtual bool Exists();

    /**
     * 返回一个目录的最后一级的名字.
     *
     * @author daixian
     * @date 2020/10/15
     *
     * @returns A std::string.
     */
    virtual std::string Name();

    /**
     * Deletes this object
     *
     * @author daixian
     * @date 2020/9/26
     */
    virtual void Delete();

    //
    // 摘要:
    //     Gets the parent directory of a specified subdirectory.
    //
    // 返回结果:
    //     The parent directory, or null if the path is null or if the file path denotes
    //     a root (such as \, C:\, or \\server\share).
    //
    // 异常:
    //   T:System.Security.SecurityException:
    //     The caller does not have the required permission.
    DirectoryInfo Parent();

    //
    // 摘要:
    //     Gets the root portion of the directory.
    //
    // 返回结果:
    //     An object that represents the root of the directory.
    //
    // 异常:
    //   T:System.Security.SecurityException:
    //     The caller does not have the required permission.
    DirectoryInfo Root();

    //
    // 摘要:
    //     Creates a directory.
    //
    // 异常:
    //   T:System.IO.IOException:
    //     The directory cannot be created.
    void Create(bool recursive = true);

    //
    // 摘要:
    //     Returns a file list from the current directory matching the given search pattern.
    //
    // 参数:
    //   searchPattern:
    //     The search string to match against the names of files. This parameter can contain
    //     a combination of valid literal path and wildcard (* and ?) characters, but it
    //     doesn't support regular expressions.
    //
    // 返回结果:
    //     An array of type System.IO.FileInfo.
    //
    // 异常:
    //   T:System.ArgumentException:
    //     searchPattern contains one or more invalid characters defined by the System.IO.Path.GetInvalidPathChars
    //     method.
    //
    //   T:System.ArgumentNullException:
    //     searchPattern is null.
    //
    //   T:System.IO.DirectoryNotFoundException:
    //     The path is invalid (for example, it is on an unmapped drive).
    //
    //   T:System.Security.SecurityException:
    //     The caller does not have the required permission.
    std::vector<FileInfo> GetFiles();

    //
    // 摘要:
    //     Returns the subdirectories of the current directory.
    //
    // 返回结果:
    //     An array of System.IO.DirectoryInfo objects.
    //
    // 异常:
    //   T:System.IO.DirectoryNotFoundException:
    //     The path encapsulated in the System.IO.DirectoryInfo object is invalid, such
    //     as being on an unmapped drive.
    //
    //   T:System.Security.SecurityException:
    //     The caller does not have the required permission.
    //
    //   T:System.UnauthorizedAccessException:
    //     The caller does not have the required permission.
    std::vector<DirectoryInfo> GetDirectories();

  private:
};

} // namespace csharp
} // namespace xuexue
