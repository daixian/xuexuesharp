#pragma once
#include <vector>
#include <string>
#include "FileInfo.h"

namespace xuexue {
namespace csharp {

class DirectoryInfo : FileSystemInfo
{
  public:
    DirectoryInfo();
    ~DirectoryInfo();

    //
    // 摘要:
    //     Gets the name of this System.IO.DirectoryInfo instance.
    //
    // 返回结果:
    //     The directory name.
    std::string Name();

    //
    // 摘要:
    //     Gets a value indicating whether the directory exists.
    //
    // 返回结果:
    //     true if the directory exists; otherwise, false.
    bool Exists();

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

  private:
    class Impl;
    Impl* _impl = nullptr;
};

} // namespace csharp
} // namespace xuexue