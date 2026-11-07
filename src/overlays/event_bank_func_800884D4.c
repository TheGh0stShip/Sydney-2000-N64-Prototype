typedef unsigned char u8;
typedef struct Obj {
    char pad0[0x45C];
    char unk45C[0x60F - 0x45C];
    u8 unk60F;
    char pad610[0x615 - 0x610];
    u8 state;
    char pad616[0x4140 - 0x616];
    char unk4140[0x5424 - 0x4140];
    int timer;
} Obj;
typedef struct Glob { char pad[0xD10]; int unkD10; } Glob;
extern Glob *D_800FC270;
extern void func_800753E8(Obj *);
extern void func_800A9BE8(void *, int);
extern void func_80099D70(void *, int, float);
extern void func_8009B9EC(int, int);
void func_800884D4(Obj *o)
{
    o->timer -= 256;
    if (o->timer <= 0) {
        switch (o->state) {
        case 0:
        case 1:
            func_800753E8(o);
            func_800A9BE8(o->unk45C, 2);
            o->timer = 0;
            o->unk60F = 3;
            break;
        case 4:
            func_80099D70(o->unk4140, 7, (float)D_800FC270->unkD10 / 30.0f * 0.00390625f);
        case 2:
        case 3:
            func_800A9BE8(o->unk45C, 5);
            o->unk60F = 6;
            break;
        case 5:
            break;
        }
    }
    func_8009B9EC(11520, 0);
}
