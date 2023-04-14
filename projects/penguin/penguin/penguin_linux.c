#if defined(UNIX)

#include "penguin/penguin_linux.h"
#include "penguin/penguin_status.h"

// Find symbol from shared object for Linux
PenguinStatus findSymbolImpl(PenguinData* data, const char* name,
                             void* symbol) {
  return kPenguinFail;
}

// Initialize penguin for Linux
PenguinStatus initializePenguinImpl() {
  return kPenguinFail;
}

// Load shared object for Linux
PenguinStatus loadSharedObjectImpl(PenguinData* data) {
  return kPenguinFail;
}

// Unload shared object for Linux
PenguinStatus unloadSharedObjectImpl(PenguinData* data) {
  return kPenguinFail;
}

// Shutdown penguin for Linux
PenguinStatus shutdownPenguinImpl() {
  return kPenguinFail;
}

#endif