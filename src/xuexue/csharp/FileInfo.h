#pragma once
#include <vector>
#include <string>
#include "FileSystemInfo.h"

namespace xuexue {
namespace csharp {

class FileInfo : FileSystemInfo
{
  public:
    FileInfo();
    ~FileInfo();

  private:
    class Impl;
    Impl* _impl = nullptr;
};

} // namespace csharp
} // namespace xuexue