typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef float f32;
typedef struct { u16 type; s16 x, y, z; u16 ang; u16 idx; u16 pad; } Ent;
typedef struct { u8 pad[6]; u16 count; Ent e[1]; } Hdr;
extern void *D_8007EBFC[];
extern Hdr *D_8007EBD4;
extern u8 D_800F2758[];
extern void func_80005A3C(void *, void *, void *, s32);
extern f32 func_8002EFF0(f32);
extern f32 func_8002E810(f32);
void func_8007E7F0(s32 a0, u8 id, f32 *out)
{
    Ent *e;
    s32 n;
    f32 *o;
    f32 *d;
    f32 a;
    f32 dx, dz;
    func_80005A3C(D_8007EBFC[id], &D_8007EBD4, D_800F2758, 1);
    e = D_8007EBD4->e;
    n = D_8007EBD4->count;
    while (1) {
        if (n == 0) break;
        if (e->type == 3) {
            a = 6.2831845f - e->ang * 9.58738e-5f;
            o = out + e->idx * 9;
            o[6] = func_8002EFF0(a);
            o[7] = 0.0f;
            o[8] = func_8002E810(a);
            d = o + 6;
            dx = d[0] * 65.534f;
            dz = d[2] * 65.534f;
            o[3] = o[0] = e->x;
            o[4] = o[1] = e->y;
            o[5] = o[2] = e->z;
            o[0] += dx;
            o[2] += dz;
            o[3] -= dx;
            o[5] -= dz;
        }
        e++;
        n--;
    }
}
