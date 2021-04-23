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
    enum class Base64Options
    {
        //使用PEM / MIME / UTF-7字母，即（按顺序）AZ，az，0-9以及字符“ +”和“ /”。
        //这就是通常在各处看到的“标准base64”，需要填充（'='），但没有换行符。空格和其他非字母符号被视为解析错误。
        RFC4648,

        // 与base64_rfc4648（相同的RFC中定义）相同，但使用“-”（减号）和“ _”（下划线）作为特殊字符，
        // 而不是“ +”和“ /”。可以安全地用于URL和文件名。
        URL
    };

    /**
     * 转换字节数组到Base64编码的等效字符串表示形式。 参数指定作为输入数组中偏移量的子集、数组中要转换的元素数以及是否在返回值中插入分行符。
     *
     * @author daixian
     * @date 2020/9/26
     *
     * @param  inArray 字节数组.
     * @param  offset  起点.
     * @param  length  长度.
     * @param  option  (Optional)Base64的编码方法.
     *
     * @returns base64编码的文本.
     */
    static std::string ToBase64String(const void* inArray, int offset, int length, Base64Options option = Base64Options::RFC4648);

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
    static std::string ToBase32String(const void* inArray, int offset, int length);

    /**
     * 转换字节数组到一个十六进制的字符串(小写).
     *
     * @author daixian
     * @date 2021/4/23
     *
     * @param  inArray 字节数组.
     * @param  offset  起点.
     * @param  length  长度.
     *
     * @returns 十六进制的字符串.
     */
    static std::string ToHexString(const void* inArray, int offset, int length);

    /**
     * base64的编码转成字节
     *
     * @author daixian
     * @date 2020/9/26
     *
     * @param  s      base64编码的字符串.
     * @param  option (Optional)Base64的编码方法.
     *
     * @returns 解码的数据.
     */
    static std::vector<unsigned char> FromBase64String(const std::string& s, Base64Options option = Base64Options::RFC4648);

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
    static std::vector<unsigned char> FromBase32String(const std::string& s);

    /**
     * 16进制编码的文本转成字节
     *
     * @author daixian
     * @date 2021/4/23
     *
     * @param  s 16进制编码的文本.
     *
     * @returns 解码的数据.
     */
    static std::vector<unsigned char> FromHexString(const std::string& s);
};

} // namespace csharp
} // namespace xuexue
