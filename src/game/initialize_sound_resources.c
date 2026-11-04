#ifndef LEAF_NAME
#define LEAF_NAME initializeSoundResources
#endif

#ifndef INITIALIZE_LOOKUP_NAME
#define INITIALIZE_LOOKUP_NAME initializeLookup
#endif

#ifndef LOAD_NAME
#define LOAD_NAME loadResource
#endif

#ifndef FIND_NAME
#define FIND_NAME findResource
#endif

#ifndef GET_NAME
#define GET_NAME getResource
#endif

#ifndef PREPARE_NAME
#define PREPARE_NAME prepareSoundBank
#endif

#ifndef LINK_NAME
#define LINK_NAME linkSoundBanks
#endif

#ifndef READ_NAME
#define READ_NAME readSoundBankValue
#endif

#ifndef SET_NAME
#define SET_NAME setSoundBankValue
#endif

#ifndef CLEANUP_LOOKUP_NAME
#define CLEANUP_LOOKUP_NAME cleanupLookup
#endif

#ifndef CLEAR_NAME
#define CLEAR_NAME clearMemory
#endif

#ifndef RATE_NAME
#define RATE_NAME configureOutputRate
#endif

#ifndef STREAM_NAME
#define STREAM_NAME initializeStreams
#endif

typedef unsigned int u32;
typedef struct ResourceLookup {
    u32 word;
} ResourceLookup;

extern char soundPointerPath[] __asm__("D_80001328");
extern char soundEffectPath[] __asm__("D_8000133C");
extern char soundWavePath[] __asm__("D_80001350");
extern int soundBankValue __asm__("D_80064F5C");
extern unsigned char audioRecords[] __asm__("D_8006B2B0");
extern unsigned char audioPage[] __asm__("D_80060000");
extern unsigned char memoryContext[] __asm__("commandContext");

extern void INITIALIZE_LOOKUP_NAME(ResourceLookup *lookup);
extern void LOAD_NAME(char *path, void **result, void *memory, int mode);
extern int FIND_NAME(ResourceLookup *lookup, char *path, int length);
extern void *GET_NAME(ResourceLookup *lookup, int index);
extern void PREPARE_NAME(void *bank);
extern void LINK_NAME(void *pointerBank, void *waveBank);
extern int READ_NAME(void *bank);
extern void SET_NAME(void *bank);
extern void CLEANUP_LOOKUP_NAME(ResourceLookup *lookup, int *index);
extern void CLEAR_NAME(void *destination, int value, int size);
extern int RATE_NAME(int rate);
extern int STREAM_NAME(int count, int argument, int unused, void *callback);

void LEAF_NAME(void)
{
    ResourceLookup lookup;
    int index;
    register ResourceLookup *lookupAddress __asm__("$19") = &lookup;

    INITIALIZE_LOOKUP_NAME(lookupAddress);
    {
        register unsigned char *pointerPage __asm__("$18") = audioPage;
        register unsigned char *effectPage __asm__("$17") = audioPage;
        void **pointerAddress = (void **)(pointerPage + 0x4F50);
        void **effectAddress = (void **)(effectPage + 0x4F54);

        *pointerAddress = 0;
        *effectAddress = 0;
        {
            register unsigned char *context __asm__("$16") = memoryContext;
            LOAD_NAME(soundPointerPath, pointerAddress, context, 1);
            LOAD_NAME(soundEffectPath, effectAddress, context, 1);
        }
        index = FIND_NAME(lookupAddress, soundWavePath, 16);
        {
            register unsigned char *wavePage __asm__("$16") = audioPage;
            void **waveAddress = (void **)(wavePage + 0x4F58);
            *waveAddress = GET_NAME(lookupAddress, index);
            PREPARE_NAME(*effectAddress);
            LINK_NAME(*pointerAddress, *waveAddress);
            soundBankValue = READ_NAME(*effectAddress);
            SET_NAME(*effectAddress);
        }
    }
    CLEANUP_LOOKUP_NAME(lookupAddress, &index);

    {
        register int record __asm__("$18");
        register unsigned char *recordAddress __asm__("$16") = audioRecords;
        for (record = 0; record < 20; record++) {
            CLEAR_NAME(recordAddress, 0, 64);
            recordAddress += 64;
        }
    }
    STREAM_NAME(1, RATE_NAME(44100), 0, 0);
}
