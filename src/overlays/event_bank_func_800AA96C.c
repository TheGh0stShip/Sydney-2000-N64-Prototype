typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef struct {
    s16 h0;
    s8 b2;
    u8 b3;
    s32 slots[3];
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
} EventRec;

typedef struct {
    s16 pad0;
    s16 h2;
    s32 w4;
    s32 pad8;
} EventSlot;

typedef struct {
    u8 pad0[0xA00];
    s32 mode;
    u8 pad1[8];
    u8 count;
    u8 pad2[3];
    EventSlot slots[1];
} EventGlobal;

typedef struct {
    u8 pad0[0x8118];
    s32 active;
    s8 cur;
    u8 pad1[0x13C - 0x11D];
    EventRec *recs;
} EventObjHi;

extern void func_80075DB4(void *obj);
extern void func_800AB2A4(void *a, s32 b, s32 c, void *d, s32 e, s32 f);
extern void func_800759C8(void *obj);
extern void func_80075100(void *obj);
extern void func_800DA804(s32 a, s32 b, void *c, s32 d, s32 e);
extern void func_80074790(void *obj);
extern void func_800AACB0(void *a, void *b, s32 c);

extern EventGlobal *D_800FC270;
extern u8 D_800F26E0[];
extern s32 D_800F2744;
extern u8 D_800F1798[];

void func_800AA96C(u8 *obj, s32 *ev)
{
    switch (ev[4]) {
    case 56: {
        EventObjHi *hi = (EventObjHi *)obj;
        u8 i;
        hi->cur = -1;
        hi->active = 1;
        for (i = 0; i < D_800FC270->count; i++) {
            u8 j;
            hi->recs[i].f14 = 0;
            hi->recs[i].f10 = 0;
            hi->recs[i].b3 = 0;
            hi->recs[i].h0 = 0;
            hi->recs[i].b2 = -1;
            hi->recs[i].f18 = 0;
            for (j = 0; j < 3; j++) {
                hi->recs[i].slots[j] = -1;
            }
            D_800FC270->slots[i].w4 = 0;
            D_800FC270->slots[i].h2 = 0;
        }
        func_80075DB4(obj);
        func_800AB2A4(D_800F26E0, D_800F2744, 21, obj, 0, 0);
        break;
    }
    case 8:
    case 15:
        break;
    case 7: {
        s32 m = D_800FC270->mode;
        if (m == 4 || m == 0 || m == 1 || m == 2) {
            func_800759C8(obj);
            func_80075100(obj);
            func_800DA804(0, 0, D_800F1798, 0, 0);
        }
    }
    case 9:
    default:
        func_80074790(obj);
        func_800AACB0(D_800F26E0, obj, 0);
        *(s32 *)(obj + 0xAC) = 1;
        break;
    }
}
