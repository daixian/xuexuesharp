#include "String.h"
//利用rapidjson做utf8和utf16的转换
#include "rapidjson/encodings.h"
#include "rapidjson/stringbuffer.h"

#include <Poco/TextConverter.h>
#include <Poco/UTF8Encoding.h>
#include <Poco/Windows936Encoding.h>

#include <Poco/String.h>
#include <Poco/StringTokenizer.h>

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

bool String::StartsWith(const std::string& str, const std::string& value)
{
    return Poco::startsWith(str, value);
}
bool String::StartsWith(const std::wstring& str, const std::wstring& value)
{
    return Poco::startsWith(str, value);
}

std::string String::Substring(const std::string& str, int startIndex)
{
    if (startIndex < 0) {
        throw std::invalid_argument("String::Substring():tartIndex < 0 Check fail!");
    }
    std::string sub(str, startIndex);
    return sub;
}
std::wstring String::Substring(const std::wstring& str, int startIndex)
{
    if (startIndex < 0) {
        throw std::invalid_argument("String::Substring():tartIndex < 0 Check fail!");
    }
    std::wstring sub(str, startIndex);
    return sub;
}

std::string String::Substring(const std::string& str, int startIndex, int length)
{
    int endIndex = startIndex + length;
    if (startIndex < 0 || endIndex > str.size()) {
        throw std::invalid_argument("String::Substring():tartIndex < 0 || endIndex >= str.size() Check fail!");
    }
    std::string sub(str, startIndex, length);
    return sub;
}
std::wstring String::Substring(const std::wstring& str, int startIndex, int length)
{
    int endIndex = startIndex + length;
    if (startIndex < 0 || endIndex > str.size()) {
        throw std::invalid_argument("String::Substring():tartIndex < 0 || endIndex >= str.size() Check fail!");
    }
    std::wstring sub(str, startIndex, length);
    return sub;
}

std::string String::ToLower(const std::string& str)
{
    return Poco::toLower(str);
}
std::wstring String::ToLower(const std::wstring& str)
{
    return Poco::toLower(str);
}

std::string String::ToUpper(const std::string& str)
{
    return Poco::toUpper(str);
}
std::wstring String::ToUpper(const std::wstring& str)
{
    return Poco::toUpper(str);
}

std::string String::Trim(const std::string& str)
{
    return Poco::trim(str);
}
std::wstring String::Trim(const std::wstring& str)
{
    return Poco::trim(str);
}

std::vector<std::string> String::Split(const std::string& str, std::vector<char> separator, int opt)
{
    std::string splitsArg; //合并多个分隔符参数
    for (size_t i = 0; i < separator.size(); i++) {
        splitsArg.push_back(separator[i]);
    }

    std::vector<std::string> result;
    // 这里带有两个参数 Poco::StringTokenizer::TOK_TRIM | Poco::StringTokenizer::TOK_IGNORE_EMPTY
    Poco::StringTokenizer st(str, splitsArg, opt);
    for (auto itr = st.begin(); itr != st.end(); itr++) {
        result.push_back(*itr);
    }
    return result;
}

} // namespace csharp
} // namespace xuexue
