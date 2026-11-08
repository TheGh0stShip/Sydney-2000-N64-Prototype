typedef struct { char pad[13]; signed char parent; char pad2[2]; } Node;
typedef struct { short count; Node *nodes; } Model;
typedef struct { char pad[28]; Model *model; } Inst;
typedef struct { char pad[4]; unsigned short node; char pad2[78]; } Slot;
typedef struct { char pad0[196]; Inst *inst; char pad1[16]; Slot *slots; unsigned char *values; } Obj;
extern void func_800B9D2C(Obj *, unsigned short, unsigned char);
int func_800B7824(Obj *o, unsigned short id)
{
    unsigned short idx = o->slots[id].node;
    Model *m = o->inst->model;
    if (idx && idx < m->count) {
        unsigned char v;
        int i;
        Model *mm;
        v = o->values[m->nodes[idx].parent];
        mm = m;
        o->values[idx] = v;
        for (i = 0; i < mm->count; i++) {
            if (mm->nodes[i].parent == idx) func_800B9D2C(o, i, v);
        }
    }
    o->slots[id].node = 0xFFFF;
    return 0;
}
