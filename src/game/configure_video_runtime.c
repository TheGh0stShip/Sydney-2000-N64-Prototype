#ifndef LEAF_NAME
#define LEAF_NAME configureVideoRuntime
#endif
#ifndef APPLY_MODE_NAME
#define APPLY_MODE_NAME applyVideoMode
#endif
#ifndef WRAP_NAME
#define WRAP_NAME wrapPackedCoordinates
#endif
#ifndef SET_VALUE_NAME
#define SET_VALUE_NAME setVideoValue
#endif

typedef unsigned int u32;
typedef signed int s32;

extern u32 extendedWidthEnabled __asm__("D_8005A820");
extern s32 videoWidth __asm__("D_8005A824");
extern s32 extendedWidth __asm__("D_8005A82C");
extern s32 coordinateOffset __asm__("D_8005A830");
extern u32 coordinateWrapEnabled __asm__("D_8005A834");
extern s32 widthScale __asm__("D_8005A838");
extern u32 videoMode __asm__("D_8005A83C");
extern u32 runtimeMode[20] __asm__("D_8005A840");
extern u32 *activeMode __asm__("D_8005A890");
extern u32 modeTemplate[20] __asm__("D_8005A894");
extern u32 packedCoordinates __asm__("D_8005A8B0");

extern void APPLY_MODE_NAME(u32 *mode);
extern void WRAP_NAME(void);
extern void SET_VALUE_NAME(s32 value);

void LEAF_NAME(void)
{
    u32 index;

    videoWidth = extendedWidthEnabled ? extendedWidth + 320 : 320;
    if (videoWidth < 320) {
        videoWidth = 320;
    }
    if (videoWidth > 640) {
        videoWidth = 640;
    }

    runtimeMode[2] = videoWidth;
    runtimeMode[10] = videoWidth * 2;
    runtimeMode[15] = videoWidth * 2;
    runtimeMode[8] = (videoWidth * widthScale) / 640;
    for (index = 0; index < 20; index++) {
        activeMode[index] = modeTemplate[index];
    }
    APPLY_MODE_NAME(runtimeMode);
    for (index = 0; index < 20; index++) {
        modeTemplate[index] = runtimeMode[index];
    }
    activeMode = runtimeMode;

    if (coordinateOffset != 0) {
        s32 high = (s32)(packedCoordinates >> 16) + coordinateOffset;
        s32 low = (s32)(packedCoordinates & 0xFFFF) + coordinateOffset;
        high %= 65535;
        low %= 65535;
        packedCoordinates = ((u32)high << 16) | (u32)low;
    }
    if (coordinateWrapEnabled != 0) {
        WRAP_NAME();
    }
    SET_VALUE_NAME(videoMode == 1 ? 106 : 90);
}
