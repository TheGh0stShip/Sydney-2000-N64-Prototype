/* func_800B4204: initialize motion state and zero its three-component vector. */
typedef unsigned int u32;
typedef struct {
    unsigned char base[0xC0];
    u32 state;
    unsigned char gapC4[0x28];
    u32 pending, mode;
    unsigned char gapF4[0x84];
    float motion[3];
} RuntimeMotionState;
typedef char motion_pointer_width[sizeof(void *) == 4 ? 1 : -1];
typedef char motion_vector_offset[(unsigned long)&((RuntimeMotionState *)0)->motion == 0x178 ? 1 : -1];
extern void func_800AE4FC(void *);
void func_800B4204(RuntimeMotionState *object) {
    float *motion;
    func_800AE4FC(object);
    object->mode = 1;
    motion = object->motion;
    object->pending = 0;
    motion[0] = 0.0f;
    motion[1] = 0.0f;
    motion[2] = 0.0f;
    object->state = 0;
}
