/* Runtime-stage C reconstruction: store the output mode, then copy it to every type-0x3D child. */
typedef unsigned char u8; typedef unsigned int u32;
typedef struct RuntimeNode RuntimeNode;
struct RuntimeNode { u32 type; RuntimeNode *parent, *firstChild, *next; u8 unused10[0xBB]; u8 mode; };
extern u8 runtimeOutputMode;

void func_800B32D4(RuntimeNode *object, u8 mode) {
    RuntimeNode *child = object->firstChild;
    RuntimeNode *next;

    runtimeOutputMode = mode;
    for (;;) {
        if (child == 0) return;
        next = child->next;
        if (child->type == 0x3D) child->mode = runtimeOutputMode;
        child = next;
    }
}
