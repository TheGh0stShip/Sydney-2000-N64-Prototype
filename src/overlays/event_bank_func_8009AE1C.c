typedef unsigned char u8;
typedef int s32;
typedef float f32;

typedef struct {
    char pad0[0x4FC];
    f32 base;
    char pad500[0x528 - 0x500];
    f32 limit;
    char pad52C[0xA04 - 0x52C];
    s32 sub;
} Game;

extern Game *D_800FC270;
extern u8 D_800F3BC0[];
extern void func_800C0110(void *, s32, s32, s32);

#define SND(n) if (D_800FC270->sub != 0) { func_800C0110(D_800F3BC0, (n), 0, 0); }

void func_8007582C(u8 *obj, f32 v)
{
    f32 base;
    f32 hi;
    f32 lo;

    if (obj[0x8054] == 5) {
        return;
    }
    base = D_800FC270->base;
    obj[0x8053] = 0;
    hi = base + 1.25f;
    lo = base - 1.25f;
    if (*(s32 *)(*(u8 **)(obj + 12136) + 744) != 0) {
        if (hi <= v) {
            SND(134);
            obj[0x8053] = 1;
        } else if (base < v) {
            SND(384);
            obj[0x8053] = 2;
        } else if (lo < v && D_800FC270->limit < v) {
            SND(384);
            obj[0x8053] = 3;
        } else if (v <= D_800FC270->limit && lo < v) {
            SND(384);
            obj[0x8053] = 4;
        } else if (D_800FC270->limit < v) {
            SND(385);
            obj[0x8053] = 5;
            } else if (80.0f < v) {
            SND(131);
        } else if (77.0f < v) {
            SND(225);
        } else if (73.0f < v) {
            SND(224);
        } else if (70.0f < v) {
            SND(223);
        } else if (67.0f < v) {
            SND(222);
        } else if (63.0f < v) {
            SND(221);
        } else if (60.0f < v) {
            SND(220);
        } else if (57.0f < v) {
            SND(219);
        } else if (53.0f < v) {
            SND(218);
        } else if (50.0f < v) {
            SND(217);
        } else if (25.0f < v) {
            SND(130);
        } else {
            SND(227);
        }
    } else {
        SND(2);
    }
}
