#if defined(UNIX)
#ifndef PENGUIN_LINUX_H
#define PENGUIN_LINUX_H

#include "penguin/penguin_data.h"
#include "penguin/penguin_status.h"

#if defined(__cplusplus)
extern "C" {
#endif

// Find symbol from shared object for Linux
PenguinStatus findSymbolImpl(PenguinData* data, const char* name, void* symbol);

// Initialize penguin for Linux
PenguinStatus initializePenguinImpl();

// Load shared object for Linux
PenguinStatus loadSharedObjectImpl(PenguinData* data);

// Unload shared object for Linux
PenguinStatus unloadSharedObjectImpl(PenguinData* data);

// Shutdown penguin for Linux
PenguinStatus shutdownPenguinImpl();

#if defined(__cplusplus)
}
#endif

#endif
#endif