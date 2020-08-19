# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.1)

if(CMAKE_CL_64)    #CMAKE的内建变量，如果是true，就说明编译器的64位的，自然可以编译64bit的程序
set(ADDRESS_MODEL 64)
set(NODE_TARGET x64)
else()
set(ADDRESS_MODEL 32)
set(NODE_TARGET x86)
endif()

# 设置C++标准为 C++ 11
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE "Debug")

# 项目信息
project (tutu)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. SRC_LIST) # 搜索当前目录下的所有.cpp文件


# 添加子目录


# 指定生成目标 
add_executable(tutu ${SRC_LIST})

# 添加链接库
