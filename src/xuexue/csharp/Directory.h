#pragma once
#include <vector>
#include <string>

#include "DirectoryInfo.h"

namespace xuexue {
namespace csharp {

class Directory
{
  public:
    /** 搜索文件夹的设置 */
    enum class SearchOption
    {
        //
        // 摘要:
        //     Includes only the current directory in a search operation.
        TopDirectoryOnly = 0,
        //
        // 摘要:
        //     Includes the current directory and all its subdirectories in a search operation.
        //     This option includes reparse points such as mounted drives and symbolic links
        //     in the search.
        AllDirectories = 1
    };

    /**
     * 在指定路径中创建所有目录和子目录，除非它们已经存在.
     *
     * @author daixian
     * @date 2020/9/26
     *
     * @param  path 要创建的目录.
     *
     * @returns 一个表示在指定路径的目录的对象。 无论指定路径的目录是否已经存在，都将返回此对象.
     */
    static DirectoryInfo createDirectory(const std::string& path);

    /**
     * 删除文件夹.
     *
     * @author daixian
     * @date 2020/10/15
     *
     * @param  path      要删除的目录.
     * @param  recursive (Optional) 如果为true,递归的删除这个文件夹里所有的文件.
     */
    static void Delete(const std::string& path, bool recursive = true);

    /**
     * 文件夹是否存在.
     *
     * @author daixian
     * @date 2020/10/15
     *
     * @param  path 文件夹路径.
     *
     * @returns 如果文件夹存在返回true.
     */
    static bool Exists(const std::string& path);

    /**
     * 拷贝一个文件夹成目标文件夹.
     *
     * @author daixian
     * @date 2021/4/7
     *
     * @param  sourceDirName 源文件夹.
     * @param  destDirName   目标文件夹.
     * @param  overwrite     (Optional) 是否覆盖,否会有异常抛出.
     */
    static void Copy(const std::string& sourceDirName, const std::string& destDirName, bool overwrite = true);

    /**
     * 拷贝一个文件夹成为目标文件夹的一个子文件夹.
     *
     * @author daixian
     * @date 2021/4/7
     *
     * @param  sourceDirName 源文件夹.
     * @param  destDirName   目标文件夹.
     * @param  overwrite     (Optional) 是否覆盖,否会有异常抛出.
     */
    static void CopyIn(const std::string& sourceDirName, const std::string& destDirName, bool overwrite = true);

    /**
     * 获取应用程序的当前工作目录。
     *
     * @author daixian
     * @date 2020/10/15
     *
     * @returns 应用程序的当前工作目录。
     */
    static std::string CurrentDirectory();

    /**
     * 返回指定目录中文件的名称(包括其路径).
     * (只有当前一级目录).
     *
     * @author daixian
     * @date 2020/9/26
     *
     * @param  path 要搜索的目录的相对或绝对路径,此字符串不区分大小写.
     *
     * @returns 这些文件的完整路径.
     */
    static std::vector<std::string> GetFiles(const std::string& path);

    /**
     * 返回指定目录中与指定的搜索模式匹配的文件的名称（包含其路径），使用某个值确定是否要搜索子目录。
     * (这个函数的通配符可能实现不了,目前使用的是正则表达式,所有文件的表达式就是".*")
     * 如果是错误的正则表达式,那么会抛出正则表达式无法解析的异常.
     *
     * @author daixian
     * @date 2020/9/26
     *
     * @param  path          要搜索的目录的相对或绝对路径，此字符串不区分大小写。
     * @param  searchPattern 要与path中的文件名匹配的搜索字符串(我这里是使用正则表达式Search)。注意这里在c#中此参数可以包含有效文本路径和通配符（* 和 ?）的组合，但不支持正则表达式.
     * @param  searchOption  The search option.
     *
     * @returns 这些文件的完整路径.
     */
    static std::vector<std::string> GetFiles(const std::string& path, const std::string& searchPattern, SearchOption searchOption);

    /**
     * 返回指定目录中文件夹的名称(包括其路径).
     * (只有当前一级目录).
     *
     * @author daixian
     * @date 2020/10/15
     *
     * @param  path 要搜索的目录的相对或绝对路径,此字符串不区分大小写.
     *
     * @returns The directories.
     */
    static std::vector<std::string> GetDirectories(const std::string& path);

    /**
     * 返回与在指定目录中的指定搜索模式匹配的子目录的名称（包括其路径），还可以选择地搜索子目录。
     * (这个函数的通配符可能实现不了,目前使用的是正则表达式,所有文件的表达式就是".*")
     * 如果是错误的正则表达式,那么会抛出正则表达式无法解析的异常.
     *
     * @author daixian
     * @date 2020/9/26
     *
     * @param  path          要搜索的目录的相对或绝对路径，此字符串不区分大小写。
     * @param  searchPattern 要与path中的文件名匹配的搜索字符串(我这里是使用正则表达式Search)。注意这里在c#中此参数可以包含有效文本路径和通配符（* 和 ?）的组合，但不支持正则表达式.
     * @param  searchOption  The search option.
     *
     * @returns 这些文件的完整路径.
     */
    static std::vector<std::string> GetDirectories(const std::string& path, const std::string& searchPattern, SearchOption searchOption);
};

} // namespace csharp
} // namespace xuexue
