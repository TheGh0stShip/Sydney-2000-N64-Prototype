/* Event-bank event dispatcher (link VRAM 0x80071468), ROM 0xB97E8..0xB9F20. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct VEntry {
    s16 delta;
    s16 pad;
    void (*fn)(void *, s32);
} VEntry;

typedef struct Pool {
    void *heap;
    u8 *items;
    u8 **stack;
    u8 **top;
    u16 cap;
    u16 count;
} Pool;

typedef struct Event {
    s32 type;
    s32 time;
    s32 pad08;
    s32 pad0C;
    u32 arg;
} Event;

extern void *D_80070F18[];
extern char D_80070EE4[];
extern s32 D_80072D28[][3];
extern s32 D_80072D58[][3];
extern s32 D_80072D88[][3];
extern s32 D_80072DB8[][3];
extern char D_80072E6C[];
extern s32 D_80072D20;
extern s32 D_80072D24;
extern u8 *D_800FC270;
extern char D_800F2AD8[];
extern char D_800F2758[];
extern char D_800F26E0[];
extern u8 D_800F1AE0[];

extern void func_80015EAC(s32);
extern void func_800177AC(void);
extern void func_80017D84(char *, s32);
extern void func_80081F08(u8 *, char *, char *, u8 *, s32);
extern void func_800839DC(u8 *, s32, s32, s32);
extern void func_80071070(u8 *);
extern void func_800BBD78(char *, s32, s32, u8 *, s32);
extern void func_80005A3C(s32, void *, char *, s32);
extern void func_80082A84(u8 *, s32, s32, s32, s32, s32);
extern void func_80082764(u8 *, s32);
extern void func_800AACB0(char *, u8 *, s32);
extern void func_800AA658(void *, void *);
extern void func_800ADC1C(u8 *);
extern void func_800828B4(u8 *, s32);
extern void func_80083700(u8 *, s32);
extern void func_800BC07C(u8 *, s32);
extern void func_80072624(u8 *);
extern s32 func_8001D4B8(u8 *, s32, s32, s32);
extern void func_8001D640(u8 *, s32, s32);
extern void func_80083A0C(u8 *);
extern void func_800728BC(u8 *);
extern void func_800721BC(u8 *);

#define W(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define P(p, o) (*(u8 **)((u8 *)(p) + (o)))
#define B(p, o) (*(u8 *)((u8 *)(p) + (o)))
typedef struct VEntry1 {
    s16 delta;
    s16 pad;
    void (*fn)(void *);
} VEntry1;
#define VE1(e, off) ((VEntry1 *)(P(e, 180) + (off)))
#define VE(e, off) ((VEntry *)(P(e, 180) + (off)))
#define VCALL1(e, off) VE1(e, off)->fn((e) + VE1(e, off)->delta)
#define VCALL(e, off, a) VE(e, off)->fn((e) + VE(e, off)->delta, a)

static __inline__ s32 Lt32(u8 x)
{
    return x < 32;
}

static __inline__ void Pool_Free(Pool *pool)
{
    void *h = pool->heap;
    if (h != 0) {
        pool->heap = 0;
        if (pool->items) func_800AA658(h, &pool->items);
        if (pool->stack) func_800AA658(h, &pool->stack);
        pool->cap = 0;
        pool->count = 0;
        pool->top = 0;
        pool->heap = 0;
    }
}

static __inline__ void Init_Block(u8 *o, f32 one, f32 y, f32 z)
{
    u8 *v = o + 17924;
    B(o, 18740) = 0;
    W(v, 36) = 0;
    W(v, 32) = 0;
    W(v, 24) = 0;
    W(v, 16) = 0;
    W(v, 8) = 0;
    W(v, 4) = 0;
    W(v, 72) = 0;
    W(v, 68) = 0;
    W(v, 64) = 0;
    F(v, 40) = one;
    F(v, 20) = one;
    F(o, 17924) = one;
    v = o + 17988;
    W(o, 17988) = 0;
    F(v, 4) = y;
    F(v, 8) = z;
}

static __inline__ void Snd_Set(u8 *p, s32 h, s32 v)
{
    func_8001D640(p, h, (W(p, 104) * v) >> 15);
}

void func_80071468(u8 *o, Event *m)
{
    s32 dt = (m->time - W(o, 16)) >> 8;
    u8 i;
    u8 *e;
    u8 *g;
    u8 *b;
    u8 *p;
    u8 t;
    s32 (*tbl)[3];

    switch (m->type) {
    case 3:
    func_80015EAC(12);
    g = D_800FC270;
    switch (g[3411]) {
    case 0:
        W(o, 17124) = D_80072D28[W(g, 3352)][W(g, 3356)];
        break;
    case 1:
        W(o, 17124) = D_80072D58[W(g, 3352)][W(g, 3356)];
        break;
    case 2:
        W(o, 17124) = D_80072D88[W(g, 3352)][W(g, 3356)];
        break;
    case 3:
        W(o, 17124) = D_80072DB8[W(g, 3352)][W(g, 3356)];
        break;
    }
skip:
    func_80017D84(D_80070EE4, -1);
    {
    u8 *v = o + 17924;
    B(o, 18740) = 0;
    W(v, 36) = 0;
    W(v, 32) = 0;
    W(v, 24) = 0;
    W(v, 16) = 0;
    W(v, 8) = 0;
    W(v, 4) = 0;
    W(v, 72) = 0;
    W(v, 68) = 0;
    W(v, 64) = 0;
    F(o, 17924) = F(v, 20) = F(v, 40) = 1.0f;
    {
    u8 *w = o + 17988;
    W(o, 17988) = 0;
    F(w, 4) = 6.553399562835693f;
    F(w, 8) = -6.553399562835693f;
    }
    }
    W(o, 18736) = 0;
    W(o, 18732) = 0;
    W(o, 18728) = 0;
    W(o, 18724) = 0;
    F(o, 18752) = F(o, 18756) = F(o, 18744) = F(o, 18748) = 0.0f;
    func_80081F08(o, D_80072E6C, D_80072E6C, o + 17904, 0);
    func_800839DC(o, 60, 60, 60);
    func_80071070(o);
    func_800BBD78(D_800F2AD8, 0, 0, o, 6);
    W(o, 18700) = 0;
    func_80005A3C(W(o, 17124), o + 18700, D_800F2758, 1);
    p = P(o, 18700);
    t = p[3];
    p += 4;
    B(o, 18723) = p[3];
    p += 4;
    F(o, 18716) = (f32)*(s32 *)p;
    p += 4;
    P(o, 18704) = p;
    B(o, 18721) = t;
    B(o, 18720) = t;
    B(o, 18722) = 0;
    W(o, 18712) = 0;
    W(o, 3860) = 0;
    B(o, 18692) = 0;
    B(o, 18708) = 0;
    W(o, 3852) = 15360;
    func_80082A84(o, 4, 0, 0, 0, 0);
    func_80082A84(o, 34, (u32)F(o, 18716), 0, 0, 0);
    func_80082764(o, 4);
    {
        f32 c, d, r;
        u8 *g2 = D_800FC270;
        c = 0.013333333656191826f;
        F(o, 18764) = c;
        r = F(g2, 44) * c + c;
        d = 2.320995569229126f;
        F(o, 18764) = r;
        F(o, 18760) = F(g2, 40) * d * 0.5f + d;
    }
    func_800177AC();
        break;
    case 7:
    switch (m->arg) {
    case 8:
    case 15:
        func_800BBD78(D_800F2AD8, 12, 1, o, 0);
        break;
    case 7:
    case 57:
        for (i = 0; Lt32(i); i++) {
            Pool *pool;
            u8 *e1;
            {
                u8 *e0;
                e0 = *(u8 **)(o + (i << 2) + 18564);
                VCALL1(e0, 24);
                e0 = *(u8 **)(o + (i << 2) + 18564);
                VCALL1(e0, 72);
            }
            e1 = *(u8 **)(o + (i << 2) + 18564);
            pool = (Pool *)(o + 18544);
            VCALL1(e1, 24);
            func_800AACB0(D_800F26E0, e1, 0);
            if (pool->count < pool->cap) {
                VCALL(e1, 8, 2);
                *pool->top = e1;
                pool->top++;
                pool->count++;
            }
        }
        Pool_Free((Pool *)(o + 18544));
        func_800AA658(D_800F2758, o + 18700);
        func_800ADC1C(o + 17692);
        func_800ADC1C(o + 17904);
        func_800ADC1C(o + 18328);
        func_800828B4(o, m->arg);
        break;
    }
    break;
    case 1:
    func_80083700(o, m->arg);
    break;
    case 2:
    b = (u8 *)&m->arg;
    if ((u32)(W(o, 18712) - 1) < 2) {
        u8 c;
        func_800BC07C(P(o, 3868), b[1]);
        c = P(o, 3868)[3];
        if (c & 4) W(o, 18724) = 1;
        if (c & 8) W(o, 18728) = 1;
        if (c & 1) W(o, 18732) = 1;
        if (c & 2) W(o, 18736) = 1;
        if (W(o, 18712) == 2 && (c & 0x10)) func_80072624(o);
        {
        u8 c2 = P(o, 3868)[2];
        if (c2 & 4) W(o, 18724) = 0;
        if (c2 & 8) W(o, 18728) = 0;
        if (c2 & 1) W(o, 18732) = 0;
        if (c2 & 2) W(o, 18736) = 0;
        }
        if (W(o, 18724) && !W(o, 18728)) B(o, 18740) |= 1;
        else if (!W(o, 18724) && W(o, 18728)) B(o, 18740) |= 2;
        else B(o, 18740) &= ~3;
        if (W(o, 18732) && !W(o, 18736)) B(o, 18740) |= 4;
        else if (!W(o, 18732) && W(o, 18736)) B(o, 18740) |= 8;
        else B(o, 18740) &= ~12;
    } else {
        func_800BC07C(P(o, 3868), b[1]);
        if (P(o, 3868)[3]) W(o, 3860) = 1;
    }
    case 5:
    if (dt == 0) return;
    if (D_80072D20 != 0) {
        D_80072D24 += 256;
        if (D_80072D24 > 1920) {
            s32 h = func_8001D4B8(D_800F1AE0, 120, 0, 1);
            Snd_Set(D_800F1AE0, h, 32767);
            D_80072D20 = 0;
            D_80072D24 = 0;
        }
    }
    func_80083A0C(o);
    func_800728BC(o);
        break;
    case 12:
    if (B(o, 18721) != 0) {
        func_800721BC(o);
        B(o, 18721)--;
    }
    }
end:
    W(o, 16) = m->time;
}
