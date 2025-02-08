#include <iostream>
#include <cstring>

#include "i18n.h"
#include "input.h"
#include "scene.h"
#include "system_env.hpp"
#include "utility.inl"


// cmake -B build -S . -G "Unix Makefiles"
// cmake -B build -S . -G "Visual Studio 17 2022"
// cmake -B build -S . -G "Ninja"
// -B 选项指定 CMake 用来存放构建输出文件的目录，这里是 build。如果 build 目录不存在，CMake 会创建它。
// -S .：-S 选项指定源代码目录，这里是当前目录 .。这告诉 CMake 从当前目录读取 CMakeLists.txt 文件。

// 然后 cmake --build build

static void printHelp() {
    std::cout << std::endl;
    std::cout << "sudoku - a little game in command line" << std::endl
              << std::endl;
    std::cout << "Usage:" << std::endl;
    std::cout << "\t sudoku [-l <progressFile>]" << std::endl << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "\t -l <path> \t specify path of progress file to load, optional." << std::endl
              << std::endl;
}

int main(int argc, char ** argv)
{
    SetSystemEnv();

    CScene scene;

    if (argc == 1) 
    {  
        InputLanguage();
        int eraseGridNumber = inputDifficulty();
        scene.generate();
        scene.eraseRandomGrids(eraseGridNumber);
    } 
    else if(argc == 2 && !strcmp(argv[1], "-h"))
    {
        printHelp();
        return 0;
    }
    else if (argc == 3 && !strcmp(argv[1], "-l"))
    {
        // load saved game progress
        if (!scene.load(argv[2])) {
            message(I18n::Instance().Get(I18n::Key::LOAD_PROGRESS_FAIL));
            return 0;
        }
        InputLanguage();
    } 
    else
    {
        std::cout << "Invalid input parameters" << std::endl;
        return 0;
    }
  
    scene.setMode(inputKeyMode());
  
    scene.play();

    return 0;
}