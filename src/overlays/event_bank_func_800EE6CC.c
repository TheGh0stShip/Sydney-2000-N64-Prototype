typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef float f32;
typedef struct { u8 pad[429]; u8 idx; s16 arr[1]; } O;
extern void func_800AD434(u8 *, f32, s32);
extern s32 func_800B9BD4(O *, s32, f32 *, f32 *, f32 *, s32);
extern void func_800B9964(O *, f32 *, f32 *, f32 *);
extern void func_800B7824(O *, s32);
extern void func_800B9E74(O *, s32);
extern void func_800B9E9C(O *, s16, s32, f32, s32);
void func_8007AE9C(O *o)
{
    f32 a[4];
    f32 b[4];
    f32 c[2];
    f32 d;
    s32 r;
    if (*(f32 *)((u8 *)o + 860) < 0.0f) {
        d = *(f32 *)((u8 *)o + 632) * 0.41887903f;
        *(f32 *)((u8 *)o + 860) += d;
        func_800AD434((u8 *)o + 20, d, 3);
    }
    r = func_800B9BD4(o, 1, a, c, b, 0);
    func_800B9964(o, a, c, b);
    if (r != 0) {
        if (*(s32 *)((u8 *)o + 760) != 0) {
            if (r == 1) {
                if (o->arr[o->idx] != -1 && (o->arr[o->idx] & 0x4000)) {
                    func_800B9E9C(o, o->arr[o->idx++] & 0xBFFF, -1, 1.0f, 0);
                }
            } else if (r == 3) {
                func_800B7824(o, 0);
                func_800B9E74(o, 2);
                if (o->arr[o->idx] != -1) {
                    func_800B9E9C(o, o->arr[o->idx++] & 0xBFFF, -1, 1.0f, 0);
                }
                *(s32 *)((u8 *)o + 760) = 0;
            }
        } else {
            if (o->arr[o->idx] != -1) {
                func_800B9E9C(o, o->arr[o->idx++] & 0xBFFF, -1, 1.0f, 0);
            }
        }
    }
}
