#!/usr/bin/env python3
# coding=utf-8

import os
import sys
import io
from conans import ConanFile, CMake, tools

# sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='gbk')
# os.system("chcp 65001")


class xuexuesharpConan(ConanFile):
    name = "xuexuesharp"
    version = "0.0.9"
    license = "This project is licensed under GLWTPL"
    author = "daixian<amano_tooko@qq.com>"
    url = "https://github.com/daixian/xuexuesharp"
    description = "一些仿C#类库的接口"
    topics = ("csharp", "xuexue", "daixian")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = {"shared": False,
                       "poco:enable_data_sqlite": False,
                       "poco:enable_mongodb": False,
                       "poco:enable_redis": False}
    generators = "cmake"
    exports_sources = "src/*"

    def requirements(self):
        self.requires("poco/[>=1.10.1]")
        self.requires("rapidjson/[>=1.1.0]")

    def _configure_cmake(self):
        '''
        转换python的设置到CMake
        '''
        cmake = CMake(self)
        # cmake.definitions["XUEXUESHARP_BUILD_SHARED"] = self.options.shared
        # 实际上这个库应该只为静态库
        cmake.definitions["XUEXUESHARP_BUILD_SHARED"] = False
        return cmake

    def build(self):
        print("进入了build...")
        cmake = self._configure_cmake()
        cmake.configure(source_folder="src")
        cmake.build()

        # Explicit way:
        # self.run('cmake %s/hello %s'
        #          % (self.source_folder, cmake.command_line))
        # self.run("cmake --build . %s" % cmake.build_config)

    def package(self):
        self.copy("*.h", dst="include", src="src")
        self.copy("*.hpp", dst="include", src="src")

        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.dylib*", dst="lib", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["xuexuesharp"]
        # 附带引用这些库
        # if self.settings.os == "Windows":
        #     self.cpp_info.libs.append("baseclasses")
