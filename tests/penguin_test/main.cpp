#include <penguin/penguin.h>
#include <penguin/penguin_status.h>
#include <boost/ut.hpp>
#include <cstring>
#include <string>

int main() {
  using namespace boost::ut;

  // Load data
  PenguinData data = {nullptr, nullptr};

  std::string path = "../../projects/hello_shared/libhello_shared.dll";
  data.path = new char[path.size() + 1];
  strncpy_s(data.path, path.size() + 1, path.c_str(), path.size());

  // Initialize penguin
  expect(kPenguinSuccess == initializePenguin());

  // Get shared library
  expect(kPenguinSuccess == loadSharedObject(&data))
      << "Unable to load " << path;

  // Get function from shared library
  const char* func_name = "getHelloWorld";
  void* sym = nullptr;

  expect(kPenguinSuccess == findSymbol(&data, func_name, &sym))
      << "Unable to find " << func_name;

  auto get_hello_world = reinterpret_cast<const char*(*)()>(sym);
  std::string hello_world = get_hello_world();

  // Release the shared library
  expect(kPenguinSuccess == unloadSharedObject(&data))
      << "Unable to free shared object";

  // Shutdown penguin
  expect(kPenguinSuccess == shutdownPenguin());

  // Free dynamic memory
  if (nullptr != data.path) {
    delete[] data.path;
    data.path = nullptr;
  }
}
