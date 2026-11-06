typedef unsigned short u16;
typedef float f32;
typedef struct { char pad[2]; u16 t; char pad2[36]; } Entry;
typedef struct { char pad[0x1c]; Entry *e; } Tbl;
typedef struct { char pad0[0xf4]; Tbl *tbl; char pad1[4]; u16 cur; char pad2[0x108-0xfe]; int idx; } Sub;
typedef struct { char pad0[0x11c8]; Sub sub; char pad3[0x43dc-0x11c8-sizeof(Sub)]; char a; char pad4[2]; char b; char pad5[4]; int val; char pad6[2]; u16 len; } State;
void func_800C4D44(State *st)
{
    Sub *s = &st->sub;
    u16 d = s->cur - s->tbl->e[s->idx].t;
    f32 r = (f32)d / (f32)st->len;
    f32 f;
    int v;
    r = 6.553399562835693359375f - r;
    f = (r * 0.375f) * 39.320400238037109375f;
    st->a = 0;
    st->b = 1;
    v = f;
    st->val = v;
    if (v > 0x2d00) st->val = 0x2d00;
}
