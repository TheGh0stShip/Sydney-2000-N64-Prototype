typedef struct { float x, y, z; } Vec;
typedef struct {
    int flags;
    Vec pos;
    Vec b;
    Vec a;
    int f28;
    int f2c;
    char blk[0x50 - 0x30];
    float f50;
    char pad54[0x58 - 0x54];
    float f58;
    float f5c;
    float f60;
    unsigned short h64;
} Desc;
typedef struct { char pad[0x18]; int step; } Clock;
typedef struct { char pad[0x40]; Vec pos; } Body;
static inline void set_pos(Body *b, Vec *v) { b->pos.x = v->x; b->pos.y = v->y; b->pos.z = v->z; }

extern Clock D_800F272C;
extern void func_800B3870(void *d, void *s, int n);
extern void func_800AEB68(void *p, int v);
extern void func_800B4B40(char *o, void *p, int v);

void func_800B5AE4(char *o, Desc *d)
{
    Vec *dst;
    Vec *src;
    Clock *c;

    if (d->flags & 1) {
        set_pos((Body *)(o + 0x14), &d->pos);
    }
    if (d->flags & 2) {
        dst = (Vec *)(o + 0x1C8);
        src = &d->b;
        dst->x = src->x; dst->y = src->y; dst->z = src->z;
    }
    if (d->flags & 0x20) {
        func_800B3870(o + 0xCC, d->blk, 0x20);
        if (*(int *)(o + 0xE8) == 0) {
            *(int *)(o + 0xBC) = 0;
        }
        c = &D_800F272C;
        *(int *)(o + 0xE8) += c->step;
        *(int *)(o + 0xE0) += c->step;
        *(int *)(o + 0xE4) += c->step;
        *(float *)(o + 0xC8) = *(float *)(o + 0xCC);
    }
    if (d->flags & 0x40) {
        *(float *)(o + 0x1C4) = d->f50;
    }
    if (d->flags & 0x10) {
        func_800AEB68(o + 0x178, d->f2c);
        func_800B4B40(o, o + 0x178, *(int *)(o + 0x1C4));
    }
    if (d->flags & 0x400) {
        *(unsigned short *)(o + 0xC4) = d->h64;
    }
    if (d->flags & 0x800) {
        *(float *)(o + 0xFC) = d->f60;
    }
    if (d->flags & 0x200) {
        *(float *)(o + 0xF4) = d->f5c;
    }
    if (d->flags & 0x100) {
        *(float *)(o + 0xF8) = d->f58;
    }
}
