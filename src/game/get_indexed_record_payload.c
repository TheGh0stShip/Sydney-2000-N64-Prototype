#ifndef LEAF_NAME
#define LEAF_NAME getIndexedRecordPayload
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
extern void COPY_NAME(void *source, void *destination, u32 length);

u32 LEAF_NAME(void *unused, s32 index) {
    u32 payload[4];

    if (index == -1) {
        return 0;
    }

    COPY_NAME(RECORDS_NAME + 4 + index * 76, BUFFER_NAME, 76);
    COPY_NAME((u8 *)BASE_VALUE_NAME + *(u32 *)(BUFFER_NAME + 4), payload, 16);
    if (payload[0] == 0x30325447) {
        return payload[1];
    }
    return *(u32 *)BUFFER_NAME;
}
