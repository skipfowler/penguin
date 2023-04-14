#pragma once

#ifdef _WIN32
#ifdef _IS_SHARED
#ifdef hello_shared_EXPORTS
#define HELLO_SHARED_DLL __declspec(dllexport)
#else
#define HELLO_SHARED_DLL __declspec(dllimport)
#endif
#else
#define HELLO_SHARED_DLL
#endif
#else
#define HELLO_SHARED_DLL
#endif