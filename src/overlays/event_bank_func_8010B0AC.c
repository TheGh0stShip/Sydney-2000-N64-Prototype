typedef int s32;
typedef unsigned char u8;
typedef float f32;
extern void func_800B3870(void *, void *, s32);
extern void func_80017B04(s32, f32);
extern void func_80081E34(s32);
void func_8007B46C(u8 *o)
{
    func_800B3870(o + 20, o + 836, 76);
    *(f32 *)(o + 372) = *(f32 *)(o + 88); *(f32 *)(o + 396) = *(f32 *)(o + 88); func_80017B04(1, *(f32 *)(o + 372) + 0.393204033f);
    func_80081E34(*(s32 *)(o + 916));
}
