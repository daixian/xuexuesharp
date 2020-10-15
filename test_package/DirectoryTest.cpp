#include "gtest/gtest.h"

#include "xuexue/csharp/Directory.h"

#pragma execution_character_set("utf-8")

using namespace std;
using namespace xuexue::csharp;

TEST(Directory, createDirectory_self)
{
    string path = "./";
    Directory::createDirectory(path);
    ASSERT_TRUE(Directory::Exists(path));
}

TEST(Directory, createDirectory_self2)
{
    string path = ".";
    Directory::createDirectory(path);
    ASSERT_TRUE(Directory::Exists(path));
}

TEST(Directory, createDirectory_Del)
{
    //创建然后删除
    string path = "./createDirectoryTest/123";
    Directory::createDirectory(path);
    ASSERT_TRUE(Directory::Exists(path));
    ASSERT_TRUE(Directory::Exists("./createDirectoryTest"));
    ASSERT_TRUE(Directory::Exists("./createDirectoryTest/"));
    Directory::Delete("./createDirectoryTest", true);
    ASSERT_FALSE(Directory::Exists("./createDirectoryTest"));
    ASSERT_FALSE(Directory::Exists("./createDirectoryTest/"));
    ASSERT_FALSE(Directory::Exists(path));
}

TEST(Directory, createDirectory_Del2)
{
    //创建然后删除
    string path = "./createDirectoryTest/123/";
    Directory::createDirectory(path);
    ASSERT_TRUE(Directory::Exists(path));
    ASSERT_TRUE(Directory::Exists("./createDirectoryTest"));
    ASSERT_TRUE(Directory::Exists("./createDirectoryTest/"));
    Directory::Delete("./createDirectoryTest", true);
    ASSERT_FALSE(Directory::Exists("./createDirectoryTest"));
    ASSERT_FALSE(Directory::Exists("./createDirectoryTest/"));
    ASSERT_FALSE(Directory::Exists(path));
}

TEST(Directory, Exists_self)
{
    ASSERT_TRUE(Directory::Exists("./"));
}

TEST(Directory, Exists_self2)
{
    ASSERT_TRUE(Directory::Exists("."));
}

TEST(Directory, Exists3)
{
    ASSERT_FALSE(Directory::Exists("./dajkfhjk"));
}

TEST(Directory, GetFiles_self)
{
    //这两种写法都能工作
    auto files = Directory::GetFiles("./");
    auto files2 = Directory::GetFiles(".");

    ASSERT_TRUE(files.size() > 0);
    ASSERT_EQ(files.size(), files2.size());
}

TEST(Directory, GetDirectories_self)
{
    //这两种写法都能工作
    auto files = Directory::GetDirectories("./");
    auto files2 = Directory::GetDirectories(".");

    ASSERT_TRUE(files.size() >= 0);
    ASSERT_EQ(files.size(), files2.size());
}