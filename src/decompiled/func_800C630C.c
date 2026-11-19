#include "sydney_types.h"

/* Shot at goal: scales the shot onto the goal plane, ranks it against 10 thresholds, and either launches the next ball and scores, or plays the miss sound. */
typedef struct Vec3 { f32 x, y, z; } Vec3;

typedef struct Xform {
    u8 pad00[0x40];
    Vec3 pos;
} Xform;

struct Ball;
struct Game;

typedef struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
} VEntry;

typedef struct Ball {
    u8 pad00[0x14];
    Xform xf;
    u8 pad60[0xB4 - 0x60];
    VEntry *vtbl;
} Ball;

typedef struct Snd {
    u8 pad00[0x68];
    s32 volume;
} Snd;

typedef struct Game {
    u8 pad000[0x54];
    Vec3 eye;
    u8 pad060[0xEC - 0x60];
    Ball *balls[32];
    u8 cur;
    u8 pad16D[0x178 - 0x16D];
    f32 thresholds[10];
    u16 score;
} Game;

extern Vec3 D_800723E0;
extern u8 D_800723F8[];
extern Snd D_800F1AE0;

s32 func_8001D4B8(Snd *snd, s32 id, s32 a, s32 b);
void func_8001D640(Snd *snd, s32 voice, s32 vol);
f32 func_800AD7D0(Vec3 *v);
void func_800AD9E8(Ball *b);

static inline void snd_play(Snd *snd, s32 id, s32 vol) {
    func_8001D640(snd, func_8001D4B8(snd, id, 0, 1), (snd->volume * vol) >> 15);
}

static inline void vec_copy(Vec3 *d, Vec3 *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

static inline void vec_sub(Vec3 *d, Vec3 *a, Vec3 *b) {
    d->x = a->x - b->x;
    d->y = a->y - b->y;
    d->z = a->z - b->z;
}

static inline void vec_scale(Vec3 *d, Vec3 *s, f32 k) {
    d->x = s->x * k;
    d->y = s->y * k;
    d->z = s->z * k;
}

static inline void xf_set_pos(Xform *xf, Vec3 *v) {
    xf->pos.x = v->x;
    xf->pos.y = v->y;
    xf->pos.z = v->z;
}

s32 func_80071C4C(Game *g, Vec3 *shot) {
    Vec3 eye;
    Vec3 p;
    Vec3 d1;
    Vec3 d3;
    Vec3 d2;
    Vec3 r;
    f32 len1;
    f32 len2;
    f32 len3;
    f32 dist;
    f32 k;
    u8 i;
    u8 rank;
    Ball *b;

    vec_copy(&eye, &g->eye);
    eye.z -= 5.0788846f;
    vec_sub(&d1, &D_800723E0, &eye);
    len1 = func_800AD7D0(&d1);
    vec_copy(&p, &eye);
    p.z = shot->z;
    vec_sub(&d2, &D_800723E0, &p);
    len2 = func_800AD7D0(&d2);
    vec_sub(&d3, &p, shot);
    len3 = func_800AD7D0(&d3);
    dist = len3 / len2 * len1;
    k = dist / len3;
    shot->y -= 39.3204f;
    vec_scale(&r, shot, k);
    r.z = eye.z;
    shot->y += 39.3204f;
    r.y += 39.3204f;
    rank = 0;
    for (i = 0; i < 10; i++) {
        if (g->thresholds[i] < dist) {
            rank++;
        }
    }
    if (rank < 10) {
        xf_set_pos(&g->balls[g->cur]->xf, &r);
        b = g->balls[g->cur];
        ((void (*)(Ball *, Game *)) b->vtbl[2].fn)((Ball *) ((u8 *) b + b->vtbl[2].delta), g);
        b = g->balls[g->cur];
        ((void (*)(Ball *)) b->vtbl[8].fn)((Ball *) ((u8 *) b + b->vtbl[8].delta));
        func_800AD9E8(g->balls[g->cur]);
        g->cur++;
        if (g->cur == 32) {
            g->cur = 0;
        }
        g->score += D_800723F8[rank];
        snd_play(&D_800F1AE0, 0xDA, 0x7FFF);
        return 1;
    }
    snd_play(&D_800F1AE0, 0xDB, 0x7FFF);
    return 0;
}
