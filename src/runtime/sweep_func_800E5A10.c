typedef struct {
    int pad0[3];
    int c;
    int v10[3];
    int v1C[3];
    int v28[3];
    int pad34[3];
    int v40[3];
    int pad4C[6];
} Elem; /* 0x64 */

typedef struct {
    int a;
    int flags;
} Slot;

typedef struct {
    char pad[0xD8];
    int busy;
    int count;
    Elem *elems;
    Slot *slots;
} Owner;

static __inline__ void clear3(int *v) {
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
}

short func_800E5A10(Owner *o) {
    short found = -1;
    int i;

    if (o->busy != 0) {
        return -1;
    }
    i = o->count;
    i--;
    while (i != -1) {
        if (!(o->slots[i].flags & 1)) {
            found = i;
            break;
        }
        i--;
    }
    if (found != -1) {
        o->elems[found].c = 0;
        o->slots[found].flags = 0;
        o->slots[found].a = -7680;
        clear3(o->elems[found].v10);
        clear3(o->elems[found].v1C);
        clear3(o->elems[found].v28);
        clear3(o->elems[found].v40);
    }
    return found;
}
