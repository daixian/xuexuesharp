#include "gtest/gtest.h"

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

TEST(Path, Combine2_4)
{
    string p = Path::Combine("1", "/2/3");
#if defined(_WIN32) || defined(_WIN64)
    ASSERT_EQ(p, "\\2\\3");
#else
    ASSERT_EQ(p, "/2/3");
#endif
}

TEST(Path, Combine2_6)
{
    string p = Path::Combine("1", "2/3/");
#if defined(_WIN32) || defined(_WIN64)
    ASSERT_EQ(p, "1\\2\\3\\");
#else
    ASSERT_EQ(p, "1/2/3/");
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

TEST(Path, Combine3_force)
{
    string p = Path::Combine("1", Path::ToRelative("/2"), Path::ToRelative("\\3"));
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
#if defined(_WIN32) || defined(_WIN64)
    ASSERT_EQ(Path::IsPathFullyQualified("/1123"), false); //目前这个是windows下的结果为false
#else
    ASSERT_EQ(Path::IsPathFullyQualified("/1123"), true);
#endif
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

TEST(Path, GetDirectoryName)
{
#if defined(_WIN32) || defined(_WIN64)
    ASSERT_EQ(Path::GetDirectoryName("C:\\MyDir\\MySubDir\\myfile.ext"), "C:\\MyDir\\MySubDir");
    ASSERT_EQ(Path::GetDirectoryName("C:\\MyDir\\MySubDir"), "C:\\MyDir");
    ASSERT_EQ(Path::GetDirectoryName("C:\\MyDir\\"), "C:\\MyDir");
    ASSERT_EQ(Path::GetDirectoryName("C:\\MyDir"), "C:\\");
    ASSERT_EQ(Path::GetDirectoryName("C:\\"), "");
    ASSERT_EQ(Path::GetDirectoryName("1\\2\\3"), "1\\2");
    ASSERT_EQ(Path::GetDirectoryName("\\"), "");
#endif
    ASSERT_EQ(Path::GetDirectoryName("/"), "");

    ASSERT_EQ(Path::GetDirectoryName("123"), "");
}

TEST(Path, GetExtension)
{
    ASSERT_EQ(Path::GetExtension("C:\\MyDir\\MySubDir\\myfile.ext"), ".ext");
    ASSERT_EQ(Path::GetExtension("C:\\MyDir\\MySubDir\\"), "");
    ASSERT_EQ(Path::GetExtension("C:\\MyDir\\MySubDir\\123"), "");
}
