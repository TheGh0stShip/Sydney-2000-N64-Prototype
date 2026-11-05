extern void func_800AD9E8(void *obj);

typedef struct {
    char pad[0x54];
    float z;
} Obj;

typedef struct {
    char pad0[17640];
    Obj *objs[241];
    float base[21];
    int count;
} Group;

void func_800BE5E8(Group *g, float offset)
{
    unsigned char i;

    for (i = 0; i < g->count; i++) {
        g->objs[i]->z = g->base[i] + offset;
        func_800AD9E8(g->objs[i]);
    }
}
