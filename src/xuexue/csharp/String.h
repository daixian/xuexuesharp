#pragma once
#include <string>

namespace xuexue {
namespace csharp {

/**
 * 这些是dx自己定的一些方法,不对应C#.
 *
 * @author daixian
 * @date 2020/9/25
 */
class String
{
  public:
    /**
     * wstring转到utf8编码的字符串.
     *
     * @author daixian
     * @date 2017/7/18
     *
     * @param  ws utf16的字符串.
     *
     * @returns utf8的字符串.
     */
    static std::string ToUTF8(const std::wstring& ws);

    /**
     * utf8编码的字符串转到utf16.
     *
     * @author daixian
     * @date 2017/7/18
     *
     * @param  s utf8的字符串
     *
     * @returns utf16的宽字符串.
     */
    static std::wstring UTF8ToWStr(const std::string& s);

    /**
     * utf8转到gbk,注意这个转换不一定能完整转换特殊字符的.
     *
     * @author daixian
     * @date 2020/4/23
     *
     * @param  s_utf8 utf8编码的字符串.
     *
     * @returns gbk编码的字符串.
     */
    static std::string UTF8ToGBK(const std::string& s_utf8);

    /**
     * gbk转到utf8.
     *
     * @author daixian
     * @date 2020/4/23
     *
     * @param  s_gbk gbk编码的字符串.
     *
     * @returns utf8编码的字符串.
     */
    static std::string GBKToUTF8(const std::string& s_gbk);
};

} // namespace csharp
} // namespace xuexue