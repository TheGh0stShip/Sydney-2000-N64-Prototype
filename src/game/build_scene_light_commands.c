/* Exact SN GCC 2.8 reconstruction of func_800064D0, ROM 0x70D0..0x733C.
 * Three packed colors and three ambient records precede the group arrays.
 * All addresses and pointer fields use the N64 o32 ABI.
 * External symbols: sceneLightState=0x80043D48, defaultSceneLight=0x80043D28.
 * Matching profile: SN GCC -O2 -G0 -mcpu=vr4300 -mips3 -mhard-float -meb.
 * Empty asm constraints emit no instructions; they retain the original
 * scratch registers, evaluation boundaries, and loop induction variables.
 * Sampled behavior: make validate-scene-lights.
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct { u32 command, argument; } Gfx;
typedef struct {
    u32 flags;
    u32 reserved;
    u8 light[16];
    u32 viewMask;
    u32 padding;
} SceneLight;
typedef char check_light_size[sizeof(SceneLight) == 32 ? 1 : -1];
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
typedef char check_ambient_size[sizeof(SceneAmbient) == 16 ? 1 : -1];
typedef char check_state_size[sizeof(SceneLightState) == 0xA8 ? 1 : -1];
extern SceneLightState sceneLightState;
extern u8 defaultSceneLight[];

void func_800064D0(Gfx **displayList, u32 view) {
    Gfx **head = displayList;
    u32 viewIndex = view;
    register u32 slot __asm__("$12");
    register u8 *base __asm__("$5");
    register u8 *ambient __asm__("$4");
    register u8 *color __asm__("$3");
    register Gfx *cursor __asm__("$11");
    register u32 count __asm__("$7");
    register u32 fallback __asm__("$15");
    register u32 group __asm__("$9");
    register u32 mask __asm__("$8");
    register u8 *row __asm__("$6");
    __asm__ volatile("" : "+r"(head), "+r"(viewIndex));
    slot = 1;
    base = (u8 *)&sceneLightState;
    ambient = (u8 *)(viewIndex * 16);
    __asm__("" : "+r"(ambient));
    ambient += (u32)base;
    color = base + viewIndex * 4;
    cursor = *head;
    ambient[0x18] = *(u32 *)(color + 8) >> 16;
    ambient[0x19] = *(u32 *)(color + 8) >> 8;
    ambient[0x1A] = *(u32 *)(color + 8);
    ambient[0x1C] = *(u32 *)(color + 8) >> 16;
    ambient[0x1D] = *(u32 *)(color + 8) >> 8;
    ambient[0x1E] = *(u32 *)(color + 8);
    count = 0;
    fallback = count;
    group = count;
    mask = slot << viewIndex;
    row = base;
    for (;;) {
        register u32 index __asm__("$4");
        if (group >= 8) break;
        if (((SceneLightState *)row)->entries[0]) {
            index = 0;
            if (((SceneLightState *)row)->entryCounts[0]) {
                do {
                    SceneLight *light = (SceneLight *)(index * 32 +
                        (u32)((SceneLightState *)row)->entries[0]);
                    if ((light->flags & 1) && light->viewMask == mask) count++;
                    index++;
                } while (index < *(u32 *)(group * 4 + (u32)base + 0x48));
            }
        }
        row += 4;
        group++;
    }
    if (!count) { count = 1; fallback += count; }
    {
        Gfx *command = cursor++;
        command->command = 0xDB020000;
        command->argument = count * 24;
    }
    {
        register u8 *secondRow __asm__("$10");
        register u32 secondMask __asm__("$14");
        register u32 commandBase __asm__("$13");
        register u32 temporary __asm__("$2");
        group = 0;
        temporary = 1;
        secondMask = temporary << viewIndex;
        __asm__("" : "+r"(secondMask));
        commandBase = 0xDC08000A;
        /* Original o32 state-page address reload, separate from its offset. */
        temporary = 0x80040000;
        __asm__("" : "+r"(temporary));
        secondRow = (u8 *)(temporary + 0x3D48);
        for (;;) {
            register u32 index __asm__("$6");
            if (group >= 8) break;
            if (((SceneLightState *)secondRow)->entries[0]) {
                register u8 *innerRow __asm__("$8");
                register u32 slotOffset __asm__("$7");
                register u32 *wordPointer __asm__("$4");
                index = 0;
                innerRow = secondRow;
                temporary = slot * 3;
                __asm__("" : "+r"(temporary));
                /* gSPLight DMEM slot encoding advances by three 8-byte units. */
                slotOffset = temporary + 3;
                wordPointer = (u32 *)((u8 *)cursor - 4);
                for (; ; index++) {
                    register u32 indexOffset __asm__("$5");
                    SceneLight *light;
                    if (index >= ((SceneLightState *)innerRow)->entryCounts[0]) break;
                    indexOffset = index * 32;
                    light = (SceneLight *)(indexOffset + (u32)((SceneLightState *)innerRow)->entries[0]);
                    if ((light->flags & 1) && light->viewMask == secondMask) {
                        wordPointer += 2;
                        cursor++;
                        wordPointer[-1] = ((slotOffset & 0xFF) << 8) | commandBase;
                        slotOffset += 3;
                        slot++;
                        wordPointer[0] = (u32)((SceneLightState *)innerRow)->entries[0] + indexOffset + 8;
                    }
                }
            }
            secondRow += 4;
            group++;
        }
    }
    if (fallback) {
        Gfx *command = cursor++;
        command->command = 0xDC08000A | (((slot * 3 + 3) & 0xFF) << 8);
        command->argument = (u32)defaultSceneLight;
        slot++;
    }
    {
        register Gfx *command __asm__("$5") = cursor++;
        register u32 tailCommand __asm__("$3") = 0xDC08000A;
        register Gfx *sync __asm__("$4") = cursor++;
        command->command = tailCommand | (((slot * 3 + 3) & 0xFF) << 8);
        command->argument = (u32)&sceneLightState.ambient[viewIndex];
        sync->command = 0xE7000000;
        sync->argument = 0;
    }
    __asm__("" : : "r"(viewIndex));
    *head = cursor;
}
