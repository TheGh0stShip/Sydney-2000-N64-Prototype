typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    char pad0[0x52];
    u8 f52;
    u8 pad53;
    u8 f54;
    char pad55[0x6C - 0x55];
    s32 f6C;
    char pad70[0x74 - 0x70];
    s32 f74;
    s32 f78;
} Hdr;

typedef struct {
    char pad0[0x68];
    s32 vol;
} Snd;

extern s32 D_800F2724;
extern s32 D_800F2728;
extern s32 D_800F1270;
extern Snd D_800F1AE0;
extern u8 D_80076EF0[];
extern void func_800D29E0(void *);
extern void func_800D33A0(void *, void *, s32, s32);
extern s32 func_8001D4B8(void *, s32, s32, s32);
extern void func_8001D640(void *, s32, s32);
extern void func_800768EC(void *, s32, s32, s32);
extern void func_800AC25C(void *, s32, s32, s32);
extern void func_8009B9EC(s32, s32);

static inline s32 mulv(s32 a, s32 b) { return a * b; }

void func_80072A0C(u8 *obj)
{
    s32 old;
    u32 cur;
    s32 r;

    if (((Hdr *)(obj + 0x8000))->f78 != 0) {
        ((Hdr *)(obj + 0x8000))->f6C -= 256;
        if (((Hdr *)(obj + 0x8000))->f6C <= 0) {
            ((Hdr *)(obj + 0x8000))->f6C = 0;
            ((Hdr *)(obj + 0x8000))->f78 = 0;
            *(s32 *)(obj + 12104) = 0;
            func_800D29E0(obj + 696);
        }
    } else {
        old = (u32)((f32)((Hdr *)(obj + 0x8000))->f74 / 30.0f * 0.00390625f);
        cur = 256;
        if (D_800F2728 == 0) {
            D_800F2724 = 1;
        }
        if (old < 0) {
            cur = 0;
        }
        ((Hdr *)(obj + 0x8000))->f74 -= cur;
        cur = (u32)((f32)((Hdr *)(obj + 0x8000))->f74 / 30.0f * 0.00390625f);
        if (cur < 6) {
            if (old != cur) {
                D_800F1270 = cur;
                if (cur == 5) {
                    func_800D33A0(obj + 696, D_80076EF0, 1, -1);
                } else {
                    func_800D33A0(obj + 696, D_80076EF0, 0, -1);
                }
                r = func_8001D4B8(&D_800F1AE0, 226, 0, 0);
                func_8001D640(&D_800F1AE0, r, mulv(D_800F1AE0.vol, 32767) >> 15);
            }
            if (old > 0 && (s32)cur <= 0) {
                ((Hdr *)(obj + 0x8000))->f74 = 0;
                func_800768EC(obj, 205, 0, 0);
                func_800AC25C(obj, 93, 17, 1);
                ((Hdr *)(obj + 0x8000))->f52 = 24;
            }
        }
    }
    if (((Hdr *)(obj + 0x8000))->f54 != 2 && ((Hdr *)(obj + 0x8000))->f54 != 4) {
        func_8009B9EC(11520, 0);
    }
}
