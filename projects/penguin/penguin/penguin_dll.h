#ifndef PENGUIN_DLL_H
#define PENGUIN_DLL_H

#ifdef _WIN32
#ifdef _IS_SHARED
#ifdef penguin_EXPORTS
#define PENGUIN_DLL __declspec(dllexport)
#else
#define PENGUIN_DLL __declspec(dllimport)
#endif
#else
#define PENGUIN_DLL
#endif
#else
#define PENGUIN_DLL
#endif

#endif