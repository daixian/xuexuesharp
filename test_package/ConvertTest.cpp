#include "gtest/gtest.h"

#include "xuexue/csharp/Convert.h"

#pragma execution_character_set("utf-8")

using namespace std;
using namespace xuexue::csharp;

TEST(Convert, Base64)
{
    vector<unsigned char> data;

    for (size_t count = 0; count < 1024; count++) {
        data.clear();
        for (size_t i = 0; i < count; i++) {
            data.push_back(i);
        }

        string base64 = Convert::ToBase64String(data.data(), 0, data.size());
        vector<unsigned char> data2 = Convert::FromBase64String(base64);

        for (size_t i = 0; i < data.size(); i++) {
            ASSERT_TRUE(data[i] == data2[i]);
        }
    }
}

TEST(Convert, Base64_2)
{
    //测一下带offset的情况
    int offset = 10;
    vector<unsigned char> data;

    for (size_t count = 24; count < 1024; count++) {
        data.clear();
        for (size_t i = 0; i < count; i++) {
            data.push_back(i);
        }

        string base64 = Convert::ToBase64String(data.data(), offset, data.size() - offset);
        vector<unsigned char> data2 = Convert::FromBase64String(base64);

        for (size_t i = 0; i < data2.size(); i++) {
            ASSERT_TRUE(data[i + offset] == data2[i]);
        }
    }
}

TEST(Convert, Base32)
{
    vector<unsigned char> data;

    for (size_t count = 0; count < 1024; count++) {
        data.clear();
        for (size_t i = 0; i < count; i++) {
            data.push_back(i);
        }

        string base32 = Convert::ToBase32String(data.data(), 0, data.size());
        vector<unsigned char> data2 = Convert::FromBase32String(base32);

        for (size_t i = 0; i < data.size(); i++) {
            ASSERT_TRUE(data[i] == data2[i]);
        }
    }
}

TEST(Convert, Base32_2)
{
    //测一下带offset的情况
    int offset = 10;
    vector<unsigned char> data;

    for (size_t count = 24; count < 1024; count++) {
        data.clear();
        for (size_t i = 0; i < count; i++) {
            data.push_back(i);
        }

        string base32 = Convert::ToBase32String(data.data(), offset, data.size() - offset);
        vector<unsigned char> data2 = Convert::FromBase32String(base32);

        for (size_t i = 0; i < data2.size(); i++) {
            ASSERT_TRUE(data[i + offset] == data2[i]);
        }
    }
}