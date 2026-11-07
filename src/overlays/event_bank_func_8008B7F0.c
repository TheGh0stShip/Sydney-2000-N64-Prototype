typedef unsigned char u8;
typedef signed char s8;
typedef struct Ent { s8 kind; char pad[3]; float f4; int pad8; } Ent;
typedef struct G {
    char pad[0xA10];
    Ent ents[1];
} G;
typedef struct Slot { float f0; int pad[2]; } Slot;
typedef struct Obj {
    char pad[0x2B8];
    char unk2B8[0x8414 - 0x2B8];
    s8 unk8414;
    s8 cur;
    u8 unk8416;
    u8 state;
    char pad8418[0x8428 - 0x8418];
    int timer8428;
    int timer842C;
    char pad8430[0x844C - 0x8430];
    Slot *slots;
} Obj;
extern G *D_800FC270;
extern char D_800F26E0[];
extern int D_800F2744;
extern void func_800D29E0(void *);
extern void func_80076EB8(Obj *);
extern void func_800AB2A4(void *, int, int, void *, int, int);
extern void func_8009BD48(int);
void func_8008B7F0(Obj *o)
{
    if (o->timer842C > 0) {
        o->timer842C -= 256;
        if (o->timer842C <= 0) {
            func_800D29E0(o->unk2B8);
        }
    }
    o->timer8428 -= 256;
    if (o->timer8428 > 0) {
        return;
    }
    func_80076EB8(o);
    switch (o->state) {
    case 0:
    case 1:
        o->unk8416 = 16;
        break;
    case 5:
        o->unk8416 = 17;
        break;
    case 2:
        o->state = 3;
        o->unk8416 = 0;
        func_800AB2A4(D_800F26E0, D_800F2744, 24, o, 0, 0);
        D_800FC270->ents[o->cur].f4 = -1.0f;
        o->slots[o->cur].f0 = -1.0f;
        o->unk8414 = -1;
        func_8009BD48(o->state);
        break;
    case 3:
    case 4:
        func_800AB2A4(D_800F26E0, D_800F2744, 24, o, 0, 0);
        break;
    }
}
