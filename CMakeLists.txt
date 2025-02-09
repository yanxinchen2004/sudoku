CMAKE_MINIMUM_REQUIRED(VERSION 3.12)

PROJECT(sudoku)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(CMAKE_BUILD_TYPE "Debug")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-O0 -Wall -g2)
else(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_options(-O3 -Wall)
endif()

set(CMAKE_VERBOSE_MAKEFILE ON)

# enable_testing()

add_definitions(-DDEBUG)

# add_subdirectory(test) # 添加test子目录

SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")

INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/include")

# 这段代码可以区分操作系统
MESSAGE("Identifying the OS...")
if(WIN32)
  MESSAGE("This is Windows.")
  if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options("/source-charset:utf-8")
    add_compile_options("/execution-charset:utf-8")
  else()
    add_compile_options("-finput-charset=utf-8")
    add_compile_options("-fexec-charset=utf-8")
  endif()
elseif(APPLE)
  MESSAGE("This is MacOS.")
elseif(UNIX)
  MESSAGE("This is Linux.")
endif()
# 这段代码可以区分操作系统

AUX_SOURCE_DIRECTORY(src DIR_SRCS) # 添加源代码文件夹, 自动扫描所有文件

add_executable(sudoku  # 输出名为sudoku的可执行文件
   ${DIR_SRCS}
)
