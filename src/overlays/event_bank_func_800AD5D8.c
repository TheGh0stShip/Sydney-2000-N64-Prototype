typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef struct VE { s16 off; s16 pad; void (*fn)(); } VE;
typedef struct VT { u8 pad[24]; VE a; u8 pad2[40]; VE b; } VT;
typedef struct Obj { u8 pad[180]; VT *vt; u8 pad2[28]; } Obj;

extern void func_80097504(u8 *p);
extern void func_800AC334(u8 *p);
extern void func_800ADC1C(u8 *p);
extern void func_800B35F0(u8 *p);
extern void func_800D29E0(u8 *p);

static inline u8 *slot(u8 *p, u32 i)
{
    return p + (30140 + 212 * i);
}

static inline Obj *obj(u8 *p, u32 i)
{
    return (Obj *)((p + 212 * i) + 30140);
}

void func_800AD5D8(u8 *p)
{
    u32 i;

    *(s32 *)(p + 0x8000 + 312) = 1;
    func_80097504(p + 13784);
    func_800AC334(p + 29928);
    func_800ADC1C(p + 29928);
    for (i = 0; i < 3; i++) {
        Obj *o = obj(p, i);
        o->vt->a.fn(slot(p, i) + o->vt->a.off);
        o->vt->b.fn(slot(p, i) + o->vt->b.off);
    }
    func_800AC334(p + 11708);
    func_800B35F0(p + 11708);
    func_800ADC1C(p + 11708);
    func_800AC334(p + 30992);
    func_800D29E0(p + 30992);
    func_800ADC1C(p + 30992);
}
