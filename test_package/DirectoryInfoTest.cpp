#include "gtest/gtest.h"

#include "xuexue/csharp/DirectoryInfo.h"

#pragma execution_character_set("utf-8")

using namespace std;
using namespace xuexue::csharp;

TEST(DirectoryInfo, Exists)
{
    DirectoryInfo di("./test/666.txt");
    ASSERT_TRUE(!di.Exists());
}

TEST(DirectoryInfo, Name)
{
    DirectoryInfo di("./test/666");
    ASSERT_EQ(di.Name(), "666");
}

TEST(DirectoryInfo, Name2)
{
    DirectoryInfo di("./test/666/");
    ASSERT_EQ(di.Name(), "666");
}

TEST(DirectoryInfo, Name_D)
{
    //如果是根目录那么它不会返回文件夹Name
    DirectoryInfo di("D:/");
    ASSERT_EQ(di.Name(), "");
}

TEST(DirectoryInfo, FullName)
{
    DirectoryInfo di("D:/test/666txt");
    ASSERT_EQ(di.FullName(), "D:\\test\\666txt\\");
}

TEST(DirectoryInfo, FullName2)
{
    DirectoryInfo di("D:\\");
    ASSERT_EQ(di.FullName(), "D:\\");
}

TEST(DirectoryInfo, FullName3)
{
    //它在c++会解析错误
    ASSERT_ANY_THROW(DirectoryInfo di("D:"));
}

TEST(DirectoryInfo, Root)
{
    DirectoryInfo di("./test/666txt");
    DirectoryInfo root = di.Root();
    ASSERT_EQ(root.FullName(), "D:\\");
}

TEST(DirectoryInfo, Parent)
{
    DirectoryInfo di("C:/test/123/666txt");
    DirectoryInfo parent = di.Parent();
    ASSERT_EQ(parent.FullName(), "C:\\test\\123\\");
}
