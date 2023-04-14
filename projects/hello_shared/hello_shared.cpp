#include "hello_shared.h"

namespace flock::test {
const char* HelloShared::get() const {
  return "Hello world from HelloShared!";
}
}  // namespace flock::test

const char* getHelloWorld() {
  flock::test::HelloShared hello_shared;
  return hello_shared.get();
}