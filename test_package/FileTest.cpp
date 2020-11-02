#include "gtest/gtest.h"

#include "xuexue/csharp/File.h"

#pragma execution_character_set("utf-8")

using namespace std;
using namespace xuexue::csharp;

TEST(File, Exists)
{
    ASSERT_FALSE(File::Exists("./"));
    ASSERT_FALSE(File::Exists("."));
}

TEST(File, Exists2)
{
    ASSERT_FALSE(File::Exists(":memory:"));
}

TEST(File, Exists3)
{

    ASSERT_FALSE(File::Exists("❀❀❀❀"));
}

TEST(File, WriteAllText)
{
    string text = "111\r\n222\r\n333\n";
    File::WriteAllText("FileTest.txt", text);
    string text2 = File::ReadAllText("FileTest.txt");
    ASSERT_EQ(text, text2);
    File::Delete("FileTest.txt");
}

TEST(File, AppendAllText)
{
    File::Delete("FileTest2.txt");
    string text = "111\r\n222\r\n333\n";
    File::AppendAllText("FileTest2.txt", text);
    string text2 = File::ReadAllText("FileTest2.txt");
    ASSERT_EQ(text, text2);

    File::AppendAllText("FileTest2.txt", text);

    text2 = File::ReadAllText("FileTest2.txt");
    ASSERT_EQ(text.size() * 2, text2.size());

    File::Delete("FileTest2.txt");
}

TEST(File, WriteAllBytes)
{
    vector<char> data;
    for (size_t i = 0; i < 4 * 1024; i++) {
        data.push_back((char)i);
    }
    for (size_t i = 0; i < 4; i++) {
        File::WriteAllBytes("FileTestBytes.txt", data.data(), data.size());

        vector<char> data2 = File::ReadAllBytes("FileTestBytes.txt");
        ASSERT_EQ(data.size(), data2.size());

        for (size_t i = 0; i < data2.size(); i++) {
            ASSERT_EQ(data[i], data2[i]);
        }
    }

    File::Delete("FileTest2.txt");
}
