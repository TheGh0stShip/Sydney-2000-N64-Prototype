typedef struct {
    int unk0;
    int flags;
    char pad[24];
} Ent800DD6F0;

typedef struct {
    char pad[598];
    short id;
    short unk2;
} Slot800DD6F0;

extern void func_800C6C90(int);
extern void func_800BC180(void *);
extern void func_800D53A0(void *, int);
extern char *D_800FCC74;
extern char D_800F2AD8[];
extern char D_800F5900[];

void func_800DD6F0(char *obj, int arg)
{
    char *g;
    unsigned char i;
    Slot800DD6F0 *s;

    g = D_800FCC74;
    for (i = 0; i < 8; i++) {
        s = (Slot800DD6F0 *)(obj + i * 6);
        s->id = i + 5;
        s->unk2 = 0;
        ((Ent800DD6F0 *)(g + 320))[i].flags |= 0x80000;
        ((Ent800DD6F0 *)(g + 64))[i].flags |= 0x80000;
    }
    for (i = 0; i < *(unsigned short *)(obj + 596); i++) {
        ((Ent800DD6F0 *)(g + 64))[i].flags &= ~0x80000;
    }
    ((Ent800DD6F0 *)(g + 32))->flags &= ~0x800000;
    ((Ent800DD6F0 *)(g + 576))->flags &= ~0x800000;
    if (arg != 0 && i != 0) {
        *(short *)(g + 14) = i + 1;
        if (((Ent800DD6F0 *)(g + 32))[i].unk0 != 0) {
            func_800C6C90(((Ent800DD6F0 *)(g + 32))[i].unk0);
        }
    } else {
        func_800BC180(D_800F2AD8);
        *(short *)(g + 14) = 1;
    }
    func_800D53A0(D_800F5900, 3);
}
