#ifndef LEAF_NAME
#define LEAF_NAME updateRuntimeRenderResource
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct DisplayCommand {
    u32 word0;
    u32 word1;
} DisplayCommand;

typedef struct RenderResource {
    u32 flags;
    u8 pad04[0x10];
    void *displayData;
    u8 pad18[0x10];
    u32 state;
    u8 pad2C[0x30];
    DisplayCommand *firstCommand;
    DisplayCommand *secondCommand;
} RenderResource;

typedef struct ResourceCollection {
    u16 count;
    u8 pad02[0x16];
    void *displayData;
} ResourceCollection;

typedef struct RuntimeRenderObject {
    u32 kind;
    u8 pad04[0xBC];
    u32 flags;
    void *resource;
} RuntimeRenderObject;

extern int func_80018838(int *object);
extern void func_80008F3C(ResourceCollection *collection, u32 index,
                          void *displayData, u32 mode);

void LEAF_NAME(RuntimeRenderObject *object, void *displayData)
{
    ResourceCollection *collection;
    RenderResource *resource;
    u32 index;

    if (object == 0 || object->resource == 0 || (object->flags & 0x20000)) {
        return;
    }

    if (func_80018838((int *)object)) {
        collection = object->resource;
        if (collection->count != 0) {
            index = 0;
            do {
                func_80008F3C(collection, index, displayData, 0);
                index++;
            } while (index < collection->count);
        }
        collection->displayData = displayData;
        return;
    }

    resource = object->resource;
    if ((u32)resource <= 0xFFFE) {
        return;
    }

    if (resource->flags & 1) {
        if (resource->state & 2) {
            return;
        }
        resource->displayData = displayData;
        if (displayData != 0) {
            resource->flags |= 0x20;
        } else {
            resource->flags &= ~0x20;
        }
    } else if (resource->flags & 2) {
        resource->displayData = displayData;
        if (resource->firstCommand != 0) {
            resource->firstCommand->word0 = 0xDE000000;
            resource->firstCommand->word1 = (u32)displayData;
        }
        if (resource->secondCommand != 0) {
            resource->secondCommand->word0 = 0xDE000000;
            resource->secondCommand->word1 = (u32)displayData;
        }
        resource->flags |= 0x20;
    }
}
