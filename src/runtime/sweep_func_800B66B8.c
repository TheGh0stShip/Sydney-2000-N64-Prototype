typedef unsigned short u16;
typedef signed int s32;
typedef float f32;
typedef struct Vec3 { f32 x, y, z; } Vec3;
typedef struct Sub { char pad[0x40]; Vec3 pos; } Sub;
typedef struct Src {
    s32 flags;
    Vec3 a;
    Vec3 b;
    char pad1C[0x14];
    char blk[0x28];
    f32 f58;
    f32 f5C;
    f32 f60;
    u16 h64;
} Src;
typedef struct G { char pad[0x18]; s32 x18; } G;
extern G D_800F272C;
extern void func_800B3870(void *dst, void *src, s32 n);
static inline void vcpy(Vec3 *d, Vec3 *s)
{
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}
static inline void setpos(Sub *s, Vec3 *v)
{
    s->pos.x = v->x;
    s->pos.y = v->y;
    s->pos.z = v->z;
}
void func_800B66B8(char *o, Src *a)
{
    if (a->flags & 1) {
        setpos((Sub *)(o + 20), &a->a);
    }
    if (a->flags & 2) {
        vcpy((Vec3 *)(o + 384), &a->b);
    }
    if (a->flags & 0x20) {
        func_800B3870(o + 204, a->blk, 32);
        if (*(s32 *)(o + 232) == 0) {
            *(s32 *)(o + 188) = 0;
        }
        *(s32 *)(o + 232) += D_800F272C.x18;
        *(s32 *)(o + 224) += D_800F272C.x18;
        *(s32 *)(o + 228) += D_800F272C.x18;
        *(f32 *)(o + 200) = *(f32 *)(o + 204);
    }
    if (a->flags & 0x400) *(u16 *)(o + 196) = a->h64;
    if (a->flags & 0x800) *(f32 *)(o + 252) = a->f60;
    if (a->flags & 0x200) *(f32 *)(o + 244) = a->f5C;
    if (a->flags & 0x100) *(f32 *)(o + 248) = a->f58;
}
