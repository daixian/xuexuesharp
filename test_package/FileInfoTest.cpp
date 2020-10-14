#include "gtest/gtest.h"

#include "xuexue/csharp/FileInfo.h"

#pragma execution_character_set("utf-8")

using namespace std;
using namespace xuexue::csharp;

TEST(FileInfo, Exists)
{
    FileInfo fi("./test/666.txt");
    ASSERT_TRUE(!fi.Exists());
}

TEST(FileInfo, BaseName)
{
    FileInfo fi("./test/666.txt");
    ASSERT_TRUE(fi.BaseName() == "666");
}

TEST(FileInfo, Extension)
{
    FileInfo fi("./test/666.txt");
    ASSERT_EQ(fi.Extension(), "txt");
}

TEST(FileInfo, Name)
{
    FileInfo fi("./test/666.txt");
    ASSERT_TRUE(fi.Name() == "666.txt");
}

TEST(FileInfo, FullName)
{
    FileInfo fi("./test/666.txt");
    string fn = fi.FullName();
    ASSERT_TRUE(fn.size() > 13);
}

TEST(FileInfo, DirectoryName)
{
#if _WIN32
    FileInfo fi("d:/test/12233234/666.txt");
    //在c#里实际返回中不带最后一个\\,c#的结果是 d:\\test\\12233234
    ASSERT_EQ(fi.DirectoryName(), "d:\\test\\12233234\\");
#else
    FileInfo fi("/test/12233234/666.txt");
    //在c#里实际返回中不带最后一个\\,c#的结果是 d:\\test\\12233234
    ASSERT_EQ(fi.DirectoryName(), "/test/12233234/");
#endif
}
