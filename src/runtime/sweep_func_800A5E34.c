typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef struct { u8 a; u8 type; s16 val; } Slot;
typedef struct {
    u8 pad0[253];
    s8 cur;
    u8 pad1[2];
    s16 lo;
    s16 hi;
    Slot slots[1];
} Obj;
void func_800A5E34(Obj *o, u8 keep)
{
    switch (o->slots[o->cur].type) {
    case 0: o->lo = -1; o->hi = -1; break;
    case 1: o->lo = 0; o->hi = 23; break;
    case 2: o->lo = 24; o->hi = 42; break;
    case 3: o->lo = 43; o->hi = 57; break;
    case 4: o->lo = 58; o->hi = 74; break;
    case 5: o->lo = 75; o->hi = 86; break;
    case 6: o->lo = 87; o->hi = 105; break;
    }
    if (!keep) {
        o->slots[o->cur].val = o->lo;
    }
}
