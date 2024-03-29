﻿#pragma once

#include <vector>
#include <string>

#include "Encoding.h"

namespace xuexue {
namespace csharp {

/**
 * 对应C#的File静态类.
 *
 * @author daixian
 * @date 2020/9/25
 */
class File
{
  public:
    /**
     * 打开一个文件，向其中追加指定的字符串，然后关闭该文件。
     * 如果文件不存在，此方法将创建一个文件，将指定的字符串写入文件，然后关闭该文件。
     *
     * @author daixian
     * @date 2020/9/25
     *
     * @param  path     要打开的文件.
     * @param  contents 要追加的内容.
     */
    static void AppendAllText(const std::string& path, const std::string& contents);

    /**
     * 拷贝一个文件.
     *
     * @author daixian
     * @date 2021/4/7
     *
     * @param  sourceFileName 源文件名.
     * @param  destFileName   目标文件名.
     * @param  overwrite      (Optional) True to overwrite, false to preserve.
     */
    static void Copy(const std::string& sourceFileName, const std::string& destFileName, bool overwrite = true);

    /**
     * 删除一个文件
     *
     * @author daixian
     * @date 2020/9/25
     *
     * @param  path 要删除的文件路径.
     */
    static void Delete(const std::string& path);

    /**
     * 确定指定的文件是否存在,如果输入了一个文件夹路径那么也是不存在的.
     *
     * @author daixian
     * @date 2020/9/25
     *
     * @param  path 文件路径.
     *
     * @returns 文件存在返回True.
     */
    static bool Exists(const std::string& path);

    /**
     * 打开一个二进制文件，将文件的内容读入一个字节数组，然后关闭该文件。
     *
     * @author daixian
     * @date 2020/9/25
     *
     * @param  path 要打开以进行读取的文件.
     *
     * @returns 包含文件内容的字节数组.
     */
    static std::vector<char> ReadAllBytes(const std::string& path);

    /**
     * 打开一个二进制文件，将文件的内容读入一个字节数组，然后关闭该文件。(它提供char的数据结果).
     *
     * @author daixian
     * @date 2020/12/10
     *
     * @param       path  要打开以进行读取的文件.
     * @param [out] bytes 数据结果.
     */
    static void ReadAllBytes(const std::string& path, std::vector<char>& bytes);

    /**
     * 打开一个二进制文件，将文件的内容读入一个字节数组，然后关闭该文件。(它提供uchar的数据结果).
     *
     * @author daixian
     * @date 2020/12/10
     *
     * @param       path  要打开以进行读取的文件.
     * @param [out] bytes 数据结果.
     */
    static void ReadAllBytes(const std::string& path, std::vector<unsigned char>& bytes);

    /**
     * 打开一个文本文件，读取文件中的所有文本，然后关闭此文件。
     *
     * @author daixian
     * @date 2020/9/25
     *
     * @param  path 要打开以进行读取的文件.
     *
     * @returns 文件中的所有文本.
     */
    static std::string ReadAllText(const std::string& path);

    /**
     * 打开一个文件，使用指定的编码读取文件中的所有文本，然后关闭此文件。
     *
     * @author daixian
     * @date 2020/9/25
     *
     * @param  path     要打开以进行读取的文件.
     * @param  encoding 这个文件的编码.
     *
     * @returns 文件中的所有文本(UTF8编码).
     */
    static std::string ReadAllText(const std::string& path, Encoding encoding);

    /**
     * @brief 打开一个文件，向其中写入指定的字节，然后关闭此文件。
     *        C#中如果文件夹不存在那么会抛出异常.这里如果文件夹不存在则会创建文件夹。
     *
     * @param path 要写入的文件路径.
     * @param[in] bytes 要写入文件的字节数组
     * @param len 要写入的长度.
     *
     * @return 成功返回true.
     */
    static bool WriteAllBytes(const std::string& path, const char* bytes, int len);

    /**
     * 创建一个新文件，向其中写入指定的字符串，然后关闭文件。 如果目标文件已存在，则覆盖该文件。
     * C#中如果文件夹不存在那么会抛出异常.这里如果文件夹不存在则会创建文件夹。
     *
     * @param  path     要写入的文件.
     * @param  contents 要写入文件的内容.
     *
     * @return 成功返回true.
     */
    static bool WriteAllText(const std::string& path, const std::string& contents);

    /**
     * 创建一个新文件，使用指定编码向其中写入指定的字符串，然后关闭文件。 如果目标文件已存在，则覆盖该文件。
     * C#中如果文件夹不存在那么会抛出异常.这里如果文件夹不存在则会创建文件夹。
     *
     * @param  path     要写入的文件.
     * @param  contents 要写入文件的内容.
     * @param  encoding 这个文件的编码.
     *
     * @return 成功返回true.
     */
    static bool WriteAllText(const std::string& path, const std::string& contents, Encoding encoding);
};

} // namespace csharp
} // namespace xuexue
