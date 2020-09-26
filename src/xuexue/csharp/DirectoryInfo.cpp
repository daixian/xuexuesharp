#include "DirectoryInfo.h"

namespace xuexue {
namespace csharp {

class DirectoryInfo::Impl
{
  public:
    Impl() {}
    ~Impl() {}

  private:
};

DirectoryInfo::DirectoryInfo()
{
    _impl = new Impl();
}

DirectoryInfo::~DirectoryInfo()
{
    delete _impl;
}

} // namespace csharp
} // namespace xuexue