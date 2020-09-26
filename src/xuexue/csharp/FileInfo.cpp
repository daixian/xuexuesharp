#include "FileInfo.h"

namespace xuexue {
namespace csharp {

class FileInfo::Impl
{
  public:
    Impl() {}
    ~Impl() {}

  private:
};

FileInfo::FileInfo()
{
    _impl = new Impl();
}

FileInfo::~FileInfo()
{
    delete _impl;
}

} // namespace csharp
} // namespace xuexue