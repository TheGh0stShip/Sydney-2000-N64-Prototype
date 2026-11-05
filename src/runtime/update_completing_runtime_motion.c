/* func_800B4FC8: event-driven runtime object update. N64 o32 layout. */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef struct {
    unsigned char base[0x10];
    u32 time;
    unsigned char gap14[0xB0];
    u16 flags;
    u16 reserved;
    float advanceParameter;
    unsigned char gapCC[0x40];
    u32 active;
    unsigned char gap110[0x14];
    u32 child[1];
    u32 childState;
} ExtendedUpdateObject;
typedef struct { s32 kind; u32 time; } RuntimeUpdateEvent;
typedef char check_update_pointer[sizeof(void *) == 4 ? 1 : -1];
typedef char check_update_child[(unsigned long)&((ExtendedUpdateObject *)0)->child == 0x124 ? 1 : -1];
extern int func_800AE9DC(void *,float,void *);
extern void func_800AE17C(void *);
extern void func_800AE1EC(void *, u32);
extern void func_800ADFAC(void *);
extern void func_800AE304(void *);
void func_800B4FC8(ExtendedUpdateObject *object, RuntimeUpdateEvent *event) {
    s32 delta = (s32)(event->time - object->time) >> 8;
    switch (event->kind) {
    case 3:
        break;
    case 5:
        if (delta == 0) return;
        func_800AE1EC(object, event->time);
        if(func_800AE9DC(object->child,object->advanceParameter,object)) func_800AE17C(object);
        break;
    }
    object->time = event->time;
    if (object->childState == 0) {
        if (object->active) func_800ADFAC(object);
        if (object->flags & 1) func_800AE304(object);
    }
}
