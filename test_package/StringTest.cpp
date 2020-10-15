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