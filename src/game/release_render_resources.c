#ifndef LEAF_NAME
#define LEAF_NAME releaseRenderResources
#endif
#ifndef PREPARE_NAME
#define PREPARE_NAME prepareRenderResources
#endif
#ifndef RELEASE_NAME
#define RELEASE_NAME releaseHandle
#endif
#ifndef FIND_NAME
#define FIND_NAME findRenderRecord
#endif
#ifndef CONTEXT_NAME
#define CONTEXT_NAME memoryContext
#endif
#ifndef RECORDS_NAME
#define RECORDS_NAME renderRecords
#endif

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 flags;
    unsigned char padding04[8];
    void *firstHandle;
    void *secondHandle;
    unsigned char padding14[4];
    void *thirdHandle;
    void *fourthHandle;
    unsigned char padding20[0x30];
    void *fifthHandle;
    void *sixthHandle;
    void *eighthHandle;
    void *seventhHandle;
    void *ninthHandle;
    unsigned char padding64[0xC];
    u16 recordType;
} RenderResource;

typedef struct {
    u32 state;
    unsigned char padding04[0xD4];
    void *handle;
    unsigned char paddingDC[4];
} RenderRecord;

extern unsigned char CONTEXT_NAME;
extern RenderRecord RECORDS_NAME[];
extern void PREPARE_NAME(RenderResource *resource);
extern void RELEASE_NAME(void *context, void **handle);
extern u32 FIND_NAME(u16 type, u32 first, u32 second, u32 third, u32 fourth);

void LEAF_NAME(RenderResource *resource, u32 releaseRecord)
{
    u32 index;
    RenderRecord *record;

    PREPARE_NAME(resource);
    if (resource->flags & 1) {
        RELEASE_NAME(&CONTEXT_NAME, &resource->firstHandle);
        RELEASE_NAME(&CONTEXT_NAME, &resource->secondHandle);
        RELEASE_NAME(&CONTEXT_NAME, &resource->thirdHandle);
        RELEASE_NAME(&CONTEXT_NAME, &resource->fourthHandle);
    } else if (resource->flags & 2) {
        if (releaseRecord != 0) {
            index = FIND_NAME(resource->recordType, 0, 0, 0, 0);
            if (index != 0) {
                record = &RECORDS_NAME[index];
                record->state = 0xFFFE;
                if (record->handle != 0) {
                    RELEASE_NAME(&CONTEXT_NAME, &record->handle);
                }
            }
        }
        if (resource->fifthHandle != 0) {
            RELEASE_NAME(&CONTEXT_NAME, &resource->fifthHandle);
        }
        if (resource->sixthHandle != 0) {
            RELEASE_NAME(&CONTEXT_NAME, &resource->sixthHandle);
        }
        if (resource->seventhHandle != 0) {
            RELEASE_NAME(&CONTEXT_NAME, &resource->seventhHandle);
        }
        if (resource->eighthHandle != 0) {
            RELEASE_NAME(&CONTEXT_NAME, &resource->eighthHandle);
        }
        if (resource->ninthHandle != 0) {
            RELEASE_NAME(&CONTEXT_NAME, &resource->ninthHandle);
        }
    }
}
