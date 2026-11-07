typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *D_800FC270;
extern void func_800DE670(int, u32);
typedef struct { u16 a[4]; int v; float f; u8 pad[80]; } Rec;
typedef struct { u8 pad[3676]; Rec r[13]; } Big;
void func_800DE9F0(int a0, u32 idx, int val, float f, u16 *src)
{
    u8 i;
    if (idx < 13) {
        i = 0;
        ((Big *)D_800FC270)->r[idx].v = val;
        ((Big *)D_800FC270)->r[idx].f = f;
        for (; i < 4; i++) {
            ((Big *)D_800FC270)->r[idx].a[i] = src[i];
        }
        func_800DE670(a0, idx);
    }
}
