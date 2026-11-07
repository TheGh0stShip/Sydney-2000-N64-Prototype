typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;
#define F32(x) (*(f32 *)(o + (x)))
#define S32(x) (*(s32 *)(o + (x)))
typedef struct { s32 a, b, c; } V3;
typedef struct { V3 cur; V3 prev; u16 t; u16 pt; u8 pad[20]; } Ent;
extern u8 D_8007D480[];
extern void func_800AD58C(void *, f32, f32, f32);
extern void func_800AD2A8(void *, void *, void *, s32);
extern void func_800E75B0(s32, void *);
extern void func_8007A510(u8 *);
extern void func_8007D374(u8 *);
extern void func_80074DD0(u8 *, s32);
extern void func_80073E54(u8 *, s32, s32, s32);
void func_8007B95C(u8 *o)
{
    u8 i;
    Ent *e;
    u8 *g;
    func_800AD58C(o + 20, F32(1120), 0.0f, 0.0f);
    F32(84) = F32(1112);
    F32(92) = F32(1116);
    F32(1348) = F32(1120);
    i = 0;
    while (1) {
        if (i >= 6) break;
        e = (Ent *)(o + 776) + i;
        func_800AD2A8(o + 20, D_8007D480 + i * 12, e, 1);
        func_800E75B0(S32(772), e);
        e->pt = e->t;
        e->prev = e->cur;
        i++;
    }
    S32(1384) = 0;
    S32(1388) = 0;
    F32(1376) = F32(908);
    F32(1380) = F32(956);
    func_8007A510(o);
    S32(1360) = 0;
    S32(1364) = 0;
    S32(1368) = 0;
    S32(1372) = 0;
    S32(1336) = 0;
    S32(1340) = 0;
    S32(1448) = 0;
    S32(1452) = 0;
    func_8007D374(o);
    g = *(u8 **)(o + 4);
    *(s16 *)(o + 764) = 300;
    o[734] = 0;
    o[735] = 0;
    *(s16 *)(o + 762) = 0;
    o[1486] = 2;
    F32(768) = 3276.69971f;
    func_80074DD0(g, 0);
    func_80073E54(g, 1, -7680, 0);
}
