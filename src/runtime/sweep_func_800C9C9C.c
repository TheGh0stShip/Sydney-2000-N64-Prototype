typedef struct { char p0[88]; float y; char p1[192 - 92]; unsigned int flags; } Item;
typedef struct {
    char p0[204];
    Item *items[40];
    Item sub;
    char p1[585 - 560];
    unsigned char count;
    char p2[604 - 586];
    int state;
    unsigned int flags;
    float tgt;
    float tgt2;
    float base;
} Obj;

static inline void set2(Item *it)
{
    it->flags |= 2;
}

void func_800C9C9C(Obj *o)
{
    float d;
    float step;
    unsigned char i;

    if (o->sub.y < o->tgt) {
        d = o->tgt - o->sub.y;
        d += d;
        if (d < 8.19175f) d = 8.19175f;
        o->sub.y = o->sub.y + d / 30.0f;
        if (o->tgt < o->sub.y) {
            o->sub.y = o->tgt;
            o->flags &= ~1;
            if (!(o->flags & 2)) {
                o->state = 0;
                set2(&o->sub);
            }
        }
    }
    if (o->items[0]->y < o->tgt2) {
        d = o->tgt2 - o->items[0]->y;
        d += d;
        if (d < 20.479374f) d = 20.479374f;
        for (i = 0; i < o->count; i++) o->items[i]->y += d / 30.0f;
        if (o->items[0]->y > o->tgt2) {
            i = 0;
            while (1) {
                if (!(i < o->count)) break;
                step = 49.150497f / o->count;
                o->items[i]->y = o->base;
                o->items[i]->y += i * step;
                o->items[i]->flags |= 2;
                i++;
            }
            o->flags &= ~2;
            if (!(o->flags & 1)) o->state = 0;
        }
    }
}
