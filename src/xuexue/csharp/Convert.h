#pragma once
#include <vector>
#include <string>

namespace xuexue {
namespace csharp {

/**
 * C++中基本不需要实际转换,只需要变换指针就行了.
 *
 * @author daixian
 * @date 2020/9/26
 */
class Convert
{
  public:
    /**
     * 转换字节数组到Base64编码的等效字符串表示形式。
     * 参数指定作为输入数组中偏移量的子集、数组中要转换的元素数以及是否在返回值中插入分行符。
     * 
     * @author daixian
     * @date 2020/9/26
     *
     * @param  inArray 字节数组.
     * @param  offset  起点.
     * @param  length  长度.
     *
     * @returns base64编码的文本.
     */
    static std::string ToBase64String(const unsigned char* inArray, int offset, int length);

    /**
     * 转换字节数组到Base32编码,使用crockford字符表
     *
     * @author daixian
     * @date 2020/9/26
     *
     * @param  inArray 字节数组.
     * @param  offset  起点.
     * @param  length  长度.
     *
     * @returns base32编码的文本.
     */
    static std::string ToBase32String(const unsigned char* inArray, int offset, int length);

    /**
     * base64的编码转成字节
     *
     * @author daixian
     * @date 2020/9/26
     *
     * @param  s base64编码的字符串.
     *
     * @returns 解码的数据
     */
    static std::vector<unsigned char> FromBase64String(std::string s);

    /**
     * base32的编码(crockford)转成字节
     *
     * @author daixian
     * @date 2020/9/26
     *
     * @param  s 使用crockford字符表的base32字符串.
     *
     * @returns 解码的数据.
     */

    static std::vector<unsigned char> FromBase32String(std::string s);
};

} // namespace csharp
} // namespace xuexue