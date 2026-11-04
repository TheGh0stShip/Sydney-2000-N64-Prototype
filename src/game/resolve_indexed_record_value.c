#ifndef LEAF_NAME
#define LEAF_NAME resolveIndexedRecordValue
#endif

#ifndef RESOLVE_NAME
#define RESOLVE_NAME resolveRecordIndex
#endif

#ifndef COPY_NAME
#define COPY_NAME copyRecord
#endif

#ifndef RECORDS_NAME
#define RECORDS_NAME records
#endif

#ifndef BUFFER_NAME
#define BUFFER_NAME buffer
#endif

#ifndef BASE_VALUE_NAME
#define BASE_VALUE_NAME baseValue
#endif

typedef signed int s32;
typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *RECORDS_NAME;
extern u8 BUFFER_NAME[76];
extern u32 BASE_VALUE_NAME;
extern s32 RESOLVE_NAME(void *first, void *second, u32 mode);
extern void COPY_NAME(void *source, void *destination, u32 length);

u32 LEAF_NAME(void *first, void *second) {
    register s32 index __asm__("$3");
    register u32 result __asm__("$2");

    index = RESOLVE_NAME(first, second, 0);
    __asm__("" : "=r"(index) : "0"(index));
    if (index != -1) {
        register u8 *bufferPointer __asm__("$16") = BUFFER_NAME;
        register u32 offset __asm__("$4") = (u32)index * 76;
        register u8 *source __asm__("$2") = RECORDS_NAME + 4;
        register u8 *destination __asm__("$5") = bufferPointer;
        register u32 length __asm__("$6") = 76;
        register u32 baseWord __asm__("$3");

        __asm__("" : "=r"(bufferPointer), "=r"(offset), "=r"(source),
                "=r"(destination), "=r"(length)
                : "0"(bufferPointer), "1"(offset), "2"(source),
                "3"(destination), "4"(length));
        COPY_NAME(source + offset, destination, length);
        baseWord = BASE_VALUE_NAME;
        __asm__("" : "=r"(baseWord) : "0"(baseWord));
        result = baseWord + *(u32 *)(bufferPointer + 4);
    } else {
        result = 0;
    }
    return result;
}
