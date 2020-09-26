﻿#include "Convert.h"
#include "../libs/cppcodec/base32_crockford.hpp"
#include "../libs/cppcodec/base64_rfc4648.hpp"
#include "../libs/cppcodec/base64_url.hpp"

namespace xuexue {
namespace csharp {

/*
* 关于cppcodec库 https://github.com/tplgy/cppcodec

base64_rfc4648:
使用PEM / MIME / UTF-7字母，即（按顺序）AZ，az，0-9以及字符“ +”和“ /”。
这就是通常在各处看到的“标准base64”，需要填充（'='），但没有换行符。空格和其他非字母符号被视为解析错误。

base64_url:
与base64_rfc4648（相同的RFC中定义）相同，但使用“-”（减号）和“ _”（下划线）作为特殊字符，而不是“ +”和“ /”。可以安全地用于URL和文件名。
必须使用'='进行填充，编码为字符串时会生成该填充，如果在解码时不存在，则将视为解析错误。

base64_url_unpaddedvariant:
与相同base64_url，但是'='填充字符是可选的。编码时，不会在结果字符串上附加填充。解码接受填充或未填充的字符串。
*/

std::string Convert::ToBase64String(const unsigned char* inArray, int offset, int length, Base64Options option)
{
    //在C#中有Base64FormattingOptions:
    //如果每 76 个字符插入一个分行符，则使用 InsertLineBreaks，如果不插入分行符，则使用 None。
    const unsigned char* ptr = inArray + offset;
    if (option == Base64Options::URL)
        return cppcodec::base64_url::encode<std::string>(ptr, length);
    else
        return cppcodec::base64_rfc4648::encode<std::string>(ptr, length);
}

std::string Convert::ToBase32String(const unsigned char* inArray, int offset, int length)
{
    const unsigned char* ptr = inArray + offset;
    return cppcodec::base32_crockford::encode<std::string>(ptr, length);
}

std::vector<unsigned char> Convert::FromBase64String(std::string s, Base64Options option)
{
    if (option == Base64Options::URL)
        return cppcodec::base64_url::decode<std::vector<unsigned char>>(s);
    else
        return cppcodec::base64_rfc4648::decode<std::vector<unsigned char>>(s);
}

std::vector<unsigned char> Convert::FromBase32String(std::string s)
{
    return cppcodec::base32_crockford::decode<std::vector<unsigned char>>(s);
}

} // namespace csharp
} // namespace xuexue