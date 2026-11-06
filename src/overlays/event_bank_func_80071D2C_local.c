typedef struct { char pad[5]; signed char kind[1]; } Tbl;
typedef struct { char data[212]; } Elem;
typedef struct {
    char pad0[17124];
    Tbl *tbl;
    char pad1[17148 - 17124 - 4];
    Elem *slot[1];
    char pad2[17205 - 17148 - 4];
    unsigned char next[3];
    char pad3[17216 - 17205 - 3];
    struct { Elem *base; int n; } pool[3];
    char pad4[17556 - 17216 - 24];
    int count;
} Obj;

void func_80071D2C(Obj *o)
{
    unsigned char i;

    for (i = 0; i < o->count; i++) {
        switch (o->tbl->kind[i]) {
        case 0:
            break;
        case 1:
            o->slot[i] = &o->pool[0].base[o->next[0]++];
            break;
        case 2:
            o->slot[i] = &o->pool[1].base[o->next[1]++];
            break;
        case 3:
            o->slot[i] = &o->pool[2].base[o->next[2]++];
            break;
        }
    }
}
