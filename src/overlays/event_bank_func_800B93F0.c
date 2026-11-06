/* Event-bank object init (link VRAM 0x80071070), ROM 0xB93F0..0xB97E8. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef float f32;

typedef struct Pool {
    void *heap;
    u8 *items;
    u8 **stack;
    u8 **top;
    u16 cap;
    u16 count;
} Pool;

extern char D_80070E14[];
extern char D_80070E44[];
extern char D_80070E74[];
extern char D_80070EA4[];
extern char D_80070EB4[];
extern char D_80070EC0[];
extern char D_80070EC8[];
extern f32 D_80070ED0;
extern f32 D_80070ED4;
extern f32 D_80070ED8;
extern f32 D_80070EDC;
extern f32 D_80070EE0;
extern char D_80071020[];
extern f32 D_80072E78[];
extern char D_800F2758[];

extern s32 func_80013E7C(char *, void *, s32);
extern s32 func_8000EB20(char *);
extern void func_80013208(void *, f32, f32, s32, s32);
extern s32 func_800AA804(void *, void *, s32, char *);
extern void func_800AA658(void *, void *);
extern u8 *func_800AAA58(s32, u8 *);
extern void func_800ADED4(u8 *);
extern void func_800AED80(u8 *);
extern void func_800ADC54(u8 *, s32);
extern void func_800AD890(u8 *, s32);
extern void func_800AED04(u8 *);
extern void func_800ADC38(u8 *);
extern void func_800AC37C(u8 *, u8 *);
extern void func_800AD434(u8 *, f32, s32);
extern void func_800AD388(u8 *, f32, s32);

#define W(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define P(p, o) (*(u8 **)((u8 *)(p) + (o)))

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

static __inline__ void Pool_Init(Pool *pool, void *heap, u16 n)
{
    if (pool->heap == 0) {
        pool->heap = heap;
        pool->cap = n;
        if (func_800AA804(heap, &pool->stack, n * 4, D_80070EC0) == 0
            && func_800AA804(heap, &pool->items, n * 320, D_80070EC8) == 0) {
            u8 *it = pool->items;
            pool->top = pool->stack;
            do {
                *pool->top = it;
                n--;
                it += 320;
                pool->top++;
                pool->count++;
            } while (n);
        } else {
            Pool_Free(pool);
        }
    }
}

static __inline__ u8 *Obj_New(u8 *mem)
{
    u8 *s = func_800AAA58(320, mem);
    func_800ADED4(s);
    P(s, 180) = D_80071020;
    func_800AED80(s + 212);
    return s;
}

static __inline__ u8 *Pool_Alloc(Pool *pool)
{
    u8 *e = 0;
    if (pool->top > pool->stack) {
        pool->count--;
        pool->top--;
        e = *pool->top;
        *pool->top = 0;
        Obj_New(e);
    }
    return e;
}

static __inline__ void Timer_Set(void *p, f32 v, u16 n)
{
    func_80013208(p, v, v, n, 2);
}

static __inline__ s32 Lt32(u8 x)
{
    return x < 32;
}

void func_800B93F0(u8 *o)
{
    u8 *a;
    u8 *e;
    u8 *s;
    u8 *t;
    u8 i;

    W(o, 17688) = 0;
    W(o, 17664) = func_80013E7C(D_80070E14, o + 17688, 0);
    W(o, 17668) = func_80013E7C(D_80070E44, o + 17688, 0);
    W(o, 17676) = 0;
    W(o, 17680) = func_80013E7C(D_80070E74, o + 17688, 0);
    W(o, 17684) = 0;
    W(o, 17672) = 0;
    Timer_Set(o + 17684, *(const f32 *)0x80070ED0, func_8000EB20(D_80070EA4));
    Timer_Set(o + 17672, *(const f32 *)0x80070ED4, func_8000EB20(D_80070EB4));

    Pool_Init((Pool *)(o + 18544), D_800F2758, 32);

    for (i = 0; Lt32(i); i++) {
        e = Pool_Alloc((Pool *)(o + 18544));
        *(u8 **)(o + (i << 2) + 18564) = e;
        W(e, 196) = W(o, 17664);
        func_800ADC54(*(u8 **)(o + (i << 2) + 18564), 1);
        func_800AD890(*(u8 **)(o + (i << 2) + 18564), 1);
        F(P(P(*(u8 **)(o + (i << 2) + 18564), 208), 8), 40) = *(const f32 *)0x80070ED8;
        func_800AED04(*(u8 **)(o + (i << 2) + 18564) + 212);
        F(*(u8 **)(o + (i << 2) + 18564), 316) = *(const f32 *)0x80070EDC;
        W(*(u8 **)(o + (i << 2) + 18564), 312) = 0;
        W(*(u8 **)(o + (i << 2) + 18564), 300) = 0;
        W(*(u8 **)(o + (i << 2) + 18564), 308) = 0;
        W(*(u8 **)(o + (i << 2) + 18564), 304) = 0;
    }

    a = o + 17904;
    W(o, 18100) = W(o, 17672);
    func_800ADC54(a, 1);
    func_800AD890(a, 1);
    W(a, 192) |= 8;
    func_800ADC38(a);
    func_800AC37C(a, o);

    s = o + 18328;
    W(o, 18524) = W(o, 17680);
    func_800ADC54(s, 1);
    func_800ADC38(s);
    func_800AD890(s, 1);
    F(o, 18368) = *(const f32 *)0x80070EE0;
    s = o + 18348;
    F(s, 64) = D_80072E78[0];
    F(s, 68) = D_80072E78[1];
    F(s, 72) = D_80072E78[2];
    func_800AD434(s, 3.1415922f, 3);
    func_800AD388(s, 1.5707961f, 3);

    t = o + 17692;
    W(t, 192) |= 0x40000A;
    W(o, 17888) = W(o, 17684);
    func_800ADC54(t, 1);
    func_800AD890(t, 1);
    func_800AC37C(t, a);
    o[17868] = 1;
    W(o, 18696) = 0;
}
