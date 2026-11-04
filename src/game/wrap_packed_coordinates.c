#ifndef LEAF_NAME
#define LEAF_NAME wrapPackedCoordinates
#endif

typedef unsigned int u32;
typedef int s32;

typedef struct PackedCoordinateState {
    unsigned char pad00[0x30];
    u32 first;
    unsigned char pad34[0x10];
    u32 second;
} PackedCoordinateState;

extern PackedCoordinateState D_8005A894;
extern s32 D_8005A834;
extern PackedCoordinateState *D_8005A890;

void LEAF_NAME(void)
{
    register u32 *source __asm__("$6") = (u32 *)&D_8005A894;
    PackedCoordinateState *destination = D_8005A890;
    register u32 packed __asm__("$4");

    __asm__ ("" : "=r"(source) : "0"(source));

    packed = source[0x0C];
    destination->first =
        ((((s32)(packed >> 16) + D_8005A834) % 0xFFFF) << 16) |
        (((s32)(packed & 0xFFFF) + D_8005A834) % 0xFFFF);

    packed = source[0x11];
    destination->second =
        ((((s32)(packed >> 16) + D_8005A834) % 0xFFFF) << 16) |
        (((s32)(packed & 0xFFFF) + D_8005A834) % 0xFFFF);
}
