﻿#include "File.h"

#include <iostream>
#include <fstream>

#include "Poco/File.h"
#include "stdio.h"

#include <Poco/TextConverter.h>
#include <Poco/UTF8Encoding.h>
#include <Poco/Windows936Encoding.h>

#include <Poco/UTF16Encoding.h>

namespace xuexue {
namespace csharp {

/*
ios::app：      以追加的方式打开文件 
ios::ate：      文件打开后定位到文件尾，ios:app就包含有此属性 
ios::binary：   以二进制方式打开文件，缺省的方式是文本方式。两种方式的区别见前文 
ios::in：       文件以输入方式打开（文件数据输入到内存） 
ios::out：      文件以输出方式打开（内存数据输出到文件） 
ios::nocreate： 不建立文件，所以文件不存在时打开失败 
ios::noreplace：不覆盖文件，所以打开文件时如果文件存在失败 
ios::trunc：    如果文件存在，把文件长度设为0 
*/

//File::File()
//{
//}
//
//File::~File()
//{
//}

void File::AppendAllText(const std::string& path, const std::string& contents)
{
    std::ofstream ofs(path, std::ios::app | std::ios::binary);
    if (ofs.is_open()) {
        ofs.write(contents.c_str(), static_cast<std::streamsize>(contents.size()));
        ofs.close();
    }
}

void File::Delete(const std::string& path)
{
    Poco::File file(path);
    if (file.exists())
        file.remove();
}

bool File::Exists(const std::string& path)
{
    Poco::File file(path);
    return file.exists();
}

std::vector<char> File::ReadAllBytes(const std::string& path)
{
    std::vector<char> data;
    if (File::Exists(path)) {
        std::ifstream ifs;
        ifs.open(path, std::ios::binary);
        if (ifs.is_open()) {
            //获得文件长度
            ifs.seekg(0, std::ios_base::end);
            int len = static_cast<int>(ifs.tellg());

            //回到文件头
            ifs.seekg(0, std::ios_base::beg);

            data.resize(len);
            ifs.read((char*)data.data(), len);
            ifs.close();
        }
        else {
        }
    }
    return data;
}

std::string File::ReadAllText(const std::string& path)
{
    std::string text;
    if (File::Exists(path)) {
        std::ifstream ifs;
        ifs.open(path, std::ios::binary);
        if (ifs.is_open()) {
            //获得文件长度
            ifs.seekg(0, std::ios_base::end);
            int len = static_cast<int>(ifs.tellg());

            //回到文件头
            ifs.seekg(0, std::ios_base::beg);

            text.resize(len);
            ifs.read((char*)text.data(), len);
            ifs.close();
        }
        else {
        }
    }
    return text;
}

std::string File::ReadAllText(const std::string& path, const Encoding encoding)
{
    //C#里面的字符串应该都是UTF8的,所以这个函数应该就是把GBK编码的文本转成UTF8的
    if (encoding == Encoding::GBK) {
        std::string s = ReadAllText(path);
        Poco::Windows936Encoding cp936;
        Poco::UTF8Encoding utf8;
        Poco::TextConverter converter(cp936, utf8);
        std::string dst;
        converter.convert(s, dst);
        return dst;
    }
    if (encoding == Encoding::UTF16) {
        std::string s = ReadAllText(path);
        Poco::UTF16Encoding utf16;
        Poco::UTF8Encoding utf8;
        Poco::TextConverter converter(utf16, utf8);
        std::string dst;
        converter.convert(s, dst);
        return dst;
    }
    else {
        return ReadAllText(path);
    }
}

void File::WriteAllBytes(const std::string& path, const char* bytes, int len)
{
    std::ofstream ofs(path, std::ios::out | std::ios::binary);
    if (ofs.is_open()) {
        ofs.write(bytes, static_cast<std::streamsize>(len));
        ofs.close();
    }
}

void File::WriteAllText(const std::string& path, const std::string& contents)
{
    std::ofstream ofs(path, std::ios::out | std::ios::binary);
    if (ofs.is_open()) {
        ofs << contents;
        ofs.close();
    }
}

void File::WriteAllText(const std::string& path, const std::string& contents, const Encoding encoding)
{
    //C#里面的字符串应该都是UTF8的
    if (encoding == Encoding::GBK) {
        Poco::Windows936Encoding cp936;
        Poco::UTF8Encoding utf8;
        Poco::TextConverter converter(utf8, cp936);
        std::string dst;
        converter.convert(contents, dst);

        WriteAllText(path, dst);
        return;
    }
    else if (encoding == Encoding::UTF16) {
        Poco::UTF16Encoding utf16;
        Poco::UTF8Encoding utf8;
        Poco::TextConverter converter(utf8, utf16);
        std::string dst;
        converter.convert(contents, dst);

        WriteAllText(path, dst);
        return;
    }
    else {
        WriteAllText(path, contents);
    }
}

} // namespace csharp
} // namespace xuexue