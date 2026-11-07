typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;
typedef struct { u8 pad[3344]; f32 f3344; } G;
extern G *D_800FC270;
extern u32 D_800779C0[];
extern u8 D_80077914[];
extern u8 D_8007793C[];
extern u8 D_80077964[];
extern u8 D_8007798C[];
extern void func_800D33A0(u8 *, void *, s32, s32);
typedef struct { u8 pad[23492]; u8 a[9]; u8 b[9]; } O;
void func_80075AE8(u8 *o)
{
    u8 s = 0;
    u8 t = 0;
    u8 i;
    for (i = 0; i < o[23416] + 1; i++) {
        s += ((O *)o)->a[i];
        t += ((O *)o)->b[i];
    }
    if (o[23416] == 7) {
        o[23500] = s;
        o[23509] = t;
    }
    if (o[23423] == 3) {
        if (o[23492] == 128) {
            D_800779C0[0] = t;
            func_800D33A0(o + 12020, D_80077914, 1, -1);
        } else {
            D_800779C0[0] = s;
            D_800779C0[1] = t;
            func_800D33A0(o + 12020, D_8007793C, 1, -1);
        }
    } else if (o[23492] == 128) {
        D_800779C0[0] = D_800FC270->f3344;
        D_800779C0[1] = t;
        func_800D33A0(o + 12020, D_80077964, 1, -1);
    } else {
        D_800779C0[0] = D_800FC270->f3344;
        D_800779C0[1] = s;
        D_800779C0[2] = t;
        func_800D33A0(o + 12020, D_8007798C, 1, -1);
    }
}
