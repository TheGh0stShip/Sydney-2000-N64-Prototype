typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern u8 *D_800FC270;
extern char D_800F3BC0[];
extern s32 D_80077BC0[];
extern char D_800779F4[];

extern void func_800C0110(char *a, s32 b, s32 c, s32 d);
extern s32 func_800D98FC(s32 a);
extern void func_800D33A0(u8 *a, char *b, s32 c, s32 d);

typedef struct Obj { u8 pad[0x4EF0]; u8 *tbl[8]; } Obj;
#define W(o) (*(s32 *)(p + (o)))
#define B(o) (*(u8 *)(p + (o)))

void func_800E1644(u8 *p)
{
    u8 *o;
    u8 a;
    s32 x;
    u8 n;
    s32 i;
    u16 base;
    s32 hi;
    s32 lo;
    s32 r;

    i = B(0x60C);
    n = i + B(0x611);
    o = ((Obj *)p)->tbl[i];
    a = o[0x1A9];
    if (o[0x1AA] != 3 && *(s32 *)(D_800FC270 + 0xA00) == 5) {
        base = 49;
        x = o[0x1A8];
        hi = 16;
        lo = 8;
    } else {
        base = 99;
        x = a;
        hi = 32;
        lo = 64;
    }
    if (B(0x613) < 3) {
        goto H;
    } else if (B(0x60C) != 0) {
        if (B(0x60C) == B(0x613) - 1) {
            if (B(0x60C) != 0) {
                base += lo;
            }
        } else {
H:
            base += hi;
        }
    }
    r = x + base;
    if (*(s32 *)(D_800FC270 + 0xA04) != 0 && W(0x62E8) == 1) {
        func_800C0110(D_800F3BC0, r, 0, 7680);
    }
    D_80077BC0[0] = (u8)n + 1;
    D_80077BC0[1] = func_800D98FC(a + 149);
    func_800D33A0(p + 0x3254, D_800779F4, 0, -1);
}
