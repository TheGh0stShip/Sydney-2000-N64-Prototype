#ifndef LEAF_NAME
#define LEAF_NAME initializeObjectReference
#endif

#ifndef CREATE_NAME
#define CREATE_NAME createObject
#endif

#ifndef ACTIVE_NAME
#define ACTIVE_NAME active
#endif

#ifndef GLOBAL_OBJECT_NAME
#define GLOBAL_OBJECT_NAME globalObject
#endif

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Object {
    u8 padding[0x80];
    u32 flags;
} Object;

extern u32 ACTIVE_NAME;
extern Object GLOBAL_OBJECT_NAME;
extern void CREATE_NAME(Object **object);

u32 LEAF_NAME(Object **object, u32 identifier) {
    if (ACTIVE_NAME != 0) {
        *object = &GLOBAL_OBJECT_NAME;
    } else if ((identifier & 0xFFFFU) == 0xFFFFU) {
        CREATE_NAME(object);
        (*object)->flags |= 8;
    } else {
        for (;;) {
        }
    }
    return 0;
}
