#if defined(WIN32)

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#include "penguin/penguin_status.h"
#endif

#include <shlwapi.h>
#include <stdio.h>
#include <windows.h>
#include "penguin/penguin_windows.h"

HANDLE g_mutex = NULL;

PenguinStatus getWideString(const char* input_str, wchar_t* wide_str,
                            const int max_count) {
  int count = min(strlen(input_str) + 1, max_count);
  mbstowcs(wide_str, input_str, count);
  wide_str[count + 1] = '\0';
  return kPenguinSuccess;
}

PenguinStatus findSymbolImpl(PenguinData* data, const char* name,
                             void** symbol) {
  if (NULL != data && NULL != data->handle) {
#if defined(_WIN32_WCE)
    wchar_t wide_path[MAX_PATH];
    *symbol = (void*)GetProcAddress((HMODULE)data->handle, MAX_PATH);
#else
    *symbol = (void*)GetProcAddress((HMODULE)data->handle, name);
#endif

    return NULL != *symbol ? kPenguinSuccess : kPenguinFail;
  }

  return kPenguinFail;
}

PenguinStatus initializePenguinImpl() {
  if (NULL == g_mutex) {
    g_mutex = CreateMutex(NULL, FALSE, NULL);
    return kPenguinSuccess;
  }

  return kPenguinFail;
}

PenguinStatus loadSharedObjectImpl(PenguinData* data) {
  if (NULL == data) {
    return kPenguinNullData;
  }

  if (NULL != data->handle) {
    return kPenguinAlreadyLoaded;
  }

  if (NULL == g_mutex) {
    return kPenguinUninitialized;
  }

  WaitForSingleObject(g_mutex, INFINITE);

  DWORD flags = 0;

  wchar_t wide_path[MAX_PATH];
  getWideString(data->path, wide_path, MAX_PATH);

#if !defined(_WIN32_WCE)
  if (FALSE == PathIsRelativeW(wide_path)) {
    flags |= LOAD_WITH_ALTERED_SEARCH_PATH;
  }
#endif

  data->handle = LoadLibraryExW(wide_path, 0, flags);

  int error_code = GetLastError();

  if (0 != error_code) {
    return kPenguinFail;
  }

  if (!ReleaseMutex(g_mutex)) {
    return kPenguinMutexReleaseFail;
  }

  return kPenguinSuccess;
}

PenguinStatus setSearchPathImpl(const char* path) {
#if _WIN32_WINNT >= 0x0502
  wchar_t wide_path[MAX_PATH];
  getWideString(path, wide_path, MAX_PATH);

  if (TRUE == SetDllDirectoryW(wide_path)) {
    return kPenguinSuccess;
  }
#endif

  return kPenguinFail;
}

PenguinStatus shutdownPenguinImpl() {
  if (NULL != g_mutex) {
    CloseHandle(g_mutex);
    return kPenguinSuccess;
  }

  return kPenguinFail;
}

PenguinStatus unloadSharedObjectImpl(PenguinData* data) {
  if (NULL == data) {
    return kPenguinNullData;
  }

  if (NULL != data->handle && FreeLibrary(data->handle)) {
    data->handle = 0;
    return kPenguinSuccess;
  }

  return kPenguinFail;
};

#endif