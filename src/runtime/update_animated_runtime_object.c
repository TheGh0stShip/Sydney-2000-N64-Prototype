/* func_800B3C34: event-driven runtime object update. N64 o32 layout. */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef struct {
    unsigned char base[0x10];
    u32 time;
    unsigned char gap14[0xB0];
    u16 flags;
    u16 reserved;
    u32 advanceParameter;
    unsigned char gapCC[0x40];
    u32 active;
    unsigned char gap110[0x14];
    u32 child[1];
    u32 childState; unsigned char gap12C[0x4C]; int animation; unsigned char gap17C[0x20]; float phase;
} ExtendedUpdateObject;
typedef struct { s32 kind; u32 time; } RuntimeUpdateEvent;
typedef char check_update_pointer[sizeof(void *) == 4 ? 1 : -1];
typedef char check_update_child[(unsigned long)&((ExtendedUpdateObject *)0)->child == 0x124 ? 1 : -1];
extern void func_800B4B40(void *, void *, u32);
extern void func_800AE1EC(void *, u32);
extern void func_800ADFAC(void *);
extern void func_800AE304(void *);
extern void func_800B3ECC(void *);
extern void func_800B48CC(void *,int,int);
void func_800B4014(ExtendedUpdateObject *object, RuntimeUpdateEvent *event) {
    switch (event->kind) {
    case 3:
        break;
    case 5:
        if (object->phase < 1.0f) func_800B3ECC(object);
        else func_800B48CC(object,object->animation,0);
        func_800AE1EC(object, event->time);
        break;
    }
    object->time = event->time;
    if (object->childState == 0) {
        if (object->active) func_800ADFAC(object);
        if (object->flags & 1) func_800AE304(object);
    }
}
