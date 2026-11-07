typedef unsigned char u8;
typedef struct Snd { char pad[0x68]; int vol; } Snd;
typedef struct Sub { char pad[0xB8]; u8 b8; u8 b9; u8 bA; u8 bB; } Sub;
typedef struct Obj {
    char pad[0x59E0];
    Sub sub;
    char pad5A9C[0x64E8 - 0x5A9C];
    char unk64E8[0x67C8 - 0x64E8];
    int unk67C8;
    char pad67CC[0x8264 - 0x67CC];
    char unk8264[0x8416 - 0x8264];
    u8 unk8416;
    u8 state;
    char pad8418[0x8430 - 0x8418];
    int unk8430;
    int unk8434;
} Obj;
extern Snd D_800F1AE0;
extern void func_800754C8(Obj *);
extern void func_80074EA0(Obj *, int);
extern void func_800A9BE8(void *, int);
extern void func_8001D5D8();
extern int func_8001D4B8(Snd *, int, int, int);
extern void func_8001D640(Snd *, int, int);
extern void func_800817F4(void *);
extern void func_800735F4(Obj *, int);
void func_80089FD8(Obj *o, int a1, int a2)
{
    int h;
    int m;
    Sub *s;
    func_800754C8(o);
    func_80074EA0(o, 1);
    switch (o->state) {
    case 0:
    case 1:
    case 3:
    case 4:
        func_800A9BE8(o->unk8264, 2);
        break;
    case 2:
        func_800A9BE8(o->unk8264, 14);
        break;
    case 5:
        func_800A9BE8(o->unk8264, 8);
        break;
    }
    switch (o->state) {
    case 0:
    case 1:
    case 5:
        { int k = o->unk8430; func_8001D5D8(&D_800F1AE0, k, 0, 120, 1, 0); }
        h = func_8001D4B8(&D_800F1AE0, 96, 0, -1);
        func_8001D640(&D_800F1AE0, h, 0);
        m = 24575;
        func_8001D5D8(&D_800F1AE0, h, (D_800F1AE0.vol * m) >> 15, 120, 0, 0);
        o->unk8434 = h;
        break;
    case 2:
    case 3:
    case 4:
        break;
    }
    if (o->state == 5) {
        o->unk67C8 = -7680;
    } else {
        o->unk67C8 = 115200;
    }
    o->unk8416 = 4;
    s = &o->sub;
    s->b9 = 1;
    s->b8 = 1;
    s->bA = 1;
    s->bB = 0;
    func_800817F4(o->unk64E8);
    func_800735F4(o, a2);
}
