typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;
typedef struct { u8 r[60]; } E60;
typedef struct { s32 a; f32 f; s32 c; } E12;
typedef struct {
    u8 pad0[20];
    E60 ents[8];
    u8 pad500[2060];
    s32 mode;
    u8 pad2564[12];
    E12 tr[83];
    u8 pad3572[0];
    f32 f3572;
} G;
extern G *D_800FC270;
extern u32 D_800779C0;
extern u8 D_80077790[];
extern void *func_800D98FC(s32);
extern void func_800D15C8(u8 *, s32, void *, u32);
extern void func_800B31EC(s32);
extern void func_800D33F8(u8 *, void *, s32, s32);
typedef struct { u8 pad[196]; s32 cur; u8 p200[12]; s32 tab[4]; } Sub;
void func_80075928(u8 *o)
{
    u8 *e = *(u8 **)(o + 21292);
    s32 b = e[424];
    E12 *t;
    Sub *q;
    if (o[23423] != 2) {
        t = &D_800FC270->tr[o[23417]];
        if (b != 8) {
            E60 *p = &D_800FC270->ents[b];
            func_800D15C8(o + 23512, e[425], p, (u32)t->f);
        } else {
            s32 k = e[425];
            func_800D15C8(o + 23512, k, func_800D98FC(13), (u32)t->f);
        }
        q = (Sub *)(o + 23512);
        q->cur = q->tab[o[23416]];
        if (D_800FC270->mode == 5) {
            func_800B31EC(3);
            D_800779C0 = (u32)D_800FC270->f3572;
            func_800D33F8(o + 13420, D_80077790, 0, -1);
        }
    }
    o[23421] = 0;
}
