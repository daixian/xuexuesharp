#pragma once
#include <vector>
#include <string>

#include "DirectoryInfo.h"

namespace xuexue {
namespace csharp {

class Directory
{
  public:
    enum SearchOption
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
     * 在指定路径中创建所有目录和子目录，除非它们已经存在。
     *
     * @author daixian
     * @date 2020/9/26
     *
     * @param  path 要创建的目录。.
     *
     * @returns 一个表示在指定路径的目录的对象。 无论指定路径的目录是否已经存在，都将返回此对象。.
     */
    static DirectoryInfo createDirectory(const std::string& path);

    /**
     * 删除文件夹
     *
     * @author daixian
     * @date 2020/10/15
     *
     * @param  path      Full pathname of the file.
     * @param  recursive True to process recursively, false to process locally only.
     */
    static void Delete(const std::string& path, bool recursive);

    /**
     * 文件夹是否存在
     *
     * @author daixian
     * @date 2020/10/15
     *
     * @param  path Full pathname of the file.
     *
     * @returns True if it succeeds, false if it fails.
     */
    static bool Exists(const std::string& path);

    /**
     * 返回指定目录中文件的名称（包括其路径）。
     *
     * @author daixian
     * @date 2020/9/26
     *
     * @param  path 要搜索的目录的相对或绝对路径。 此字符串不区分大小写。.
     *
     * @returns The files.
     */
    static std::vector<std::string> GetFiles(const std::string& path);

    /**
     * 返回指定目录中与指定的搜索模式匹配的文件的名称（包含其路径），使用某个值确定是否要搜索子目录。
     * （这个函数的通配符可能实现不了）
     *
     * @author daixian
     * @date 2020/9/26
     *
     * @param  path          要搜索的目录的相对或绝对路径，此字符串不区分大小写。
     * @param  searchPattern 要与path中的文件名匹配的搜索字符串。此参数可以包含有效文本路径和通配符（* 和 ?）的组合，但不支持正则表达式.
     * @param  searchOption  The search option.
     *
     * @returns The files.
     */
    static std::vector<std::string> GetFiles(const std::string& path, const std::string& searchPattern, SearchOption searchOption);
};

} // namespace csharp
} // namespace xuexue