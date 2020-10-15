#include "gtest/gtest.h"

#include "xuexue/csharp/DirectoryInfo.h"

#pragma execution_character_set("utf-8")

using namespace std;
using namespace xuexue::csharp;

TEST(DirectoryInfo, Exists)
{
    DirectoryInfo di("./test/666.txt");
    ASSERT_FALSE(di.Exists());
}

TEST(DirectoryInfo, Exists_self)
{
    DirectoryInfo di("./");
    ASSERT_TRUE(di.Exists());
}

TEST(DirectoryInfo, Exists_self2)
{
    DirectoryInfo di(".");
    ASSERT_TRUE(di.Exists());
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
#if _WIN32
    //如果是根目录那么它不会返回文件夹Name
    DirectoryInfo di("D:/");
    ASSERT_EQ(di.Name(), "");
#else
    DirectoryInfo di("/");
    ASSERT_EQ(di.Name(), "");
#endif
}

TEST(DirectoryInfo, FullName)
{
#if _WIN32
    DirectoryInfo di("D:/test/666txt");
    ASSERT_EQ(di.FullName(), "D:\\test\\666txt\\");
#else
    DirectoryInfo di("/test/666txt");
    ASSERT_EQ(di.FullName(), "/test/666txt/");
#endif
}

TEST(DirectoryInfo, FullName2)
{
#if _WIN32
    DirectoryInfo di("D:\\");
    ASSERT_EQ(di.FullName(), "D:\\");
#else
    DirectoryInfo di("/");
    ASSERT_EQ(di.FullName(), "/");
#endif
}

TEST(DirectoryInfo, FullName3)
{
#if _WIN32
    //它在c++会解析错误
    ASSERT_ANY_THROW(DirectoryInfo di("D:"));
#endif
}

TEST(DirectoryInfo, Root)
{
#if _WIN32
    DirectoryInfo di("D:/test/666txt");
    DirectoryInfo root = di.Root();
    ASSERT_EQ(root.FullName(), "D:\\");
#else
    DirectoryInfo di("./test/666txt");
    DirectoryInfo root = di.Root();
    //目前在其他平台这个函数的C#结果是什么不太清楚
    ASSERT_EQ(root.FullName(), "/");
#endif
}

TEST(DirectoryInfo, Parent)
{
#if _WIN32
    DirectoryInfo di("C:/test/123/666txt");
    DirectoryInfo parent = di.Parent();
    ASSERT_EQ(parent.FullName(), "C:\\test\\123\\");
#else
    DirectoryInfo di("/test/123/666txt");
    DirectoryInfo parent = di.Parent();
    ASSERT_EQ(parent.FullName(), "/test/123/");
#endif
}

TEST(DirectoryInfo, GetFiles_self)
{
    DirectoryInfo di("./");
    DirectoryInfo di2(".");
    //这两种写法都能工作
    auto files = di.GetFiles();
    auto files2 = di2.GetFiles();

    ASSERT_TRUE(files.size() > 0);
    ASSERT_EQ(files.size(), files2.size());
}

TEST(DirectoryInfo, GetFiles_noExists)
{
    DirectoryInfo di("./3131212");

    //这两种写法都能工作
    ASSERT_ANY_THROW(di.GetFiles());
}

TEST(DirectoryInfo, GetDirectories_self)
{
    DirectoryInfo di("./");
    DirectoryInfo di2(".");
    //这两种写法都能工作
    auto files = di.GetDirectories();
    auto files2 = di2.GetDirectories();

    ASSERT_TRUE(files.size() >= 0);
    ASSERT_EQ(files.size(), files2.size());
}

TEST(DirectoryInfo, GetDirectories_noExists)
{
    DirectoryInfo di("./3131212");

    //这两种写法都能工作
    ASSERT_ANY_THROW(di.GetDirectories());
}