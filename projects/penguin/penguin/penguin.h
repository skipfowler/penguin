#ifndef PENGUIN_H
#define PENGUIN_H

#include "penguin/penguin_data.h"
#include "penguin/penguin_dll.h"
#include "penguin/penguin_status.h"

#if defined(__cplusplus)
extern "C" {
#endif

// Agnostic find symbol in shared object
PENGUIN_DLL PenguinStatus findSymbol(PenguinData* data, const char* name,
                                     void** symbol);

// Agnostic initialize penguin
PENGUIN_DLL PenguinStatus initializePenguin();

// Agnostic load shared objects
PENGUIN_DLL PenguinStatus loadSharedObject(PenguinData* data);

// Agnostic shutdown penguin
PENGUIN_DLL PenguinStatus shutdownPenguin();

// Agnostic set search paths for finding shared objects
PENGUIN_DLL PenguinStatus setSearchPath(const char* path);

// Agnostic unload shared object
PENGUIN_DLL PenguinStatus unloadSharedObject(PenguinData* data);

#if defined(__cplusplus)
}
#endif

#endif