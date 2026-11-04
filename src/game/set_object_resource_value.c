#ifndef LEAF_NAME
#define LEAF_NAME setObjectResourceValue
#endif

#ifndef RESOLVE_NAME
#define RESOLVE_NAME resolveResourceValue
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 flags;
    u8 padding04[0x6C];
    u16 resourceValue;
    u8 padding72[4];
    u16 state;
} ResourceObject;

extern int RESOLVE_NAME(u16 value, int arg1, int arg2, int arg3, int arg4);

int LEAF_NAME(ResourceObject *object, int unused, int value) {
    register int resourceArgument __asm__("$4");
    register int zeroArgument __asm__("$5");

    (void)unused;
    resourceArgument = value;
    if (object->flags & 2) {
        object->resourceValue = value;
    } else {
        resourceArgument = (u16)resourceArgument;
        zeroArgument = 0;
        __asm__("" : "=r"(zeroArgument) : "0"(zeroArgument));
        object->resourceValue = RESOLVE_NAME(
            resourceArgument,
            zeroArgument,
            zeroArgument,
            zeroArgument,
            0
        );
    }
    object->state = 3;
    return 0;
}
