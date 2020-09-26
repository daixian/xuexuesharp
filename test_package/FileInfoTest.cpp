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
    ASSERT_TRUE(fi.Extension() == "txt");
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
}