typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned char u8;
typedef float f32;
typedef struct { u8 pad[429]; u8 idx; s16 arr[1]; } OI;
extern s32 D_800F2728;
extern s32 D_800F2778;
extern void func_800BC07C(void *, s32);
extern void func_800BBB30(void *, s32, void *);
extern void func_80079964(u8 *, s32);
extern void func_800B9E9C(u8 *, s16, s32, f32, s32);
extern void func_8007BDF0(u8 *);
extern void func_8007B9E8(u8 *);
void func_80078C20(u8 *o, s32 *m)
{
    s32 d;
    s32 ok;
    s32 f;
    u8 *p;
    u8 *s;
    d = (m[1] - *(s32 *)(o + 16)) >> 8;
    (*(u8 **)(o + 648))[3] = 0;
    (*(u8 **)(o + 648))[2] = 0;
    switch (m[0]) {
    case 2:
        p = *(u8 **)(o + 4);
        ok = 1;
        switch (*(u32 *)(o + 172)) {
        case 20: case 21: case 22: case 23: case 24: case 25: case 26:
            f = D_800F2728 == 0 || m[1] - D_800F2778 < 0;
            if (f) {
                ok = 0;
            } else if (p[31918] == 2) {
                ok = 0;
            } else {
                s = (u8 *)(m + 4);
                func_800BC07C(*(void **)(o + 648), s[1]);
                if (p[31919] != 5 && *(s32 *)(o + 800) != 0) {
                    func_800BBB30(*(void **)(o + 644), m[1] - D_800F2778, s);
                }
            }
            break;
        }
        if (!ok) {
            break;
        }
    case 5:
        func_80079964(o, d);
        break;
    case 25:
        if (((OI *)o)->arr[((OI *)o)->idx] != -1) {
            func_800B9E9C(o, ((OI *)o)->arr[((OI *)o)->idx++], -1, *(f32 *)(o + 744), 0);
        }
        *(s32 *)(o + 172) = 26;
        break;
    case 17:
        func_8007BDF0(o);
        func_8007B9E8(o);
        break;
    case 26:
        break;
    }
    *(s32 *)(o + 16) = m[1];
}
