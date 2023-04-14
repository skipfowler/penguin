#ifndef PENGUIN_STATUS_H
#define PENGUIN_STATUS_H

#if defined(__cplusplus)
extern "C" {
#endif

typedef enum PenguinStatus {
  // penguin succeeded the operation
  kPenguinSuccess,
  // penguin needs to be initialized
  kPenguinUninitialized,
  // penguin was provided null data
  kPenguinNullData,
  // penguin was provided a path that does not exist
  kPenguinPathNotExists,
  // penguin failed the operation
  kPenguinFail,
  // penguin has already loaded a handle
  kPenguinAlreadyLoaded,
  // penguin failed to release mutex
  kPenguinMutexReleaseFail,
} PenguinStatus;

#if defined(__cplusplus)
}
#endif

#endif
