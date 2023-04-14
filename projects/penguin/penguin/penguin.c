#include "penguin/penguin.h"

#if defined(WIN32)
#include "penguin/penguin_windows.h"
#elif defined(UNIX)
#include "penguin/penguin_linux.h"
#endif

PenguinStatus findSymbol(PenguinData* data, const char* name, void** symbol) {
  return findSymbolImpl(data, name, symbol);
}

PenguinStatus initializePenguin() {
  return initializePenguinImpl();
}

PenguinStatus loadSharedObject(PenguinData* data) {
  return loadSharedObjectImpl(data);
}

PenguinStatus setSearchPath(const char* path) {
  return setSearchPathImpl(path);
}

PenguinStatus shutdownPenguin() {
  return shutdownPenguinImpl();
}

PenguinStatus unloadSharedObject(PenguinData* data) {
  return unloadSharedObjectImpl(data);
}