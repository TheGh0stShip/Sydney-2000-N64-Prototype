typedef signed char s8;
typedef unsigned char u8;
typedef int s32;
typedef float f32;

typedef struct {
    s32 a;
    s32 b;
    s32 c;
} Elem;

typedef struct {
    char pad0[0xA00];
    s32 mode;
    s32 sub;
    char pad1[0xA14 - 0xA08];
    Elem tbl[1];
} Game;

extern Game *D_800FC270;
extern void func_800CEC00(void *, f32);
extern void func_800CEE04(void *);
extern void func_80096860(void *, s32, s32, s32);
extern void func_80096F54(void *, s32, s32);
extern void func_800971EC(void *, void *, f32, void *, s32, s32);
extern void func_80096C8C(void *, s32, s32, Elem *, s32, s32);
extern void func_80076C18(u8 *);


#define OBJ(o) (*(u8 **)((o) + 23004))

void func_80074EA0(u8 *o, s32 flag)
{
    u8 st;
    u8 k;
    s32 ok;
    u8 *r;

    st = o[0x8417];
    if (st == 5 || st == 1) {
        return;
    }
    ok = 0;
    k = OBJ(o)[426];
    if (k == 1) {
        goto set;
    }
    if (k == 2) {
set:
        ok = 1;
    }
    if (ok) {
        if (flag == 0) {
            r = o + 31844;
            *(f32 *)(r + 212) = 0.0f;
            func_800CEC00(r, *(f32 *)(r + 212));
            func_800CEE04(r);
        }
        if (o[0x8417] != 2) {
            r = o + 26580;
            if (flag == 0) {
                func_80096860(r, 3, *(s32 *)(OBJ(o) + 420), 0);
                if (o[0x8417] == 4 || (D_800FC270->mode == 4 && D_800FC270->sub == 1)) {
                    func_80096F54(r, 3, *(s32 *)((u8 *)D_800FC270 + 3344));
                }
            } else {
                func_800971EC(r, OBJ(o), 0.6666f, OBJ(o) + 788, 195, 194);
                func_80096C8C(r, 3, D_800FC270->tbl[(s8)o[0x8415]].a,
                              *(Elem **)(o + 0x844C) + (s8)o[0x8415], (s8)o[0x8414], 0);
                func_80076C18(o);
            }
        }
    }
    *(s32 *)(o + 0x8440) = 0;
}
