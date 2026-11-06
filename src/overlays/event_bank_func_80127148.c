typedef unsigned char u8;
typedef int s32;
typedef float f32;

extern void func_8009CB40(u8 *sub, f32 scale, s32 n, s32 id, s32 v);

void func_80127148(u8 *obj, s32 on)
{
    u8 *owner = *(u8 **)(obj + 4);
    s32 n;
    s32 flag;

    n = 120;
    if (on == 0)
        n = 0;
    flag = 0;
    if (owner[1556] == 2 || owner[1556] == 4)
        flag = 1;
    if (flag)
        n = 120;
    func_8009CB40(obj + 2076, 0.5f, n, obj[743], *(s32 *)(owner + 248));
    *(f32 *)(obj + 4868) = *(f32 *)0x8008143C;
}
