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
     * 得到模块目录(dll或者exe所在的文件夹).末尾不带斜杠"D:\\Work\\F3DSys\\F3DSystem".
     * 这是dx自己加的函数，这个函数基本上是一个windows下才有意义的概念.
     *
     * @author daixian
     * @date 2020/10/18
     *
     * @returns The module dir.
     */
    static std::string ModuleDir();

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
};

} // namespace csharp
} // namespace xuexue
