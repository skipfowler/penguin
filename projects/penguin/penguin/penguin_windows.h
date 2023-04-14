#ifndef PENGUIN_WINDOWS_H
#define PENGUIN_WINDOWS_H

#include "penguin/penguin_data.h"
#include "penguin/penguin_status.h"

#if defined(__cplusplus)
extern "C" {
#endif

// Find symbol from shared object for Windows
PenguinStatus findSymbolImpl(PenguinData* data, const char* name, void** symbol);

// Initialize penguin for Windows
PenguinStatus initializePenguinImpl();

// Load shared object for Windows
PenguinStatus loadSharedObjectImpl(PenguinData* data);

// Set search path for finding shared objects
PenguinStatus setSearchPathImpl(const char* path);

// Shutdown penguin for Windows
PenguinStatus shutdownPenguinImpl();

// Unload shared object for Windows
PenguinStatus unloadSharedObjectImpl(PenguinData* data);

#if defined(__cplusplus)
}
#endif

#endif