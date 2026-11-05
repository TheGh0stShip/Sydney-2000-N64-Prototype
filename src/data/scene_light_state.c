/* Resident scene-light state, N64 big-endian MIPS/o32. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct SceneLight SceneLight;
typedef struct {
    u8 color[3], pad;
    u8 copy[3], pad2;
    u8 unused[8];
} SceneAmbient;
typedef struct {
    u32 index, count;
    u32 colors[3];
    u32 unused14;
    SceneAmbient ambient[3];
    u32 entryCounts[8];
    u32 entryMasks[8];
    SceneLight *entries[8];
} SceneLightState;
#define MEMBER_OFFSET(type, member) ((u32)&((type *)0)->member)
typedef char check_u32_size[sizeof(u32) == 4 ? 1 : -1];
typedef char check_pointer_size[sizeof(void *) == 4 ? 1 : -1];
typedef char check_ambient_size[sizeof(SceneAmbient) == 16 ? 1 : -1];
typedef char check_state_size[sizeof(SceneLightState) == 0xA8 ? 1 : -1];
typedef char check_ambient_offset[MEMBER_OFFSET(SceneLightState, ambient) == 0x18 ? 1 : -1];
typedef char check_count_offset[MEMBER_OFFSET(SceneLightState, entryCounts) == 0x48 ? 1 : -1];
typedef char check_pointer_offset[MEMBER_OFFSET(SceneLightState, entries) == 0x88 ? 1 : -1];

/* Explicit .data placement retains this initialized object outside BSS. */
SceneLightState sceneLightState __attribute__((section(".data"))) = {0};
