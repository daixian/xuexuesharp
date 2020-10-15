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
     * dx:要注意的是在windows下wchar_t是16位,而linux系统是32位.
     * 因此在linux下将一个utf16编码存在wchar_t数组中时,高位有很多补0.
     *
     * @author daixian
     * @date 2020/4/23
     *
     * @param  utf16 utf16的字符串,存在一个wstring中.
     *
     * @returns utf8的字符串.
     */
    static std::string UTF16ToUTF8(const std::wstring& utf16);

    /**
     * utf8编码的字符串转到utf16.
     * 
     * dx:要注意的是在windows下wchar_t是16位,而linux系统是32位.
     * 因此在linux下将一个utf16编码存在wchar_t数组中时,高位有很多补0.
     *
     * @author daixian
     * @date 2020/4/23
     *
     * @param  utf8 utf8的字符串.
     *
     * @returns utf16的wstring字符串.
     */
    static std::wstring UTF8ToUTF16(const std::string& utf8);

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
    static std::string UTF8ToGBK(const std::string& utf8);

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
    static std::string GBKToUTF8(const std::string& gbk);
};

} // namespace csharp
} // namespace xuexue