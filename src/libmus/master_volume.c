#include <PR/ultratypes.h>

extern s16 gMusMasterVolumeEffects;
extern s16 gMusMasterVolumeSongs;

void MusSetMasterVolume(s32 type, s32 volume) {
    if (type & 1) {
        gMusMasterVolumeEffects = volume;
    }
    if (type & 2) {
        gMusMasterVolumeSongs = volume;
    }
}
