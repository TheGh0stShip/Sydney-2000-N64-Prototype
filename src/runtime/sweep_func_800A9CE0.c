typedef struct { char pad[6]; unsigned short count; } Frame;
typedef struct { Frame *frame; char **links; } Item;
typedef struct { Item *items; unsigned char count; } Table;
extern char D_800F2758[];
extern void func_800AA804(void *, void *, int, char *);
void func_800A9CE0(Table *t, char **cur)
{
    char *heap = D_800F2758;
    unsigned char i;
    t->count = **cur;
    *cur += 4;
    t->items = 0;
    func_800AA804(heap, t, t->count * 8, "FRAME");
    for (i = 0; i < t->count; i++) {
        unsigned char j;
        t->items[i].frame = (Frame *)*cur;
        *cur += 8;
        t->items[i].links = 0;
        if (t->items[i].frame->count) {
            func_800AA804(heap, &t->items[i].links, t->items[i].frame->count * 4, "FRMELINK");
            for (j = 0; j < t->items[i].frame->count; j++) {
                t->items[i].links[j] = *cur;
                *cur += 4;
            }
        }
    }
}
