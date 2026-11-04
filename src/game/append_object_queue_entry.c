#ifndef LEAF_NAME
#define LEAF_NAME appendObjectQueueEntry
#endif

#ifndef COUNT_NAME
#define COUNT_NAME entryCount
#endif

#ifndef ENTRIES_NAME
#define ENTRIES_NAME entries
#endif

#ifndef MAXIMUM_NAME
#define MAXIMUM_NAME maximumValue
#endif

typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Object {
    u8 padding00[0x54];
    float x;
    float y;
    u8 padding5C[0x6D];
    u8 value;
} Object;

typedef struct QueueEntry {
    Object *object;
    s16 x;
    s16 y;
} QueueEntry;

extern u32 COUNT_NAME;
extern QueueEntry ENTRIES_NAME[512];
extern u32 MAXIMUM_NAME;

void LEAF_NAME(Object *object) {
    register Object *objectPointer __asm__("$4") = object;
    register u8 *countBase __asm__("$6") = (u8 *)0x80060000;
    register u32 index __asm__("$5");

    __asm__("" : "=r"(countBase) : "0"(countBase));
    index = *(u32 *)(countBase + 0x24C4);
    __asm__("" : "=r"(index) : "0"(index));

    if (index < 512) {
        register u8 *entriesBase __asm__("$2") = (u8 *)0x80060000;
        register QueueEntry *entry __asm__("$3");
        float x;
        float y;

        __asm__("" : "=r"(entriesBase) : "0"(entriesBase));
        entriesBase += 0x2500;
        entry = (QueueEntry *)(index * 8 + entriesBase);
        __asm__("" : "=r"(entry) : "0"(entry));
        x = objectPointer->x;
        y = objectPointer->y;
        entry->object = objectPointer;
        entry->x = (s32)x * 4;
        entry->y = (s32)y * 4;
        {
            register u8 *maximumBase __asm__("$3") = (u8 *)0x80060000;
            u32 value = objectPointer->value;

            __asm__("" : "=r"(maximumBase) : "0"(maximumBase));
            if ((s32)*(u32 *)(maximumBase + 0x24C8) < (s32)value) {
                *(u32 *)(maximumBase + 0x24C8) = value;
            }
        }
        {
            register u32 nextIndex __asm__("$2") = index + 1;

            __asm__("" : "=r"(nextIndex) : "0"(nextIndex));
            *(u32 *)(countBase + 0x24C4) = nextIndex;
        }
    }
}
