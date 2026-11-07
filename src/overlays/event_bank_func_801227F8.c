typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

typedef struct Ctx { u8 pad[216]; s32 bit; } Ctx;
typedef struct Cls { u8 pad[16]; s16 off; s16 pad2; void (*fn)(u8 *, Ctx *); } Cls;
typedef struct G { u8 pad[3352]; s32 a; s32 b; } G;

extern u8 D_800F2758[];
extern Ctx D_800F4D00;
extern u16 D_800F4170[];
extern G *D_800FC270;

extern void func_800DAD10(u8 *a, s32 b, s32 c, s32 d);
extern void func_800B31EC(s32 a);
extern void func_800ADC54(u8 *e, s32 m);
extern void func_80082A84(u8 *p, s32 a, s32 b, s32 c, s32 d, s32 e);

typedef struct Ent { u8 b[220]; } Ent;
#define CLS(e) (*(Cls **)((e) + 180))

static inline void act(Ctx *c, u8 *e)
{
    CLS(e)->fn(e + CLS(e)->off, c);
    func_800ADC54(e, 1 << c->bit);
    e[176] = 1;
}

void func_801227F8(u8 *p)
{
    u8 i;
    u8 *e;

    func_800DAD10(D_800F2758, 350, 13, 15);
    func_800B31EC(0);
    i = 0;
    while (1) {
        if (!(i < 10)) break;
        act(&D_800F4D00, p + i * 220 + 1616);
        i++;
    }
    func_80082A84(p, D_800F4170[D_800FC270->a], 0, 0, 0, 0);
    func_80082A84(p, 25, D_800FC270->b + 1, 0, 0, 0);
    act(&D_800F4D00, p + 216);
}
