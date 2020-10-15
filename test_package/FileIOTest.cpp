#include "gtest/gtest.h"

#include "xuexue/csharp/Directory.h"
#include "xuexue/csharp/File.h"

#pragma execution_character_set("utf-8")

using namespace std;
using namespace xuexue::csharp;

TEST(FileIO, CreateDelete)
{
    Directory::createDirectory("./fileioTest/1/1/1");
    Directory::createDirectory("./fileioTest/1/2");
    Directory::createDirectory("./fileioTest/2/1/1");
    Directory::createDirectory("./fileioTest/2/1/2");
    Directory::createDirectory("./fileioTest/2/2/1");

    string text = "111\r\n222\r\n333\n";
    File::WriteAllText("./fileioTest/FileTest.txt", text);
    File::WriteAllText("./fileioTest/1/FileTest.txt", text);
    File::WriteAllText("./fileioTest/1/1/FileTest.txt", text);
    File::WriteAllText("./fileioTest/2/FileTest.txt", text);

    ASSERT_TRUE(File::Exists("./fileioTest/FileTest.txt"));
    ASSERT_TRUE(File::Exists("./fileioTest/1/FileTest.txt"));
    ASSERT_TRUE(File::Exists("./fileioTest/1/1/FileTest.txt"));

    File::Delete("./fileioTest/FileTest.txt");
    ASSERT_FALSE(File::Exists("./fileioTest/FileTest.txt"));

    Directory::Delete("./fileioTest");
    ASSERT_FALSE(Directory::Exists("./fileioTest"));
}