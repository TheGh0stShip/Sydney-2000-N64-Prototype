typedef struct { float x, y, z; } Vec;
typedef struct {
    int flags;
    Vec pos;
    Vec b;
    Vec a;
    char pad28[0x30 - 0x28];
    char blk[0x58 - 0x30];
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
extern void func_800B4C2C(char *o, Vec *v);

void func_800B5960(char *o, Desc *d)
{
    Vec *dst;
    Vec *src;
    Clock *c;

    if (d->flags & 1) {
        set_pos((Body *)(o + 0x14), &d->pos);
    }
    if (d->flags & 4) {
        dst = (Vec *)(o + 0x178);
        src = &d->a;
        dst->x = src->x; dst->y = src->y; dst->z = src->z;
    }
    if (d->flags & 2) {
        dst = (Vec *)(o + 0x184);
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
    func_800B4C2C(o, (Vec *)(o + 0x178));
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
