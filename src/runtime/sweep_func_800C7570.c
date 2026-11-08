typedef struct {
    char p0[1740];
    float maxA;
    float maxB;
    float a;
    float b;
    char p1[4];
    short done;
    unsigned short flags;
} Obj;

extern void func_800C76BC(Obj *o);

void func_800C7570(Obj *o)
{
    if (o->flags & 8) {
        o->b += 0.033333335f;
        if (o->maxB <= o->b) {
            o->b = o->maxB;
            o->flags &= ~8;
        }
    } else if (o->flags & 0x10) {
        o->b -= 0.033333335f;
        if (o->b <= o->maxB) {
            o->b = o->maxB;
            o->flags &= ~0x10;
        }
    }
    if (o->flags & 2) {
        o->a += 0.033333335f;
        if (o->maxA <= o->a) {
            o->a = o->maxA;
            o->flags &= ~2;
        }
    } else if (o->flags & 4) {
        o->a -= 0.033333335f;
        if (o->a <= o->maxA) {
            o->a = o->maxA;
            o->flags &= ~4;
        }
    }
    if (o->a == o->maxA && o->b == o->maxB) o->done = 0;
    func_800C76BC(o);
}
