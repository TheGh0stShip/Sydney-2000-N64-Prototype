#ifndef LEAF_NAME
#define LEAF_NAME runObjectUpdatePasses
#endif

#ifndef FIRST_UPDATE_NAME
#define FIRST_UPDATE_NAME runFirstUpdate
#endif

#ifndef SECOND_UPDATE_NAME
#define SECOND_UPDATE_NAME runSecondUpdate
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Object {
    u8 padding00[0x20];
    u32 state;
    u8 padding24[0x46];
    u16 selection;
} Object;

extern void FIRST_UPDATE_NAME(Object *object);
extern void SECOND_UPDATE_NAME(Object *object, u32 argument);

void LEAF_NAME(Object *object) {
    register u8 *modeBase __asm__("$17") = (u8 *)0x80060000;
    register u32 savedMode __asm__("$19");
    register u16 savedSelection __asm__("$18");

    __asm__("" : "=r"(modeBase) : "0"(modeBase));
    savedMode = *(u32 *)(modeBase - 0x56C4);
    savedSelection = object->selection;
    object->selection = *(u16 *)((u8 *)object + 0x22);
    *(u32 *)(modeBase - 0x56C4) = 0;
    FIRST_UPDATE_NAME(object);
    SECOND_UPDATE_NAME(object, 1);
    *(u32 *)(modeBase - 0x56C4) = 1;
    FIRST_UPDATE_NAME(object);
    SECOND_UPDATE_NAME(object, 1);
    object->selection = savedSelection;
    object->state = 0;
    *(u32 *)(modeBase - 0x56C4) = savedMode;
}
