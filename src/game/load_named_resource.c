#ifndef LEAF_NAME
#define LEAF_NAME loadNamedResource
#endif
#ifndef INITIALIZE_NAME
#define INITIALIZE_NAME initializeResourceLookup
#endif
#ifndef DECODE_NAME
#define DECODE_NAME decodeResourcePath
#endif
#ifndef COPY_NAME
#define COPY_NAME copyString
#endif
#ifndef FIND_NAME
#define FIND_NAME findResourceRecord
#endif
#ifndef CHECK_NAME
#define CHECK_NAME checkResourceRecord
#endif
#ifndef PAYLOAD_NAME
#define PAYLOAD_NAME getResourcePayload
#endif
#ifndef RECORD_NAME
#define RECORD_NAME getResourceRecord
#endif
#ifndef CLEAR_NAME
#define CLEAR_NAME clearResourceLookup
#endif
#ifndef BUSY_NAME
#define BUSY_NAME resourceLookupBusy
#endif
#ifndef PATH_NAME
#define PATH_NAME resourcePath
#endif
#ifndef RESULT_NAME
#define RESULT_NAME resourceResult
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 state;
    void *first;
    void *second;
    u16 firstValue;
    u16 secondValue;
} ResourceResult;

extern u32 BUSY_NAME;
extern char PATH_NAME[];
extern ResourceResult RESULT_NAME;
extern void INITIALIZE_NAME(void *lookup);
extern void DECODE_NAME(char *output, const char *input);
extern void COPY_NAME(char *output, const char *input);
extern int FIND_NAME(void *lookup, const char *path, u32 limit);
extern int CHECK_NAME(void *lookup, u32 index);
extern void *PAYLOAD_NAME(void *lookup, u32 index);
extern void *RECORD_NAME(void *lookup, u32 index);
extern void CLEAR_NAME(void *lookup, u32 *index);

void LEAF_NAME(const char *name, u32 decode) {
    struct {
        u8 padding[16];
        void *lookup;
        u32 index;
    } local;
    void *result;

    INITIALIZE_NAME(&local.lookup);
    BUSY_NAME = 1;
    if (decode != 0) {
        DECODE_NAME(PATH_NAME, name);
    } else {
        COPY_NAME(PATH_NAME, name);
    }

    local.index = FIND_NAME(&local.lookup, PATH_NAME, 16);
    if ((int)local.index >= 0) {
        if (CHECK_NAME(&local.lookup, local.index) == 1) {
            result = PAYLOAD_NAME(&local.lookup, local.index);
        } else {
            result = RECORD_NAME(&local.lookup, local.index);
        }
        CLEAR_NAME(&local.lookup, &local.index);
        RESULT_NAME.first = result;
        RESULT_NAME.second = result;
        RESULT_NAME.state = 0;
        RESULT_NAME.secondValue = 0;
        RESULT_NAME.firstValue = 0;
        BUSY_NAME = 0;
    }
}
