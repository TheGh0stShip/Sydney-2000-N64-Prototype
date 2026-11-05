/* Fade step: state 1 ramps the level up to its target, state 2 ramps it down
 * to zero and raises the finished flag; either way the level is re-applied. */
typedef struct Sub {
    char pad[192];
    int flags;
} Sub;

typedef struct Obj {
    char pad[184];
    Sub sub;
    char pad2[404 - 184 - 196];
    float level;
    float target;
    unsigned char state;
} Obj;

extern void func_800C0C48(Obj *o);

void func_800C0C88(Obj *o)
{
    float v;
    Sub *s;

    switch (o->state) {
    case 0:
        return;
    case 1:
        o->level += 47.0f;
        v = o->level;
        if (o->target <= v) {
            o->state = 0;
            o->level = v = o->target;
        }
        break;
    case 2:
        o->level -= 47.0f;
        if (o->level <= 0.0f) {
            o->state = 0;
            o->level = 0.0f;
            s = &o->sub;
            s->flags |= 4;
        }
        break;
    default:
        return;
    }
    func_800C0C48(o);
}
