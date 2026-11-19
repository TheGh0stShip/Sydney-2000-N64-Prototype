#include "sydney_types.h"

/* Builds a screen's four HUD sprites from a small object pool and attaches them to the screen. */
typedef struct { s16 delta; s16 index; void (*fn)(); } VEntry;
typedef struct { VEntry e[9]; } VTable;
typedef struct Sprite {
    s32 unk_00;
    u8 pad04[0xA0 - 0x04];
    f32 unk_A0;
    f32 unk_A4;
    u8 padA8[0xB0 - 0xA8];
    s8 unk_B0;
    u8 padB1[3];
    VTable *vt;
    u8 padB8[0xC0 - 0xB8];
    s32 unk_C0;
    s32 unk_C4;
    u8 padC8;
    s8 unk_C9;
    u8 padCA[0xD4 - 0xCA];
} Sprite;
typedef struct {
    void *heap;
    Sprite *buf;
    Sprite **base;
    Sprite **top;
    s16 cap;
    u16 count;
} Pool;
typedef struct {
    u8 pad000[0x2B4];
    Pool pool;
    Sprite *unk_2C8[4];
    u8 pad2D8[0x354 - 0x2D8];
    s32 unk_354;
} Screen;
typedef struct { u8 pad[0xD8]; s32 unk_D8; } Display;

extern u8 D_800884E0[], D_800884E8[], D_800884F0[], D_800884F8[], D_80088500[];
extern u8 D_800F2758[];
extern Display *D_800F63F0;
void func_800191E0(s32 *, s32);
void func_80019680(s32 *, void *);
void func_8001A1D8(s32 *, f32, f32, f32, f32);
void func_8001A210(s32 *, f32, f32, f32, f32, s32);
void func_8001A330(s32 *, s32);
void func_800AA658(void *, void *);
s32 func_800AA804(void *, void *, s32, void *);
s32 func_800AAA58(s32, Sprite *);
void func_800ADC10(Sprite *);
void func_800ADC54(Sprite *, s32);
void func_800ADE10(s32);

static inline Sprite *pool_get(Pool *p) {
    Sprite *s = NULL;
    if (p->top > p->base) {
        p->count--;
        s = *--p->top;
        *p->top = NULL;
        func_800ADE10(func_800AAA58(sizeof(Sprite), s));
    }
    return s;
}

static inline void pool_init(Pool *pool, void *heap) {
    Sprite *p;
    u16 n = 4;

    if (pool->heap == NULL) {
        pool->heap = heap;
        pool->cap = 4;
        if (func_800AA804(heap, &pool->base, 4 * sizeof(Sprite *), D_800884E0) == 0 &&
            func_800AA804(heap, &pool->buf, 4 * sizeof(Sprite), D_800884E8) == 0) {
            p = pool->buf;
            pool->top = pool->base;
            do {
                n--;
                *pool->top = p;
                p++;
                pool->top++;
                pool->count++;
            } while (n);
        } else if (pool->heap != NULL) {
            void *h = pool->heap;
            pool->heap = NULL;
            if (pool->buf != NULL) {
                func_800AA658(h, &pool->buf);
            }
            if (pool->base != NULL) {
                func_800AA658(h, &pool->base);
            }
            pool->cap = 0;
            pool->count = 0;
            pool->top = NULL;
            pool->heap = NULL;
        }
    }
}

static inline void vcall8(Sprite *s) {
    ((void (*)(void *))s->vt->e[8].fn)((u8 *)s + s->vt->e[8].delta);
}

void func_800C0DF0(Screen *scr) {
    Pool *pool;
    Sprite *s;
    s32 h;
    u8 i;
    VTable *vt;

    h = 0;
    pool_init(&scr->pool, D_800F2758);
    pool = &scr->pool;

    s = pool_get(pool);
    scr->unk_2C8[1] = s;
    func_80019680(&h, D_800884F0);
    func_8001A1D8(&h, 0.0f, 0.0f, 14.0f, 15.0f);
    func_8001A210(&h, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&h, -1);
    s->unk_C9 = 4;
    s->unk_C0 |= 0x20000;
    func_800ADC54(s, 1 << D_800F63F0->unk_D8);
    func_800ADC10(s);
    s->unk_C0 |= 2;
    s->unk_C4 = h;
    vcall8(s);

    h = 0;
    s = pool_get(pool);
    scr->unk_2C8[2] = s;
    s->unk_00 = 0x3F;
    func_80019680(&h, D_800884F8);
    func_8001A1D8(&h, 173.0f, 0.0f, 187.0f, 15.0f);
    func_800ADC10(s);
    func_8001A210(&h, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&h, -1);
    s->unk_C9 = 4;
    s->unk_C0 |= 0x20000;
    func_800ADC54(s, 1 << D_800F63F0->unk_D8);
    s->unk_C0 |= 2;
    s->unk_C4 = h;
    vcall8(s);

    h = 0;
    s = pool_get(pool);
    scr->unk_2C8[3] = s;
    s->unk_00 = 0x3F;
    func_8001A330(&h, 0xFFFF);
    func_8001A1D8(&h, 23.0f, 4.0f, 164.0f, 6.0f);
    func_8001A210(&h, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&h, -1);
    s->unk_C9 = 3;
    s->unk_C0 |= 0x20000;
    func_800ADC54(s, 1 << D_800F63F0->unk_D8);
    s->unk_C0 |= 2;
    s->unk_C4 = h;
    vcall8(s);

    h = 0;
    s = pool_get(pool);
    scr->unk_2C8[0] = s;
    func_80019680(&h, D_80088500);
    func_8001A1D8(&h, 0.0f, 2.0f, 11.0f, 8.0f);
    func_8001A210(&h, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&h, -1);
    s->unk_C9 = 4;
    s->unk_C0 |= 0x20000;
    func_800ADC54(s, 1 << D_800F63F0->unk_D8);
    s->unk_C0 |= 2;
    s->unk_C4 = h;
    vcall8(s);

    i = 0;
    do {
        s = scr->unk_2C8[i];
        ((void (*)(void *, Screen *))s->vt->e[2].fn)((u8 *)s + s->vt->e[2].delta, scr);
        i++;
        s->unk_B0 = 1;
        s->unk_A0 = 244.0f;
        s->unk_A4 = -1.0f;
    } while (i < 4);
    scr->unk_354 |= 2;
}
