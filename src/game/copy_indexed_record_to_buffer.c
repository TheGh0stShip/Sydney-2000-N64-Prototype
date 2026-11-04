#ifndef LEAF_NAME
#define LEAF_NAME copyIndexedRecordToBuffer
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

typedef signed int s32;
typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *RECORDS_NAME;
extern u8 BUFFER_NAME[76];
extern void COPY_NAME(void *source, void *destination, u32 length);

u32 LEAF_NAME(void *unused, s32 index) {
    register u32 result __asm__("$2") = 0;

    if (index != -1) {
        register u8 *bufferBase __asm__("$16") = (u8 *)0x80040000;
        register u32 offset __asm__("$4") = (u32)index * 76;
        register u8 *sourceBase __asm__("$2") = RECORDS_NAME + 4;
        register u8 *destination __asm__("$5") = bufferBase + 0x36C0;
        register u32 length __asm__("$6") = 76;

        __asm__("" : "=r"(bufferBase), "=r"(offset), "=r"(sourceBase),
                "=r"(destination), "=r"(length)
                : "0"(bufferBase), "1"(offset), "2"(sourceBase),
                "3"(destination), "4"(length));
        COPY_NAME(sourceBase + offset, destination, length);
        result = *(u32 *)(bufferBase + 0x36C0);
    }

    return result;
}
