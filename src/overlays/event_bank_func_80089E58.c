typedef struct Obj {
    char pad[0x2F50];
    void *unk2F50;
    char pad2F54[0x59DC - 0x2F54];
    void *unk59DC;
    char pad59E0[0x5A9C - 0x59E0];
    char unk5A9C[0x8264 - 0x5A9C];
    char unk8264[0x8358 - 0x8264];
    char unk8358[4];
} Obj;
typedef struct Arg { int pad[4]; int kind; } Arg;
extern void func_80076E24(Obj *, void *, int);
extern void func_800A9B78(void *, void *, int, int, int);
void func_80089E58(Obj *o, Arg *a)
{
    switch (a->kind) {
    case 0:
        break;
    case 1:
        func_80076E24(o, o->unk59DC, 1);
        break;
    case 2:
        func_800A9B78(o->unk8264, o->unk2F50, 1, 1, 2);
        break;
    case 3:
        func_800A9B78(o->unk8264, o->unk5A9C, 1, 1, 2);
        break;
    case 6:
        func_800A9B78(o->unk8264, o->unk8358, 1, 1, 2);
        break;
    case 12:
        func_800A9B78(o->unk8264, o->unk8358, 1, 1, 1);
        func_800A9B78(o->unk8264, o->unk5A9C, 1, 1, 0);
        break;
    case 16:
        func_800A9B78(o->unk8264, o->unk5A9C, 1, 1, 1);
        func_800A9B78(o->unk8264, o->unk59DC, 1, 1, 0);
        break;
    case 18:
        func_800A9B78(o->unk8264, o->unk5A9C, 1, 1, 1);
        func_800A9B78(o->unk8264, o->unk8358, 1, 1, 0);
        break;
    }
}
