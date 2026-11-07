typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    s32 type;
    s32 time;
    s32 pad8;
    s32 arg;
    u8 data[4];
} Event;

extern u8 D_800F2AD8[];
extern void func_800BC07C(void *, s32);
extern s32 func_800BBB30(void *, s32, void *);
extern void func_800BC1E8(void *, s32, s32, s32);
extern void func_800BBD78(void *, s32, s32, void *, s32);
extern void func_80078F18(u8 *, s32);

#define S32(o) (*(s32 *)(obj + (o)))
#define PTR(o) (*(u8 **)(obj + (o)))

void func_80078D00(u8 *obj, Event *ev)
{
    u8 *w;
    s32 d;
    s32 st;
    s32 type;
    u8 *e;
    s32 snd;

    w = PTR(4);
    d = (ev->time - S32(16)) >> 8;
    st = w[24041];
    PTR(648)[3] = 0;
    PTR(648)[2] = 0;
    type = ev->type;
    switch (type) {
    case 2:
        if ((u32)(S32(172) - 15) < 2) {
            e = ev->data;
            func_800BC07C(PTR(648), e[1]);
            if (obj[426] != 4 && st != 5 && st != type && *(s32 *)(w + 24108) == 0) {
                *(s32 *)(w + 24108) = func_800BBB30(PTR(644), ev->arg, e);
            }
        }
        func_80078F18(obj, d);
        break;
    case 5:
        func_80078F18(obj, d);
        break;
    case 15:
        *(s16 *)(PTR(644) + 2) = 0;
        if (st != 5 && st != 2) {
            func_800BC1E8(D_800F2AD8, (s8)obj[427], 0, obj[732]);
        } else {
            func_800BC1E8(D_800F2AD8, (s8)obj[427], 0, 21);
        }
        func_800BBD78(D_800F2AD8, (s8)obj[427], 0, obj, 8);
        {
        u8 *q = PTR(648);
        q[0] = 0;
        q[1] = 0;
        q[2] = 0;
        q[3] = 0;
        q[4] = 0;
        q[5] = 0;
        q[6] = 0;
        q[7] = 0;
        }
        obj[637] = 0;
        S32(172) = 15;
        func_80078F18(obj, d);
        break;
    case 18:
        func_800BBD78(D_800F2AD8, (s8)obj[427], 0, 0, 8);
        S32(172) = 4;
        break;
    }
    S32(16) = ev->time;
}
