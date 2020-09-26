#pragma once

#include <vector>
#include <string>

namespace xuexue {
namespace csharp {

class FileSystemInfo
{
  protected:
    //
    // 摘要:
    //     Represents the fully qualified path of the directory or file.
    //
    // 异常:
    //   T:System.IO.PathTooLongException:
    //     The fully qualified path exceeds the system-defined maximum length.
    std::string FullPath;

    //
    // 摘要:
    //     The path originally specified by the user, whether relative or absolute.
    std::string OriginalPath;

  public:
    //
    // 摘要:
    //     Gets the full path of the directory or file.
    //
    // 返回结果:
    //     A string containing the full path.
    //
    // 异常:
    //   T:System.IO.PathTooLongException:
    //     The fully qualified path and file name exceed the system-defined maximum length.
    //
    //   T:System.Security.SecurityException:
    //     The caller does not have the required permission.
    virtual std::string FullName() = 0;

    //
    // 摘要:
    //     Gets a value indicating whether the file or directory exists.
    //
    // 返回结果:
    //     true if the file or directory exists; otherwise, false.
    virtual bool Exists() = 0;

    //
    // 摘要:
    //     For files, gets the name of the file. For directories, gets the name of the last
    //     directory in the hierarchy if a hierarchy exists. Otherwise, the Name property
    //     gets the name of the directory.
    //
    // 返回结果:
    //     A string that is the name of the parent directory, the name of the last directory
    //     in the hierarchy, or the name of a file, including the file name extension.
    virtual std::string Name() = 0;

    //
    // 摘要:
    //     Deletes a file or directory.
    //
    // 异常:
    //   T:System.IO.DirectoryNotFoundException:
    //     The specified path is invalid; for example, it is on an unmapped drive.
    //
    //   T:System.IO.IOException:
    //     There is an open handle on the file or directory, and the operating system is
    //     Windows XP or earlier. This open handle can result from enumerating directories
    //     and files. For more information, see How to: Enumerate Directories and Files.
    virtual void Delete() = 0;

  private:
};

} // namespace csharp
} // namespace xuexue