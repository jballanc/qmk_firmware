#pragma once

#define STARTUP_SONG SONG(PLANCK_SOUND)

#define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND),   \
                              SONG(COLEMAK_SOUND),  \
                              SONG(DVORAK_SOUND)    \
}

// Prevent Mod/Layer-Tap from registering two keys when typing fast
#define PERMISSIVE_HOLD
