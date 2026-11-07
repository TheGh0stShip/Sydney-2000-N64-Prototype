typedef unsigned char u8;
typedef signed char s8;
typedef float f32;
typedef struct { u8 pad[64]; f32 x; f32 y; f32 z; u8 pad2[136]; } Part;
typedef struct {
    u8 pad0[236];
    f32 f236;
    u8 pad1[12];
    u8 b252;
    s8 i253;
    s8 i254;
    u8 pad2[4668 - 255];
    Part parts[4];
} Obj;
extern f32 D_800F2360[];
extern f32 D_800F2378[];
static inline void set_part_pos(Part *p, f32 x, f32 y, f32 z)
{
    p->x = x;
    p->y = y;
    p->z = z;
}
void func_800A4E30(Obj *o)
{
    if (o->b252 == 0) {
        set_part_pos(&o->parts[0], D_800F2378[o->i254], D_800F2360[o->i253] - 16.0f - o->f236, 0.0f);
        set_part_pos(&o->parts[1], D_800F2378[o->i254], D_800F2360[o->i253] + 16.0f + o->f236, 0.0f);
    }
    set_part_pos(&o->parts[3], 47.0f, D_800F2360[o->i253] - 16.0f, 0.0f);
}
