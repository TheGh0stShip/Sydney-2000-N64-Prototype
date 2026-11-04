#ifndef LEAF_NAME
#define LEAF_NAME loadIndexedMusicResource
#endif
#ifndef PREPARE_NAME
#define PREPARE_NAME prepareRuntime
#endif
#ifndef FORMAT_NAME
#define FORMAT_NAME formatString
#endif
#ifndef STOP_NAME
#define STOP_NAME stopMusic
#endif
#ifndef POLL_NAME
#define POLL_NAME pollMusic
#endif
#ifndef RELEASE_NAME
#define RELEASE_NAME releaseResource
#endif
#ifndef LOAD_NAME
#define LOAD_NAME loadResource
#endif
#ifndef VOLUME_NAME
#define VOLUME_NAME setVolume
#endif
#ifndef START_NAME
#define START_NAME startMusic
#endif

typedef signed int s32;

extern char musicPathFormat[] __asm__("D_800010F0");
extern unsigned char memoryContext[] __asm__("commandContext");
extern unsigned char audioPage[] __asm__("D_80060000");
extern volatile s32 audioConfiguration[];
extern char *musicNames[] __asm__("D_80064FA0");
extern s32 initialMusicEnabled __asm__("D_80064F94");
extern s32 musicEnabled __asm__("D_80064F98");
extern s32 transitionEnabled __asm__("D_80064F7C");
extern s32 transitionLimit __asm__("D_80064F80");
extern s32 transitionFirstActive __asm__("D_80064F60");
extern s32 transitionFirstMode __asm__("D_80064F6C");
extern s32 transitionSecondMode __asm__("D_80064F70");
extern s32 transitionTarget __asm__("D_80064F74");
extern s32 transitionCurrent __asm__("D_80064F78");

extern void PREPARE_NAME(void);
extern void FORMAT_NAME(char *output, char *format, ...);
extern void STOP_NAME(int channel, int value);
extern int POLL_NAME(int channel);
extern void RELEASE_NAME(void *context, void **resource);
extern void LOAD_NAME(char *path, void **resource, void *context, int mode);
extern void VOLUME_NAME(int channel, int value);
extern void START_NAME(int enabled);

void LEAF_NAME(s32 index)
{
    char path[256];
    register int current __asm__("$17");
    int limit;

    if (index == 0) {
        initialMusicEnabled = 1;
    }
    PREPARE_NAME();
    FORMAT_NAME(path, musicPathFormat, musicNames[index]);
    STOP_NAME(2, 0);
    do {
        current = POLL_NAME(2);
    } while (current != 0);

    {
        register unsigned char *resourcePage __asm__("$16") = audioPage;
        register void **resourceAddress __asm__("$18") =
            (void **)(resourcePage + 0x4F9C);
        if (*resourceAddress != 0) {
            RELEASE_NAME(memoryContext, resourceAddress);
        }
        LOAD_NAME(path, resourceAddress, memoryContext, 1);
        if (*resourceAddress == 0) {
            return;
        }
    }

    (void)audioConfiguration[27];
    VOLUME_NAME(2, 0);
    START_NAME(1);
    {
        register int one __asm__("$5") = 1;

        transitionLimit = audioConfiguration[27];
        limit = audioConfiguration[27];
        musicEnabled = one;
        transitionEnabled = one;
        if (limit < 0) {
            limit = audioConfiguration[27];
        }
        if (current < limit) {
            transitionFirstActive = one;
            transitionFirstMode = one;
            transitionTarget = one;
            transitionCurrent = limit;
        } else {
            transitionFirstActive = one;
            transitionSecondMode = one;
            transitionCurrent = 0;
            transitionTarget = audioConfiguration[27];
        }
    }
}
