/* func_800B3E88: initialize animation state after the base constructor. */
typedef unsigned int u32;
typedef struct {
    unsigned char base[0xC0];
    u32 state;
    unsigned char gapC4[0x28];
    u32 pending, mode;
    unsigned char gapF4[0x84];
    u32 active;
    unsigned char gap17C[0x20];
    float scale;
} RuntimeAnimationState;
typedef char animation_pointer_width[sizeof(void *) == 4 ? 1 : -1];
typedef char animation_scale_offset[(unsigned long)&((RuntimeAnimationState *)0)->scale == 0x19C ? 1 : -1];
extern void func_800AE4FC(void *);
void func_800B3E88(RuntimeAnimationState *object) {
    func_800AE4FC(object);
    object->pending = 0;
    object->mode = 2;
    object->active = 0;
    object->state = 0;
    object->scale = 1.0f;
}
