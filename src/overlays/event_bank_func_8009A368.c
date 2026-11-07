typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

typedef struct G { u8 pad[2560]; s32 mode; s32 on; } G;

extern G *D_800FC270;
extern u8 D_800F3BC0[];

extern u8 func_8009B670(u8 *o);
extern void func_800C0110(u8 *a, s32 b, s32 c, s32 d);

#define W(o) (*(s32 *)(p + (o)))
#define OBJ (*(u8 **)(p + 12136))
#define Q(o) (*(u8 *)(p + 0x8000 + (o)))
#define QS(o) (*(s8 *)(p + 0x8000 + (o)))

void func_80074D78(u8 *p)
{
    u8 r;
    s32 b;
    s32 n;
    s32 x;
    s32 a;

    r = func_8009B670(OBJ);
    if (Q(84) >= 2) {
        return;
    }
    if (D_800FC270->mode == 5 && OBJ[426] == 1) {
        a = 4;
        b = OBJ[424];
    } else {
        a = 38;
        b = OBJ[425];
    }
    x = a + b;
    if (D_800FC270->on != 0) {
        func_800C0110(D_800F3BC0, x, 0, 0);
    }
    a = -1;
    if (D_800FC270->mode != 4) {
        return;
    }
    if (D_800FC270->on == 4) {
        if (QS(80) == 1) {
            a = 533;
        } else if (QS(80) == 2) {
            a = 540;
        }
    } else if (D_800FC270->on == 5) {
        if (QS(80) != 2) {
            a = 547;
        } else if (OBJ[426] == 1) {
            a = 557;
        } else {
            a = 552;
        }
    }
    if (r < 4) {
        b = r;
    } else if (r < 8) {
        b = 4;
    } else {
        b = 5;
    }
    if (a >= 0) {
        x = a + b;
        if (D_800FC270->on != 0) {
            func_800C0110(D_800F3BC0, x, 0, 0);
        }
    }
}
