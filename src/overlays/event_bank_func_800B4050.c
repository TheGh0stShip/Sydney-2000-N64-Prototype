typedef unsigned char u8;
typedef struct Ent { char pad[1208]; u8 unk4B8; } Ent;
typedef struct Obj {
    char pad[21292];
    Ent *ent;
    char unk5330[21604 - 21296];
    char unk5464[23416 - 21604];
    u8 unk5B78;
    char pad5B79[2];
    u8 unk5B7B;
    char pad5B7C[23432 - 23420];
    int unk5B88;
    u8 unk5B8C;
    u8 unk5B8D;
    u8 unk5B8E;
    char pad5B8F[23448 - 23439];
    u8 unk5B98;
} Obj;
extern u8 D_80077660[][4];
extern char D_800F26E0[];
extern int D_800F2744;
extern void func_80081100(void *, int, int);
extern void func_800AB2A4(void *, int, int, Ent *, int, int);
void func_80074E80(Obj *o)
{
    u8 k = D_80077660[o->unk5B78][o->unk5B7B];
    o->unk5B8D = 1;
    o->unk5B98 = 0;
    o->unk5B88 = 0;
    switch (k) {
    case 0:
        break;
    case 1:
        func_80081100(o->unk5330, 1, 1);
        o->ent->unk4B8 = 1;
        o->unk5B8E = 1;
        break;
    case 2:
        func_80081100(o->unk5330, 0, 1);
        o->ent->unk4B8 = 1;
        o->unk5B8E = 1;
        break;
    case 3:
        func_80081100(o->unk5330, 1, 1);
        func_80081100(o->unk5464, 0, 0);
        o->ent->unk4B8 = 2;
        o->unk5B8E = 2;
        break;
    case 4:
        func_80081100(o->unk5464, 1, 0);
        func_80081100(o->unk5330, 0, 1);
        o->ent->unk4B8 = 2;
        o->unk5B8E = 2;
        break;
    }
    o->unk5B8D = 1;
    o->unk5B8C = 0;
    func_800AB2A4(D_800F26E0, D_800F2744, 14, o->ent, 0, 0);
}
