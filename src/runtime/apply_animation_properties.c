/* func_800B40D8: selectively apply flagged object properties. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct { float x, y, z; } PropertyVector;
typedef struct { unsigned char pad[0x40]; PropertyVector position; } PropertyTransform;
typedef struct {
    unsigned char head[0xBC];
    u32 special, state;
    u16 flags, reserved;
    float advance;
    unsigned char gapCC[0x1C];
    u32 expiry;
    unsigned char gapEC[8];
    float f4, f8, fc;
    unsigned char gap100[0x24];
    u32 child[1];
} PropertyObject;
typedef struct {
    u32 flags;
    PropertyVector position;
    unsigned char gap10[0x1C];
    u32 childParameter;
    unsigned char gap30[0x1C];
    u32 delay;
    float advance;
    u32 reserved;
    float f58, f5c, f60;
    u16 objectFlags;
} ObjectProperties;
typedef char property_word_width[sizeof(u32) == 4 ? 1 : -1];
typedef char property_pointer_width[sizeof(void *) == 4 ? 1 : -1];
typedef char property_child_offset[(unsigned long)&((PropertyObject *)0)->child == 0x124 ? 1 : -1];
typedef char property_flags_offset[(unsigned long)&((ObjectProperties *)0)->objectFlags == 0x64 ? 1 : -1];
extern u32 runtimePropertyClock;
extern void func_800AEB68(void *, u32);
extern void func_800B4B40(void *, void *, float);
void func_800B40D8(PropertyObject *object, ObjectProperties *input) {
    if (input->flags & 1) {
        PropertyTransform *transform = (PropertyTransform *)((unsigned char *)object + 0x14);
        PropertyVector *position = &input->position;
        transform->position.x = position->x;
        transform->position.y = position->y;
        transform->position.z = position->z;
    }
    if (input->flags & 0x20) {
        if (!input->delay) object->special = 0;
        object->expiry = runtimePropertyClock + input->delay;
    }
    if (input->flags & 0x400) object->flags = input->objectFlags;
    if (input->flags & 0x800) object->fc = input->f60;
    if (input->flags & 0x200) object->f4 = input->f5c;
    if (input->flags & 0x100) object->f8 = input->f58;
}
