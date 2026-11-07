typedef struct { float x, y, z; } Vec3;
typedef struct { Vec3 p[3]; } Tri;
typedef struct { int a, b, c; } Idx3;
typedef struct { char pad0[16]; int value; char pad1[164]; int active; char pad2[13]; unsigned char ticks; } Obj;
extern void func_800A7610(Obj *, int, Tri *, Idx3 *);
extern void func_800A7910(Obj *);
extern void func_800A8034(Obj *);
void func_800A8580(Obj *o, int *msg)
{
    switch (msg[0]) {
    case 3: {
        Tri tri = { { { 655.339966f, 491.504974f, 2949.02979f },
                      { 819.174927f, 720.873962f, 2949.02979f },
                      { 983.009949f, 491.504974f, 2949.02979f } } };
        Idx3 idx = { 9, 31, 9 };
        func_800A7610(o, 3, &tri, &idx);
        break;
    }
    case 7:
        func_800A7910(o);
        break;
    case 5:
        o->ticks++;
        if (o->active && o->ticks == 2) {
            func_800A8034(o);
            o->ticks = 0;
        }
        break;
    }
    o->value = msg[1];
}
