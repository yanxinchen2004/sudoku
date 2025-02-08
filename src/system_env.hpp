#ifndef SUDOKU_SYSTEM_ENV_H_
#define SUDOKU_SYSTEM_ENV_H_

#if _WIN32
#include <Windows.h>
#endif

inline void SetWindowsEnv() {
#if _WIN32
  SetConsoleOutputCP(CP_UTF8);
#endif
}

inline void SetSystemEnv() { SetWindowsEnv(); }

#endif
