#include "File.h"

#include <iostream>
#include <fstream>

#include "Poco/Path.h"
#include "Poco/File.h"
#include "Poco/FileStream.h"
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

void File::AppendAllText(const std::string& path, const std::string& contents)
{
    Poco::FileOutputStream ofs(path, std::ios::app | std::ios::binary);
    if (ofs) {
        ofs.write(contents.c_str(), static_cast<std::streamsize>(contents.size()));
        ofs.close();
    }
}

void File::Copy(const std::string& sourceFileName, const std::string& destFileName, bool overwrite)
{
    Poco::File file(Poco::Path(sourceFileName).absolute());
    //创建文件夹
    Poco::File destDir = Poco::Path(destFileName).makeFile().parent().absolute();
    destDir.createDirectories();
    if (!overwrite) {
        file.copyTo(destFileName, Poco::File::Options::OPT_FAIL_ON_OVERWRITE);
    }
    else {
        file.copyTo(destFileName);
    }
}

void File::Delete(const std::string& path)
{
    Poco::File file(Poco::Path(path).absolute());
    if (file.exists() && file.isFile()) //要先判断是否文件存在,然后再判断是否是文件,否则io异常
        file.remove();
}

bool File::Exists(const std::string& path)
{
    Poco::File file(Poco::Path(path).absolute());
    //如果传入了一些非法的文件名,那么它会异常
    try {
        if (file.exists() && file.isFile()) {
            return true;
        }
    }
    catch (const std::exception& e) {
        printf("File.Exists():exception = %s \n", e.what());
    }

    return false;
}

std::vector<char> File::ReadAllBytes(const std::string& path)
{
    std::vector<char> data;
    if (File::Exists(path)) {
        Poco::FileInputStream ifs(path, std::ios::in | std::ios::binary);
        if (ifs) {
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

void File::ReadAllBytes(const std::string& path, std::vector<char>& bytes)
{
    if (File::Exists(path)) {
        Poco::FileInputStream ifs(path, std::ios::in | std::ios::binary);
        if (ifs) {
            bytes.clear();
            //获得文件长度
            ifs.seekg(0, std::ios_base::end);
            int len = static_cast<int>(ifs.tellg());

            //回到文件头
            ifs.seekg(0, std::ios_base::beg);

            bytes.resize(len);
            ifs.read((char*)bytes.data(), len);
            ifs.close();
        }
        else {
        }
    }
}

void File::ReadAllBytes(const std::string& path, std::vector<unsigned char>& bytes)
{
    if (File::Exists(path)) {
        Poco::FileInputStream ifs(path, std::ios::in | std::ios::binary);
        if (ifs) {
            bytes.clear();
            //获得文件长度
            ifs.seekg(0, std::ios_base::end);
            int len = static_cast<int>(ifs.tellg());

            //回到文件头
            ifs.seekg(0, std::ios_base::beg);

            bytes.resize(len);
            ifs.read((char*)bytes.data(), len);
            ifs.close();
        }
        else {
        }
    }
}

std::string File::ReadAllText(const std::string& path)
{
    std::string text;
    if (File::Exists(path)) {
        Poco::FileInputStream ifs(path, std::ios::in | std::ios::binary);
        if (ifs) {
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

std::string File::ReadAllText(const std::string& path, Encoding encoding)
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
    //如果文件夹不存在那么会报异常
    //System.IO.DirectoryNotFoundException:“Could not find a part of the path 'C:\\shaTest\\text.txt'.”
    //std::ofstream ofs(path, std::ios::out | std::ios::binary);// std的这个在windows下utf8路径不行
    Poco::FileOutputStream ofs(path);
    if (ofs) {
        ofs.write(bytes, static_cast<std::streamsize>(len));
        ofs.close();
    }
}

void File::WriteAllText(const std::string& path, const std::string& contents)
{
    //ios::trunc 如果文件已存在则先删除该文件
    Poco::FileOutputStream ofs(path);

    //std::ofstream ofs(path, std::ios::out | std::ios::binary);   // std的这个在windows下utf8路径不行
    if (ofs) {
        ofs << contents;
    }
    ofs.close();
}

void File::WriteAllText(const std::string& path, const std::string& contents, Encoding encoding)
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
