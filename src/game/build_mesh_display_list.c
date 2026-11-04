#ifndef LEAF_NAME
#define LEAF_NAME buildMeshDisplayList
#endif
#ifndef RELEASE_NAME
#define RELEASE_NAME releaseHandle
#endif
#ifndef ALLOCATE_NAME
#define ALLOCATE_NAME allocateHandle
#endif
#ifndef FIND_NAME
#define FIND_NAME findRenderRecord
#endif
#ifndef TAG_NAME
#define TAG_NAME displayListTag
#endif

typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u32 command;
    u32 value;
} Gfx;

typedef struct {
    u32 flags;
    u8 padding04[0x10];
    Gfx *materialList;
    u8 padding18[0x3C];
    u8 *vertexBuffers[2];
    Gfx *displayLists[2];
    u32 vertexCount;
    u16 busy;
    u16 indexCount;
    u16 *indices;
    u16 recordType;
    u16 padding72[2];
    u16 dirtyMask;
} MeshObject;

typedef struct {
    u32 state;
    u8 padding04[0xC];
    Gfx displayList[26];
} RenderRecord;

extern u32 activeDisplayList __asm__("D_8005A93C");
extern void *memoryContext __asm__("D_8005A9E8");
extern RenderRecord renderRecords[] __asm__("D_80049A28");
extern char TAG_NAME[];
extern void RELEASE_NAME(void *context, void *handle);
extern void ALLOCATE_NAME(void *context, void *output, u32 size, char *tag);
extern u32 FIND_NAME(u16 type, u32 first, u32 second, u32 third, u32 fourth);

s32 LEAF_NAME(MeshObject *object, s32 external)
{
    u16 *indices;
    u16 count;
    u32 size;
    u32 i;
    Gfx *displayList;
    Gfx *gfx;
    u32 index;

    if (object->indices == 0 || object->dirtyMask == 0) {
        return 0;
    }

    object->dirtyMask &= ~(1 << activeDisplayList);
    if (object->displayLists[activeDisplayList] != 0) {
        RELEASE_NAME(memoryContext, &object->displayLists[activeDisplayList]);
    }
    object->displayLists[activeDisplayList] = 0;

    indices = object->indices;
    count = object->indexCount;
    if (object->busy != 0) {
        return -1000;
    }

    if (object->displayLists[activeDisplayList] == 0) {
        if (external != 0) {
            size = (count / 2) * 7 + (count & 1) * 4 + 6;
        } else if (object->vertexCount > 32) {
            size = count * 4 + 5;
        } else {
            size = count / 2 + (count & 1) + 6;
        }
        ALLOCATE_NAME(memoryContext, &object->displayLists[activeDisplayList],
                      size * 8, TAG_NAME);
    }

    displayList = object->displayLists[activeDisplayList];
    if (displayList == 0) {
        return -1000;
    }
    displayList++;

    gfx = displayList++;
    gfx->command = 0xD9FFFFFF;
    gfx->value = 0x00020000;
    gfx = displayList++;
    gfx->command = 0xE7000000;
    gfx->value = 0;

    if (external == 0) {
        if (object->vertexCount > 32) {
            for (i = 0; i < count; i++) {
                u16 first = *indices++;
                u16 second = *indices++;
                u16 third = *indices++;

                displayList[0].command = 0x01001002;
                displayList[0].value =
                    (u32)(object->vertexBuffers[activeDisplayList] + first * 16);
                displayList[1].command = 0x01001004;
                displayList[1].value =
                    (u32)(object->vertexBuffers[activeDisplayList] + second * 16);
                displayList[2].command = 0x01001006;
                displayList[2].value =
                    (u32)(object->vertexBuffers[activeDisplayList] + third * 16);
                displayList[3].command = 0x05040200;
                displayList[3].value = 0;
                displayList += 4;
            }
        } else {
            gfx = displayList++;
            gfx->command = 0x01000000 | (object->vertexCount & 0xFF) << 12 |
                           (object->vertexCount & 0x7F) << 1;
            gfx->value = (u32)object->vertexBuffers[activeDisplayList];

            for (i = 0; i < count / 2; i++) {
                u16 first = *indices++;
                u16 second = *indices++;
                u16 third = *indices++;
                u16 fourth = *indices++;
                u16 fifth = *indices++;
                u16 sixth = *indices++;

                gfx = displayList++;
                gfx->command = 0x06000000 | ((third << 1) & 0xFF) << 16 |
                               ((second << 1) & 0xFF) << 8 |
                               ((first << 1) & 0xFF);
                gfx->value = ((sixth << 1) & 0xFF) << 16 |
                             ((fifth << 1) & 0xFF) << 8 |
                             ((fourth << 1) & 0xFF);
            }

            if (count & 1) {
                u32 first = *indices++;
                u32 second = indices[0];
                u32 third = indices[1];

                gfx = displayList++;
                gfx->value = 0;
                gfx->command = 0x05000000 | ((third << 1) & 0xFF) << 16 |
                               ((second << 1) & 0xFF) << 8 |
                               ((first << 1) & 0xFF);
            }
        }
    }

    if (object->flags & 0x20) {
        gfx = object->displayLists[0];
        if (gfx != 0) {
            gfx->command = 0xDE000000;
            gfx->value = (u32)object->materialList;
        }
        gfx = object->displayLists[1];
        if (gfx != 0) {
            gfx->command = 0xDE000000;
            gfx->value = (u32)object->materialList;
        }
        gfx = displayList++;
        gfx->command = 0xD9FBFFFF;
        gfx->value = 0;
    } else if (object->displayLists[activeDisplayList] != 0) {
        index = FIND_NAME(object->recordType, 0, 0, 0, 0);
        gfx = object->displayLists[activeDisplayList];
        gfx->command = 0xDE000000;
        gfx->value = (u32)renderRecords[index].displayList;
    }

    if (external == 0) {
        displayList->command = 0xDF000000;
        displayList->value = 0;
    }
    return 0;
}
