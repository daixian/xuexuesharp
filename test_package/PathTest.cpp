﻿#include "gtest/gtest.h"

#include "xuexue/csharp/Path.h"

#pragma execution_character_set("utf-8")

using namespace std;
using namespace xuexue::csharp;

TEST(Path, Combine2)
{
    string p = Path::Combine("1", "2");
#if defined(_WIN32) || defined(_WIN64)
    ASSERT_EQ(p, "1\\2");
#else
    ASSERT_EQ(p, "1/2");
#endif
}

TEST(Path, Combine2_2)
{
#if defined(_WIN32) || defined(_WIN64)
    string p = Path::Combine("1", "2\\");
    ASSERT_EQ(p, "1\\2\\");
#else
    string p = Path::Combine("1", "2/");
    ASSERT_EQ(p, "1/2/");
#endif
}

TEST(Path, Combine2_3)
{
#if defined(_WIN32) || defined(_WIN64)
    string p = Path::Combine("\\1", "2\\");
    ASSERT_EQ(p, "\\1\\2\\");
#else
    string p = Path::Combine("/1", "2/");
    ASSERT_EQ(p, "/1/2/");
#endif
}

TEST(Path, Combine3)
{
    string p = Path::Combine("1", "2", "3");
#if defined(_WIN32) || defined(_WIN64)
    ASSERT_EQ(p, "1\\2\\3");
#else
    ASSERT_EQ(p, "1/2/3");
#endif
}

TEST(Path, Combine3_2)
{
#if defined(_WIN32) || defined(_WIN64)
    string p = Path::Combine("1", "2", "3\\");
    ASSERT_EQ(p, "1\\2\\3\\");
#else
    string p = Path::Combine("1", "2", "3/");
    ASSERT_EQ(p, "1/2/3/");
#endif
}

TEST(Path, Combine3_3)
{
#if defined(_WIN32) || defined(_WIN64)
    string p = Path::Combine("\\1", "2", "3\\");
    ASSERT_EQ(p, "\\1\\2\\3\\");
#else
    string p = Path::Combine("/1", "2", "3/");
    ASSERT_EQ(p, "/1/2/3/");
#endif
}

TEST(Path, Combine4)
{
    string p = Path::Combine("1", "2", "3", "4");
#if defined(_WIN32) || defined(_WIN64)
    ASSERT_EQ(p, "1\\2\\3\\4");
#else
    ASSERT_EQ(p, "1/2/3/4");
#endif
}

TEST(Path, CombineVec)
{
    string p = Path::Combine(std::vector<std::string>{"1", "2", "3", "4"});
#if defined(_WIN32) || defined(_WIN64)
    ASSERT_EQ(p, "1\\2\\3\\4");
#else
    ASSERT_EQ(p, "1/2/3/4");
#endif
}

#if defined(_WIN32) || defined(_WIN64)
TEST(Path, ModuleDir)
{
    string p = Path::ModuleDir();
    ASSERT_TRUE(!p.empty());
}
#endif

TEST(Path, isRelative)
{
    ASSERT_EQ(Path::IsPathFullyQualified("1123"), false);
    ASSERT_EQ(Path::IsPathFullyQualified("/1123"), false); //目前这个是windows下的结果为false

    ASSERT_EQ(Path::IsPathRooted("1123"), false);
    ASSERT_EQ(Path::IsPathRooted("/1123"), true);

#if defined(_WIN32) || defined(_WIN64)

    ASSERT_EQ(Path::IsPathFullyQualified("\\"), false);
    ASSERT_EQ(Path::IsPathFullyQualified("C:/1123"), true);
    ASSERT_EQ(Path::IsPathFullyQualified("C:\\1123"), true);
    ASSERT_EQ(Path::IsPathFullyQualified("C:/"), true);
    ASSERT_EQ(Path::IsPathFullyQualified("C:\\"), true);
    ASSERT_EQ(Path::IsPathFullyQualified("G:/"), true);

    ASSERT_EQ(Path::IsPathRooted("\\1123"), true);
    ASSERT_EQ(Path::IsPathRooted("C:/1123"), true);
#endif
}

TEST(Path, GetPathRoot)
{
    ASSERT_EQ(Path::GetPathRoot("myfile.ext"), "");
    ASSERT_EQ(Path::GetPathRoot("/mydir/"), "/");
#if defined(_WIN32) || defined(_WIN64)
    ASSERT_EQ(Path::GetPathRoot("\\mydir\\"), "\\");
    ASSERT_EQ(Path::GetPathRoot("C:\\mydir\\myfile.ext"), "C:\\");
#endif
}
