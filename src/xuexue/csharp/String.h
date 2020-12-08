#pragma once

#include <vector>
#include <string>
#include <string.h>
#include <exception>

namespace xuexue {
namespace csharp {

/**
 * 包含了某些dx自己定的一些方法,不对应C#.
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

    /**
     * 是否包含这个字符。
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str   The string.
     * @param  value The value.
     *
     * @returns True if the object is in this collection, false if not.
     */
    inline static bool Contains(const std::vector<char>& value, char ch)
    {
        for (size_t i = 0; i < value.size(); i++) {
            if (value[i] == ch) {
                return true;
            }
        }
        return false;
    }

    /**
     * 是否包含这个字符。
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str   The string.
     * @param  value The value.
     *
     * @returns True if the object is in this collection, false if not.
     */
    inline static bool Contains(const std::vector<wchar_t>& value, wchar_t ch)
    {
        for (size_t i = 0; i < value.size(); i++) {
            if (value[i] == ch) {
                return true;
            }
        }
        return false;
    }

    /**
     * str中是否包含value这个字符串.
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str   The string.
     * @param  value The value.
     *
     * @returns True if the object is in this collection, false if not.
     */
    inline static bool Contains(const std::string& str, const std::string& value)
    {
        if (value.empty() || str.empty()) {
            return false;
        }
        if (str.size() < value.size()) { //如果字符串比value更短那么肯定包含不了
            return false;
        }
        for (size_t i = 0; i <= str.size() - value.size(); i++) {
            for (size_t j = 0; j < value.size(); j++) {
                if (str[i + j] != value[j]) {
                    break;
                }
                return true;
            }
        }
        return false;
    }

    /**
     * str中是否包含value这个字符串.
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str   The string.
     * @param  value The value.
     *
     * @returns True if the object is in this collection, false if not.
     */
    inline static bool Contains(const std::wstring& str, const std::wstring& value)
    {
        if (value.empty() || str.empty()) {
            return false;
        }
        if (str.size() < value.size()) { //如果字符串比value更短那么肯定包含不了
            return false;
        }
        for (size_t i = 0; i <= str.size() - value.size(); i++) {
            for (size_t j = 0; j < value.size(); j++) {
                if (str[i + j] != value[j]) {
                    break;
                }
                return true;
            }
        }
        return false;
    }

