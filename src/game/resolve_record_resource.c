#ifndef LEAF_NAME
#define LEAF_NAME resolveRecordResource
#endif

#ifndef INITIALIZE_NAME
#define INITIALIZE_NAME initializeRecordQuery
#endif

#ifndef RESOLVE_NAME
#define RESOLVE_NAME resolveRecordIndex
#endif

#ifndef COPY_NAME
#define COPY_NAME copyRecord
#endif

#ifndef CLEAR_NAME
#define CLEAR_NAME clearRecordQuery
#endif

#ifndef RECORDS_NAME
#define RECORDS_NAME records
#endif

#ifndef BUFFER_NAME
#define BUFFER_NAME recordBuffer
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
extern void *INITIALIZE_NAME(void *query);
extern s32 RESOLVE_NAME(void *query, const void *record, u32 length);
extern void COPY_NAME(void *source, void *destination, u32 length);
extern void CLEAR_NAME(void *query, s32 *index);

u32 LEAF_NAME(const void *record, u32 *output) {
    u32 query;
    s32 index;
    u32 result = 0;

    INITIALIZE_NAME(&query);
    index = RESOLVE_NAME(&query, record, 16);
    if (index >= 0) {
        COPY_NAME(RECORDS_NAME + 4 + index * 76, BUFFER_NAME, 76);
        result = BASE_VALUE_NAME + *(u32 *)(BUFFER_NAME + 4);
        *output = *(u32 *)BUFFER_NAME;
    }
    CLEAR_NAME(&query, &index);
    return result;
}
