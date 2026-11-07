typedef unsigned char u8;
typedef struct Snd { char pad[104]; int volume; } Snd;
typedef struct Obj {
    char pad[1116];
    char unk45C[1551 - 1116];
    u8 unk60F;
    char pad610[1554 - 1552];
    u8 unk612;
    char pad613[1557 - 1555];
    u8 state;
    char pad616[12884 - 1558];
    char unk3254[24932 - 12884];
    int unk6164;
    char pad6168[24976 - 24936];
    int handle;
    char pad6194[24996 - 24980];
    int unk61A4;
} Obj;
extern Snd D_800F1AE0;
extern char D_8007755C[];
extern void func_8007543C(Obj *);
extern int func_8001D4B8(Snd *, int, int, int);
extern void func_8001D640(Snd *, int, int);
extern void func_8001D5D8(Snd *, int, int, int, int, int);
extern void func_8009BEE0(int);
extern void func_800D33A0(void *, void *, int, int);
extern void func_80076564(Obj *, int, int, int);
extern void func_800A9BE8(void *, int);
extern void func_800177EC(void);
static __inline__ int scale(int v, int k)
{
    return (v * k) >> 15;
}

void func_80071CC4(Obj *o)
{
    int h;
    switch (o->state) {
    case 0:
    case 1:
        func_8007543C(o);
        h = func_8001D4B8(&D_800F1AE0, 95, 0, -1);
        func_8001D640(&D_800F1AE0, h, 0);
        func_8001D5D8(&D_800F1AE0, h, scale(D_800F1AE0.volume, 19660), 45, 0, 0);
        o->handle = h;
        func_8009BEE0(11520);
        break;
    case 2:
        func_800D33A0(o->unk3254, D_8007755C, 1, -1);
        func_80076564(o, 42, 0, 0);
        break;
    case 3:
    case 4:
    case 5:
        break;
    }
    func_800A9BE8(o->unk45C, o->unk612);
    o->unk60F = 2;
    o->unk6164 = o->unk61A4;
    func_800177EC();
}
