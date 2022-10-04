#pragma once
#include <vector>
#include <string>

namespace xuexue {
namespace csharp {

class Path
{
  public:
    /**
     * 将两个字符串组合成一个路径.
     * 要注意path2的开头不能有斜杠.否则会认为是绝对路径忽略path1,此时可以使用ToRelative()函数转换path2.
     *
     * @author daixian
     * @date 2020/10/18
     *
     * @param  path1 The first path.
     * @param  path2 The second path.
     *
     * @returns 已组合的路径.
     */
    static std::string Combine(const std::string& path1, const std::string& path2);

    /**
     * 将三个字符串组合成一个路径.
     *
     * @author daixian
     * @date 2020/10/18
     *
     * @param  path1 The first path.
     * @param  path2 The second path.
     * @param  path3 The third path.
     *
     * @returns 已组合的路径.
     */
    static std::string Combine(const std::string& path1, const std::string& path2, const std::string& path3);

    /**
     * 将四个字符串组合成一个路径.
     *
     * @author daixian
     * @date 2020/10/18
     *
     * @param  path1 The first path.
     * @param  path2 The second path.
     * @param  path3 The third path.
     * @param  path4 The fourth path.
     *
     * @returns 已组合的路径.
     */
    static std::string Combine(const std::string& path1, const std::string& path2, const std::string& path3, const std::string& path4);

    /**
     * 将字符串数组组合成一个路径.
     *
     * @author daixian
     * @date 2020/10/18
     *
     * @param  paths The paths.
     *
     * @returns 已组合的路径.
     */
    static std::string Combine(const std::vector<std::string>& paths);

    /**
     * 把一个斜杠开头的绝对路径转成相对路径.
     *
     * @author daixian
     * @date 2020/12/9
     *
     * @param  path 斜杠开头的绝对路径.
     *
     * @returns 相对路径.
     */
    static std::string ToRelative(const std::string& path);

#if defined(_WIN32) || defined(_WIN64)

    /**
     * @brief 得到模块目录(dll或者exe所在的文件夹).末尾不带斜杠"D:\\Work\\F3DSys\\F3DSystem".
     * 这是dx自己加的函数，这个函数基本上是一个windows下才有意义的概念.
     *
     * @param handle 如果是dll那么要传入dll的句柄.
     * @return 返回文件夹路径结果
     */
    static std::string ModuleDir(void* handle = nullptr);
#else
    static std::string ModuleDir();
#endif

    /**
     * GReturns the current working directory.
     *
     * @author daixian
     * @date 2020/10/18
     *
     * @returns A std::string.
     */
    static std::string Current();

    /**
     *  Returns the user's data directory.
     *  On Unix systems, this is the '~/.local/share/'.
     *  On Windows systems, this is '%APPDATA%'.
     *
     * @author daixian
     * @date 2020/10/18
     *
     * @returns A std::string.
     */
    static std::string DataHome();

    /**
     * Returns the user's home directory.
     *
     * @author daixian
     * @date 2020/10/18
     *
     * @returns A std::string.
     */
    static std::string Home();

    /**
     * Returns the temporary directory.
     *
     * @author daixian
     * @date 2020/10/18
     *
     * @returns A std::string.
     */
    static std::string Temp();

    /**
     * 是否是绝对路径.注意/123这样的路径不认为是windows下的绝对路径。
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @returns 是绝对路径返回True.
     */
    static bool IsPathFullyQualified(const std::string& path);

    /**
     * 是否是绝对路径.注意/123这样的路径在windows下也会认为是绝对路径。
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @returns 是绝对路径返回True.
     */
    static bool IsPathRooted(const std::string& path);

    /**
     * 从指定字符串中包含的路径获取根目录信息。
     * GetPathRoot('\mydir\') returns '\'
     * GetPathRoot('myfile.ext') returns ''
     * GetPathRoot('C:\mydir\myfile.ext') returns 'C:\'
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  path 字符串路径.
     *
     * @returns 跟目录.
     */
    static std::string GetPathRoot(const std::string& path);

    /**
     * 返回path所在的目录,和c#的api行为一致.
     *
     *  返回结果示例:
     *  GetDirectoryName('C:\MyDir\MySubDir\myfile.ext') returns 'C:\MyDir\MySubDir'
     *  GetDirectoryName('C:\MyDir\MySubDir') returns 'C:\MyDir'
     *  GetDirectoryName('C:\MyDir\') returns 'C:\MyDir'
     *  GetDirectoryName('C:\MyDir') returns 'C:\'
     *  GetDirectoryName('C:\') returns ''
     *
     * @author daixian
     * @date 2020/12/9
     *
     * @param  path 一个文件或文件夹路径.
     *
     * @returns 所在的目录.
     */
    static std::string GetDirectoryName(const std::string& path);

    /**
     * 返回指定路径字符串的扩展名（包括句点“.”）。
     *
     * @author daixian
     * @date 2020/12/9
     *
     * @param  path Full pathname of the file.
     *
     * @returns The extension.
     */
    static std::string GetExtension(const std::string& path);
};

} // namespace csharp
} // namespace xuexue
