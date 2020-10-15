#include "String.h"
//利用rapidjson做utf8和utf16的转换
#include "rapidjson/encodings.h"
#include "rapidjson/stringbuffer.h"

#include <Poco/TextConverter.h>
#include <Poco/UTF8Encoding.h>
#include <Poco/Windows936Encoding.h>

typedef rapidjson::GenericStringStream<rapidjson::UTF16<>> StringStreamW;
typedef rapidjson::GenericStringBuffer<rapidjson::UTF16<>> StringBufferW;

namespace xuexue {
namespace csharp {

std::string String::UTF16ToUTF8(const std::wstring& ws)
{
    using namespace rapidjson;
    StringStreamW source(ws.c_str());
    StringBuffer target;
    bool hasError = false;
    while (source.Peek() != L'\0')
        if (!Transcoder<UTF16<>, UTF8<>>::Transcode(source, target)) {
            hasError = true;
            break;
        }
    if (!hasError) {
        return target.GetString();
    }
    return std::string();
}

std::wstring String::UTF8ToUTF16(const std::string& s)
{
    using namespace rapidjson;
    StringStream source(s.c_str());
    StringBufferW target;
    bool hasError = false;
    while (source.Peek() != '\0')
        if (!Transcoder<UTF8<>, UTF16<>>::Transcode(source, target)) {
            hasError = true;
            break;
        }
    if (!hasError) {
        return target.GetString();
    }
    return std::wstring();
}

std::string String::UTF8ToGBK(const std::string& s_utf8)
{
    Poco::Windows936Encoding cp936;
    Poco::UTF8Encoding utf8;
    Poco::TextConverter converter(utf8, cp936);
    std::string dst;
    converter.convert(s_utf8, dst);
    return dst;
}

std::string String::GBKToUTF8(const std::string& s_gbk)
{
    Poco::Windows936Encoding cp936;
    Poco::UTF8Encoding utf8;
    Poco::TextConverter converter(cp936, utf8);
    std::string dst;
    converter.convert(s_gbk, dst);
    return dst;
}

} // namespace csharp
} // namespace xuexue