#include "gtest/gtest.h"

#include "xuexue/csharp/String.h"

#pragma execution_character_set("utf-8")

using namespace std;
using namespace xuexue::csharp;

TEST(String, ToUTF8_UTF8ToWStr)
{
    wstring ws = L"en中文和❀❀❀❀!";
    string s = String::UTF16ToUTF8(ws);
    wstring ws2 = String::UTF8ToUTF16(s);
    ASSERT_TRUE(ws == ws2);
}

TEST(String, GBKToUTF8)
{
    //测试GBK不能带有❀这样的特殊符号,因为转换不了
    wstring ws = L"en中文和!2131312123";
    string utf8 = String::UTF16ToUTF8(ws);
    wstring ws2 = String::UTF8ToUTF16(utf8);
    ASSERT_TRUE(ws == ws2);

    string gbk = String::UTF8ToGBK(utf8);
    string utf8_2 = String::GBKToUTF8(gbk);
    ASSERT_TRUE(utf8 == utf8_2);
    ws2 = String::UTF8ToUTF16(utf8_2);
    ASSERT_TRUE(ws == ws2);
}

TEST(String, SubString)
{
    ASSERT_EQ(String::Substring("123456", 2), "3456");
    ASSERT_EQ(String::Substring(L"123456", 2), L"3456");
}

TEST(String, SubString2)
{
    ASSERT_EQ(String::Substring("123456", 2, 1), "3");
    ASSERT_EQ(String::Substring(L"123456", 2, 1), L"3");
}

TEST(String, IndexOf)
{
    ASSERT_EQ(String::IndexOf("123456", '2'), 1);
    ASSERT_EQ(String::IndexOf("123456", '3'), 2);
}

TEST(String, IndexOfAny)
{
    ASSERT_EQ(String::IndexOfAny("123456", {'2', '3'}), 1);
    ASSERT_EQ(String::IndexOfAny("123456", {'3'}), 2);
}

TEST(String, LastIndexOf)
{
    ASSERT_EQ(String::LastIndexOf("123456", '2'), 1);
    ASSERT_EQ(String::LastIndexOf("123456", '3'), 2);
}

TEST(String, LastIndexOfAny)
{
    ASSERT_EQ(String::LastIndexOfAny("123456", {'2', '3'}), 2);
    ASSERT_EQ(String::LastIndexOfAny("123456", {'3'}), 2);
}

TEST(String, Trim)
{
    ASSERT_EQ(String::Trim("/123456\\", {'/', '\\'}), "123456");
}

TEST(String, TrimEnd)
{
    ASSERT_EQ(String::TrimEnd("/123456\\/", {'/', '\\'}), "/123456");
}

TEST(String, TrimStart)
{
    ASSERT_EQ(String::TrimStart("/123456\\", {'/', '\\'}), "123456\\");
}

TEST(String, ContainsStrTrue)
{
    ASSERT_EQ(String::Contains("/123456\\", "/123456\\"), true);
    ASSERT_EQ(String::Contains("/123456\\", "/123"), true);
    ASSERT_EQ(String::Contains("/123456\\", "23"), true);
    ASSERT_EQ(String::Contains("/123456\\", "6\\"), true);
}

TEST(String, ContainsStrFalse)
{
    ASSERT_EQ(String::Contains("/123456\\", "/123456\\312"), false);
    ASSERT_EQ(String::Contains("/123456\\", "\\123"), false);
    ASSERT_EQ(String::Contains("/123456\\", "\\23"), false);
    ASSERT_EQ(String::Contains("/123456\\", ""), false);
}

TEST(String, Split)
{
    auto res = String::Split("/123456\\312321/321", {'\\', '/'});
    ASSERT_EQ(res.size(), 3);
}

TEST(String, Replace)
{
    ASSERT_EQ(String::Replace("/123456\\312321/321", '\\', '/'), "/123456/312321/321");
    ASSERT_EQ(String::Replace("/123456\\312321/321", "123456", ""), "/\\312321/321");
}

TEST(String, Replace2)
{
    ASSERT_EQ(String::Replace(L"/123456\\312321/321", L'\\', L'/'), L"/123456/312321/321");
    ASSERT_EQ(String::Replace(L"/123456\\312321/321", L"123456", L""), L"/\\312321/321");
}
