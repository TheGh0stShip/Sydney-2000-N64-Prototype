typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Body {
    char pad[64];
    Vec3 color;
} Body;

typedef struct Unit {
    char pad0[684];
    char slotA[236];
    char slotB[236];
    char sub[96];
    Body body;
    char pad1[912];
    unsigned char lit;
    char pad2[3];
    int state;
} Unit;

extern Vec3 D_800F4BD0;
extern Vec3 D_800F4BDC;
extern char D_800F4CB0[];
extern char D_800F4CD8[];
extern void func_800D6ED0(void *, void *);
extern void func_800B3254(void *, int);
extern void func_800AD9E8(void *);

void func_800D3D34(Unit *unit)
{
    Body *body;

    if (unit->state == 2) {
        return;
    }
    if (unit->lit) {
        body = &unit->body;
        body->color.x = D_800F4BDC.x;
        body->color.y = D_800F4BDC.y;
        body->color.z = D_800F4BDC.z;
        func_800D6ED0(unit->slotA, D_800F4CD8);
        func_800B3254(unit->slotA, 0x80000);
        func_800D6ED0(unit->slotB, D_800F4CB0);
    } else {
        body = &unit->body;
        body->color.x = D_800F4BD0.x;
        body->color.y = D_800F4BD0.y;
        body->color.z = D_800F4BD0.z;
        func_800D6ED0(unit->slotA, D_800F4CB0);
        func_800B3254(unit->slotA, 0x80000);
        func_800D6ED0(unit->slotB, D_800F4CD8);
    }
    func_800AD9E8(unit->sub);
    unit->lit = !unit->lit;
}
