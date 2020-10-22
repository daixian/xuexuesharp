#include "gtest/gtest.h"

#include "Poco/Path.h"
#include "Poco/File.h"

#include "xuexue/csharp/csharp.h"

#pragma execution_character_set("utf-8")

TEST(Poco, File_Exists_Remove)
{
    std::string filePath = "./testfile";
    xuexue::csharp::File::WriteAllText(filePath, "随便的一些内容!");
    Poco::File file(filePath);
    if (file.exists()) { //如果文件存在
        ASSERT_FALSE(file.isDirectory());
        ASSERT_TRUE(file.isFile());
        file.remove(true);
    }
    else {
        FAIL();
    }
    ASSERT_FALSE(file.exists());
}

TEST(Poco, Dir_Exists_Remove)
{
    std::string filePath = "./testfile";
    xuexue::csharp::Directory::createDirectory("./testfile");
    Poco::File file(filePath);
    if (file.exists()) { //如果文件夹存在
        ASSERT_TRUE(file.isDirectory());
        ASSERT_FALSE(file.isFile());
        file.remove(true);
    }
    else {
        FAIL();
    }
    ASSERT_FALSE(file.exists());
}