    /**
     * 报告在此实例中首次出现的指定字符串的从零开始的索引。搜索从指定的字符位置开始。
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str        The string.
     * @param  value      The value.
     * @param  startIndex (Optional) The start index.
     *
     * @returns 从零开始value的当前实例的索引位置（如果找到该字符串），否则为-1。如果value为空，则返回值为startIndex.
     */
    inline static int IndexOf(const std::string& str, char value, size_t startIndex = 0)
    {
        if (str.empty()) {
            return static_cast<int>(startIndex);
        }
        for (size_t i = startIndex; i < str.size(); i++) {
            if (str[i] == value) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }

    /**
     * 报告在此实例中首次出现的指定字符串的从零开始的索引。搜索从指定的字符位置开始。
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str        The string.
     * @param  value      The value.
     * @param  startIndex (Optional) The start index.
     *
     * @returns 从零开始value的当前实例的索引位置（如果找到该字符串），否则为-1。如果value为空，则返回值为startIndex.
     */
    inline static int IndexOf(const std::wstring& str, wchar_t value, size_t startIndex = 0)
    {
        if (str.empty()) {
            return static_cast<int>(startIndex);
        }
        for (size_t i = startIndex; i < str.size(); i++) {
            if (str[i] == value) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }

    /**
     * 报告指定实例的字符数组中任何字符在此实例中首次出现的索引。如果在此实例中找不到数组中的字符，则该方法返回-1。
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str        The string.
     * @param  value      The value.
     * @param  startIndex (Optional) The start index.
     *
     * @returns The zero-based index of the found any, or -1 if no match was found.
     */
    inline static int IndexOfAny(const std::string& str, const std::vector<char>& value, size_t startIndex = 0)
    {
        if (str.empty()) {
            return static_cast<int>(startIndex);
        }
        for (size_t i = startIndex; i < str.size(); i++) {
            for (size_t j = 0; j < value.size(); j++) {
                if (str[i] == value[j]) {
                    return static_cast<int>(i);
                }
            }
        }
        return -1;
    }

    /**
     * 报告指定实例的字符数组中任何字符在此实例中首次出现的索引。如果在此实例中找不到数组中的字符，则该方法返回-1。
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str        The string.
     * @param  value      The value.
     * @param  startIndex (Optional) The start index.
     *
     * @returns The zero-based index of the found any, or -1 if no match was found.
     */
    inline static int IndexOfAny(const std::wstring& str, const std::vector<wchar_t>& value, size_t startIndex = 0)
    {
        if (str.empty()) {
            return static_cast<int>(startIndex);
        }
        for (size_t i = startIndex; i < str.size(); i++) {
            for (size_t j = 0; j < value.size(); j++) {
                if (str[i] == value[j]) {
                    return static_cast<int>(i);
                }
            }
        }
        return -1;
    }

    /**
     * 报告此实例中最后一次出现的指定字符的从零开始的索引位置。搜索从指定的字符位置开始，并朝字符串的开头向后进行指定数量的字符位置。
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str        The string.
     * @param  value      The value.
     * @param  startIndex (Optional) The start index.
     *
     * @returns An int.
     */
    inline static int LastIndexOf(const std::string& str, char value, size_t startIndex = 0)
    {
        if (str.empty()) {
            return static_cast<int>(startIndex);
        }
        for (size_t i = str.size() - 1; i >= startIndex; i--) {
            if (str[i] == value) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }

    /**
     * Searches for the last match
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str        The string.
     * @param  value      The value.
     * @param  startIndex (Optional) The start index.
     *
     * @returns An int.
     */
    inline static int LastIndexOf(const std::wstring& str, wchar_t value, size_t startIndex = 0)
    {
        if (str.empty()) {
            return static_cast<int>(startIndex);
        }
        for (size_t i = str.size() - 1; i >= startIndex; i--) {
            if (str[i] == value) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }

    /**
     * 报告此实例中最后一次出现的任意指定字符的从零开始的索引位置。搜索从指定的字符位置开始，并朝字符串的开头向后进行指定数量的字符位置。
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str        The string.
     * @param  value      The value.
     * @param  startIndex (Optional) The start index.
     *
     * @returns The zero-based index of the found any, or -1 if no match was found.
     */
    inline static int LastIndexOfAny(const std::string& str, const std::vector<char>& value, size_t startIndex = 0)
    {
        if (str.empty()) {
            return static_cast<int>(startIndex);
        }
        for (size_t i = str.size() - 1; i >= startIndex; i--) {
            for (size_t j = 0; j < value.size(); j++) {
                if (str[i] == value[j]) {
                    return static_cast<int>(i);
                }
            }
        }
        return -1;
    }

    /**
     * 报告此实例中最后一次出现的任意指定字符的从零开始的索引位置。搜索从指定的字符位置开始，并朝字符串的开头向后进行指定数量的字符位置。
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str        The string.
     * @param  value      The value.
     * @param  startIndex (Optional) The start index.
     *
     * @returns The zero-based index of the found any, or -1 if no match was found.
     */
    inline static int LastIndexOfAny(const std::wstring& str, const std::vector<wchar_t>& value, size_t startIndex = 0)
    {
        if (str.empty()) {
            return static_cast<int>(startIndex);
        }
        for (size_t i = str.size() - 1; i >= startIndex; i--) {
            for (size_t j = 0; j < value.size(); j++) {
                if (str[i] == value[j]) {
                    return static_cast<int>(i);
                }
            }
        }
        return -1;
    }

    /**
     * 确定此字符串实例的开头是否与指定的字符串匹配。
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str   The string.
     * @param  value The value.
     *
     * @returns True if it succeeds, false if it fails.
     */
    static bool StartsWith(const std::string& str, const std::string& value);

    /**
     * 确定此字符串实例的开头是否与指定的字符串匹配。
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str   The string.
     * @param  value The value.
     *
     * @returns True if it succeeds, false if it fails.
     */
    static bool StartsWith(const std::wstring& str, const std::wstring& value);

    /**
     * 从此实例检索子字符串。子字符串从指定的字符位置开始，一直到字符串的末尾。
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str        The string.
     * @param  startIndex The start index.
     *
     * @returns 子字符串.
     */
    static std::string Substring(const std::string& str, int startIndex);

    /**
     * 从此实例检索子字符串。子字符串从指定的字符位置开始，一直到字符串的末尾。
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str        The string.
     * @param  startIndex The start index.
     *
     * @returns 子字符串.
     */
    static std::wstring Substring(const std::wstring& str, int startIndex);

    /**
     * 从此实例检索子字符串。子字符串从指定的字符位置开始，并具有指定的长度。
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str        The string.
     * @param  startIndex The start index.
     * @param  length     The length.
     *
     * @returns 子字符串.
     */
    static std::string Substring(const std::string& str, int startIndex, int length);

    /**
     * 从此实例检索子字符串。子字符串从指定的字符位置开始，并具有指定的长度。
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str        The string.
     * @param  startIndex The start index.
     * @param  length     The length.
     *
     * @returns 子字符串.
     */
    static std::wstring Substring(const std::wstring& str, int startIndex, int length);

    /**
     * 转成小写.
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str The string.
     *
     * @returns 结果字符串.
     */
    static std::string ToLower(const std::string& str);

    /**
     * 转成小写.
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str The string.
     *
     * @returns 结果字符串.
     */
    static std::wstring ToLower(const std::wstring& str);

    /**
     * 转成大写.
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str The string.
     *
     * @returns 结果字符串.
     */
    static std::string ToUpper(const std::string& str);

    /**
     * 转成大写.
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str The string.
     *
     * @returns 结果字符串.
     */
    static std::wstring ToUpper(const std::wstring& str);

    /**
    * Removes all leading and trailing white-space characters from the current string.
    * 从当前字符串中删除数组中白空格字符的所有前导和尾随出现。
    *
    * @author daixian
    * @date 2020/12/8
    *
    * @param  str The string.
    *
    * @returns 结果字符串.
    */
    static std::string Trim(const std::string& str);

    /**
    * Removes all leading and trailing white-space characters from the current string.
    * 从当前字符串中删除数组中白空格字符的所有前导和尾随出现。
    *
    * @author daixian
    * @date 2020/12/8
    *
    * @param  str The string.
    *
    * @returns 结果字符串.
    */
    static std::wstring Trim(const std::wstring& str);

    /**
     * Removes all leading and trailing occurrences of a set of characters specified in an array
     * from the current string. 从当前字符串中删除数组中指定的一组字符的所有前导和尾随出现。
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str       The string.
     * @param  trimChars The trim characters.
     *
     * @returns 结果字符串.
     */
    inline static std::string Trim(const std::string& str, const std::vector<char>& trimChars)
    {
        int first = 0;
        int last = int(str.size()) - 1;

        while (first <= last && String::Contains(trimChars, str[first]))
            ++first;
        while (last >= first && String::Contains(trimChars, str[last]))
            --last;

        int len = last - first + 1;
        return std::string(str, first, len);
    }

    /**
     * Removes all leading and trailing occurrences of a set of characters specified in an array
     * from the current string. 从当前字符串中删除数组中指定的一组字符的所有前导和尾随出现。
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str       The string.
     * @param  trimChars The trim characters.
     *
     * @returns 结果字符串.
     */
    inline static std::wstring Trim(const std::wstring& str, const std::vector<wchar_t>& trimChars)
    {
        int first = 0;
        int last = int(str.size()) - 1;

        while (first <= last && String::Contains(trimChars, str[first]))
            ++first;
        while (last >= first && String::Contains(trimChars, str[last]))
            --last;

        int len = last - first + 1;
        return std::wstring(str, first, len);
    }

    /**
     * Removes all the trailing occurrences of a set of characters specified in an array from the
     * current string.
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str       The string.
     * @param  trimChars The trim characters.
     *
     * @returns 结果字符串.
     */
    inline static std::string TrimEnd(const std::string& str, const std::vector<char>& trimChars)
    {
        int first = 0;
        int last = int(str.size()) - 1;

        while (last >= first && String::Contains(trimChars, str[last]))
            --last;

        int len = last - first + 1;
        return std::string(str, first, len);
    }

    /**
     * Removes all the trailing occurrences of a set of characters specified in an array from the
     * current string.
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str       The string.
     * @param  trimChars The trim characters.
     *
     * @returns 结果字符串.
     */
    inline static std::wstring TrimEnd(const std::wstring& str, const std::vector<wchar_t>& trimChars)
    {
        int first = 0;
        int last = int(str.size()) - 1;

        while (last >= first && String::Contains(trimChars, str[last]))
            --last;

        int len = last - first + 1;
        return std::wstring(str, first, len);
    }

    /**
     * Removes all the leading occurrences of a set of characters specified in an array from the
     * current string.
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str       The string.
     * @param  trimChars The trim characters.
     *
     * @returns 结果字符串.
     */
    inline static std::string TrimStart(const std::string& str, const std::vector<char>& trimChars)
    {
        int first = 0;
        int last = int(str.size()) - 1;

        while (first <= last && String::Contains(trimChars, str[first]))
            ++first;

        int len = last - first + 1;
        return std::string(str, first, len);
    }

    /**
     * Removes all the leading occurrences of a set of characters specified in an array from the
     * current string.
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str       The string.
     * @param  trimChars The trim characters.
     *
     * @returns 结果字符串.
     */
    inline static std::wstring TrimStart(const std::wstring& str, const std::vector<wchar_t>& trimChars)
    {
        int first = 0;
        int last = int(str.size()) - 1;

        while (first <= last && String::Contains(trimChars, str[first]))
            ++first;

        int len = last - first + 1;
        return std::wstring(str, first, len);
    }

    /**
     * 分离字符串,默认带有参数Poco::StringTokenizer::TOK_TRIM | Poco::StringTokenizer::TOK_IGNORE_EMPTY.
     *
     * @author daixian
     * @date 2020/12/8
     *
     * @param  str       The string.
     * @param  separator 分隔符参数.
     * @param  opt       (Optional) 默认参数是 TOK_TRIM|TOK_IGNORE_EMPTY.
     *
     * @returns 拆分的结果.
     */
    static std::vector<std::string> Split(const std::string& str, std::vector<char> separator, int opt = 1 | 2);

    /**
     * 返回一个新字符串，其中此实例中出现的所有指定字符都替换为另一个指定的字符。
     *
     * @author daixian
     * @date 2020/12/9
     *
     * @param  str        The string.
     * @param  oldChar    The old character.
     * @param  newChar    The new character.
     * @param  startIndex (Optional) The start index.
     *
     * @returns A std::string.
     */
    static std::string Replace(const std::string& str, char oldChar, char newChar, size_t startIndex = 0);

    /**
     * 返回一个新字符串，其中此实例中出现的所有指定字符都替换为另一个指定的字符。
     *
     * @author daixian
     * @date 2020/12/9
     *
     * @param  str        The string.
     * @param  oldChar    The old character.
     * @param  newChar    The new character.
     * @param  startIndex (Optional) The start index.
     *
     * @returns A std::string.
     */
    static std::wstring Replace(const std::wstring& str, wchar_t oldChar, wchar_t newChar, size_t startIndex = 0);

    /**
     * 返回一个新字符串，其中当前实例中出现的所有指定字符串都替换为另一个指定的字符串。
     *
     * @author daixian
     * @date 2020/12/9
     *
     * @param  str        The string.
     * @param  oldValue   The old value.
     * @param  newValue   如果newValue为空字符串,则删除的所有匹配项oldValue 。.
     * @param  startIndex (Optional) The start index.
     *
     * @returns A std::string.
     */
    static std::string Replace(const std::string& str, const std::string& oldValue, const std::string& newValue, size_t startIndex = 0);

    /**
     * 返回一个新字符串，其中当前实例中出现的所有指定字符串都替换为另一个指定的字符串。
     *
     * @author daixian
     * @date 2020/12/9
     *
     * @param  str        The string.
     * @param  oldValue   The old value.
     * @param  newValue   如果newValue为空字符串,则删除的所有匹配项oldValue 。.
     * @param  startIndex (Optional) The start index.
     *
     * @returns A std::string.
     */
    static std::wstring Replace(const std::wstring& str, const std::wstring& oldValue, const std::wstring& newValue, size_t startIndex = 0);
};

} // namespace csharp
} // namespace xuexue
