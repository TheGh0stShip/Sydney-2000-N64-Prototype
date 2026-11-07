typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef float f32;

typedef struct {
    char pad0[16];
    s16 off16;
    s16 pad18;
    void (*fn20)(void *, void *);
    char pad24[64 - 24];
    s16 off64;
    s16 pad66;
    void (*fn68)(void *);
} VT;

typedef struct {
    char pad0[8];
    u8 **base;
    u8 **top;
    char pad16[2];
    u16 count;
} Pool;

extern u8 D_80080A78[];
extern void *func_800AEF6C(void *, s32);
extern void func_800AF0BC(void *, s32 *);
extern u8 *func_800AAA58(s32, void *);
extern void func_800ADED4(void *);
extern void func_80080FA8(void *, s32, s32, s32, f32);
extern void func_80080F10(void *);

#define S32(o) (*(s32 *)(obj + (o)))
#define VTP(p) (*(VT **)((p) + 180))

static inline u8 *pool_new(Pool *pl, void *vt, s32 tag, u8 *obj)
{
    u8 *p = 0;
    u8 *q;
    if (pl->top > pl->base) {
        pl->count--;
        pl->top--;
        p = *pl->top;
        *pl->top = 0;
        q = func_800AAA58(272, p);
        func_800ADED4(q);
        *(void **)(q + 180) = vt;
        *(s32 *)q = tag;
        *(s32 *)(q + 260) = 0;
        *(s32 *)(q + 264) = 0;
        *(s32 *)(q + 268) = 0;
    }
    if (p != 0) {
        VTP(p)->fn20(p + VTP(p)->off16, obj);
    }
    return p;
}

void func_80075510(u8 *obj, u8 slot, u8 kind)
{
    s32 info[4];
    s32 n;
    u8 i;
    u8 *e;
    void *vt;
    s32 tag;

    func_800AF0BC(func_800AEF6C(obj + 25424, kind), info);
    n = 0;
    vt = D_80080A78;
    tag = 73;
    while (1) {
        i = n;
        if (i >= 10) {
            break;
        }
        e = pool_new((Pool *)(obj + 20188), vt, tag, obj);
        if (e == 0) {
            break;
        }
        *(u8 **)(obj + (slot * 40 + i * 4) + 20240) = e;
        func_80080FA8(e, S32(25348), S32(25356), info[0], *(f32 *)(obj + (i << 2) + 25220));
        func_80080F10(e);
        n++;
        VTP(e)->fn68(e + VTP(e)->off64);
    }
}
