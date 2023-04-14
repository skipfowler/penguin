#pragma once

#include "hello_shared_dll.h"

namespace flock::test {
class HelloShared {
 public:
  const char* get() const;
};
}  // namespace flock::test

#if defined(__cplusplus)
extern "C" {
#endif

HELLO_SHARED_DLL const char* getHelloWorld();

#if defined(__cplusplus)
}
#endif