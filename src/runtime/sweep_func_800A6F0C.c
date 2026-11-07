typedef struct { float x, y, z; } Vec;
typedef struct {
    char pad0[196]; Vec *pts; char state;
} Obj;
extern char D_800F2758[];
extern int func_800AA804(void *, void *, int, char *);
static inline void vset(Vec *v, float x, float y, float z) { v->x = x; v->y = y; v->z = z; }
void func_800A6F0C(Obj *o)
{
    o->state = 2;
    if (func_800AA804(D_800F2758, &o->pts, 72, "CROWD_SECTIONS")) {
        o->state = 0;
        return;
    }
    vset(&o->pts[0], -2949.0298f, 262.136f, -1638.3499f);
    vset(&o->pts[1], -2949.0298f, 262.136f, 1638.3499f);
    vset(&o->pts[2], -1966.0199f, 0.0f, 1638.3499f);
    vset(&o->pts[3], 2949.0298f, 262.136f, 1638.3499f);
    vset(&o->pts[4], 2949.0298f, 262.136f, -1638.3499f);
    vset(&o->pts[5], 1966.0199f, 0.0f, -1638.3499f);
}
