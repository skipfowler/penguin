#ifndef PENGUIN_DATA_H
#define PENGUIN_DATA_H

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct PenguinData {
  char* path;
  void* handle;
} PenguinData;

#if defined(__cplusplus)
}
#endif

#endif
