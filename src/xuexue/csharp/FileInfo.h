#pragma once
#include <vector>
#include <string>
#include "FileSystemInfo.h"

namespace xuexue {
namespace csharp {

class FileInfo : FileSystemInfo
{
  public:
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

    /**
     * Deletes this object
     *
     * @author daixian
     * @date 2020/9/26
     */
    virtual void Delete();

  private:
    class Impl;
    Impl* _impl = nullptr;
};

} // namespace csharp
} // namespace xuexue