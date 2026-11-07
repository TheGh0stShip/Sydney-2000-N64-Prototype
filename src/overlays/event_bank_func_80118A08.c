typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern s32 D_8007EC14[];
extern char D_8007EC78[];
extern char D_8007EC90[];

extern void func_800125DC(s32 a, s16 *cfg, s32 *out, s32 n);
extern void func_80017C4C(s32 h, s32 a, s32 *out);
extern void func_800B3870(s32 h, char *s, s32 n);
extern void func_80017C3C(s32 h);
extern void func_80017C20(s32 h, s32 a, s32 b, char *s);
extern s32 func_8000EB20(s32 a);
extern void func_80017CF4(s32 h, s32 a, u16 b);

typedef struct Obj {
    u8 pad[0xCE0];
    s32 slots[25];
} Obj;

void func_80118A08(Obj *p)
{
    s16 cfg;
    s32 h;
    s32 *slot;
    u8 i;

    slot = p->slots;
    i = 0;
    cfg = 8;
    h = 0;
    do {
        *slot = 0;
        func_800125DC(1, &cfg, slot, 4);
        func_80017C4C(*slot, 0, &h);
        func_800B3870(h, D_8007EC90, 288);
        func_80017C3C(*slot);
        func_80017C20(*slot, 0, 4, D_8007EC78);
        slot++;
        func_80017CF4((p->slots)[i], 0, func_8000EB20(D_8007EC14[i]));
        i++;
    } while (i < 25);
}
