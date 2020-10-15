#pragma once
#include <vector>
#include <string>
#include "FileSystemInfo.h"

namespace xuexue {
namespace csharp {

class FileInfo : FileSystemInfo
{
  public:
    //必须要有一个默认构造函数,用来拷贝,否则有些STL模板可能使用不了.
    FileInfo();
    FileInfo(const std::string& fileName);
    ~FileInfo();

    /**
     * 获取目录或文件的完整目录.
     *
     * @author daixian
     * @date 2020/9/26
     *
     * @returns A std::string.
     */
    virtual std::string FullName();

    /**
     * 文件是否存在
     *
     * @author daixian
     * @date 2020/9/26
     *
     * @returns True if it succeeds, false if it fails.
     */
    virtual bool Exists();

    /**
     * 获取文件名,带扩展名.
     *
     * @author daixian
     * @date 2020/9/26
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

    /**
     * 获取文件名,不带扩展名.
     *
     * @author daixian
     * @date 2020/9/26
     *
     * @returns A std::string.
     */
    std::string BaseName();

    /**
     * Gets the extension
     *
     * @author daixian
     * @date 2020/9/26
     *
     * @returns A std::string.
     */
    std::string Extension();

    //
    // 摘要:
    //     Gets a string representing the directory's full path.
    //     获取表示目录的完整路径的字符串。
    //
    // 返回结果:
    //     A string representing the directory's full path.
    //
    // 异常:
    //   T:System.ArgumentNullException:
    //     null was passed in for the directory name.
    //
    //   T:System.IO.PathTooLongException:
    //     The fully qualified path name exceeds the system-defined maximum length.
    //
    //   T:System.Security.SecurityException:
    //     The caller does not have the required permission.
    std::string DirectoryName();

  private:
};

} // namespace csharp
} // namespace xuexue