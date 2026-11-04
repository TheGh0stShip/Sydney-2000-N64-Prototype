#ifndef LEAF_NAME
#define LEAF_NAME loadNumberedSoundResource
#endif

#ifndef FORMAT_NAME
#define FORMAT_NAME formatString
#endif

#ifndef STOP_NAME
#define STOP_NAME stopMusic
#endif

#ifndef POLL_NAME
#define POLL_NAME pollChannel
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

extern char soundName0[] __asm__("D_80001100");
extern char soundName1[] __asm__("D_80001110");
extern char soundName2[] __asm__("D_8000111C");
extern char soundName3[] __asm__("D_80001128");
extern char soundName4[] __asm__("D_80001134");
extern char soundName5[] __asm__("D_80001140");
extern char soundName6[] __asm__("D_8000114C");
extern char soundName7[] __asm__("D_80001158");
extern char soundName8[] __asm__("D_80001164");
extern char soundName9[] __asm__("D_80001170");
extern char soundName10[] __asm__("D_80001178");
extern char soundName11[] __asm__("D_80001184");
extern char soundName12[] __asm__("D_80001190");
extern char soundName13[] __asm__("D_8000119C");
extern char soundName14[] __asm__("D_800011A8");
extern char soundName15[] __asm__("D_800011B4");
extern char soundName16[] __asm__("D_800011C0");
extern char soundName17[] __asm__("D_800011CC");
extern char soundName18[] __asm__("D_800011D8");
extern char soundName19[] __asm__("D_800011E4");
extern char soundName20[] __asm__("D_800011F0");
extern char soundName21[] __asm__("D_80001200");
extern char soundName22[] __asm__("D_8000120C");
extern char soundName23[] __asm__("D_8000121C");
extern char soundName24[] __asm__("D_80001228");
extern char soundName25[] __asm__("D_80001238");
extern char soundName26[] __asm__("D_80001248");
extern char soundName27[] __asm__("D_80001254");
extern char soundName28[] __asm__("D_80001264");
extern char soundName29[] __asm__("D_80001270");
extern char soundName30[] __asm__("D_8000127C");
extern char soundName31[] __asm__("D_8000128C");
extern char soundPathFormat[] __asm__("D_80001294");
extern unsigned char memoryContext[] __asm__("D_800F2758");
extern void *soundResource __asm__("D_80064F9C");
extern s32 audioConfiguration[];
extern s32 musicEnabled __asm__("D_80064F98");
extern s32 transitionEnabled __asm__("D_80064F7C");
extern s32 transitionLimit __asm__("D_80064F80");

extern void FORMAT_NAME(char *output, char *format, ...);
extern void STOP_NAME(int channel, int value);
extern int POLL_NAME(int channel);
extern void RELEASE_NAME(void *context, void **resource);
extern void LOAD_NAME(char *path, void **resource, void *context, int mode);
extern void VOLUME_NAME(int channel, int value);
extern void START_NAME(int enabled);

/* Selects one of 32 named sound banks, loads it into the shared audio slot, and starts playback. */
void LEAF_NAME(unsigned int index)
{
    char name[256];
    char path[256];

    switch (index) {
    case 0:
        FORMAT_NAME(name, soundName0);
        break;
    case 1:
        FORMAT_NAME(name, soundName1);
        break;
    case 2:
        FORMAT_NAME(name, soundName2);
        break;
    case 3:
        FORMAT_NAME(name, soundName3);
        break;
    case 4:
        FORMAT_NAME(name, soundName4);
        break;
    case 5:
        FORMAT_NAME(name, soundName5);
        break;
    case 6:
        FORMAT_NAME(name, soundName6);
        break;
    case 7:
        FORMAT_NAME(name, soundName7);
        break;
    case 8:
        FORMAT_NAME(name, soundName8);
        break;
    case 9:
        FORMAT_NAME(name, soundName9);
        break;
    case 10:
        FORMAT_NAME(name, soundName10);
        break;
    case 11:
        FORMAT_NAME(name, soundName11);
        break;
    case 12:
        FORMAT_NAME(name, soundName12);
        break;
    case 13:
        FORMAT_NAME(name, soundName13);
        break;
    case 14:
        FORMAT_NAME(name, soundName14);
        break;
    case 15:
        FORMAT_NAME(name, soundName15);
        break;
    case 16:
        FORMAT_NAME(name, soundName16);
        break;
    case 17:
        FORMAT_NAME(name, soundName17);
        break;
    case 18:
        FORMAT_NAME(name, soundName18);
        break;
    case 19:
        FORMAT_NAME(name, soundName19);
        break;
    case 20:
        FORMAT_NAME(name, soundName20);
        break;
    case 21:
        FORMAT_NAME(name, soundName21);
        break;
    case 22:
        FORMAT_NAME(name, soundName22);
        break;
    case 23:
        FORMAT_NAME(name, soundName23);
        break;
    case 24:
        FORMAT_NAME(name, soundName24);
        break;
    case 25:
        FORMAT_NAME(name, soundName25);
        break;
    case 26:
        FORMAT_NAME(name, soundName26);
        break;
    case 27:
        FORMAT_NAME(name, soundName27);
        break;
    case 28:
        FORMAT_NAME(name, soundName28);
        break;
    case 29:
        FORMAT_NAME(name, soundName29);
        break;
    case 30:
        FORMAT_NAME(name, soundName30);
        break;
    case 31:
        FORMAT_NAME(name, soundName31);
        break;
    }
    FORMAT_NAME(path, soundPathFormat, name);
    STOP_NAME(2, 0);
    while (POLL_NAME(2) != 0) {
    }
    {
        register void **slot __asm__("$16") = &soundResource;

        if (*slot != 0) {
            RELEASE_NAME(memoryContext, slot);
        }
        LOAD_NAME(path, slot, memoryContext, 1);
    }
    VOLUME_NAME(2, 30000);
    START_NAME(1);
    transitionEnabled = 1;
    musicEnabled = 1;
    transitionLimit = audioConfiguration[27];
}
