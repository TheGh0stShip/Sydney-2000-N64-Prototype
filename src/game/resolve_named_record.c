#ifndef LEAF_NAME
#define LEAF_NAME resolveNamedRecord
#endif

#ifndef INITIALIZE_NAME
#define INITIALIZE_NAME initializeQuery
#endif

#ifndef COPY_NAME
#define COPY_NAME copyString
#endif

#ifndef RESOLVE_NAME
#define RESOLVE_NAME resolveRecord
#endif

typedef signed int s32;
typedef unsigned char u8;
typedef unsigned int u32;

#ifdef CHECK_NAME
extern s32 CHECK_NAME(void *query, const u8 *name);
extern u32 BUSY_NAME;
#endif

extern void *INITIALIZE_NAME(void *query);
extern u8 *COPY_NAME(u8 *destination, const u8 *source);
extern u32 RESOLVE_NAME(void *query, const u8 *name);

s32 LEAF_NAME(const u8 *name, u32 *output) {
    u8 nameBuffer[256];
    u32 query[2];
    u32 result;

    *(u32 *)0x80043714 = 1;
    INITIALIZE_NAME(query);
    COPY_NAME(nameBuffer, name);
#ifdef CHECK_NAME
    if (BUSY_NAME != 0 || CHECK_NAME(query, nameBuffer) == 1) {
        return -1;
    }
#endif
    result = RESOLVE_NAME(query, nameBuffer);
    if (result != 0) {
        *output = result;
        *(u32 *)0x80043714 = 0;
        return 0;
    }
    return -1;
}
