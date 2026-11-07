typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

typedef struct {
    char pad0[2];
    u16 t;
    char pad4[36];
} Entry;

typedef struct {
    char pad0[0x1C];
    Entry *e;
} Tbl;

typedef struct {
    char pad0[0xF4];
    Tbl *tbl;
    char padF8[4];
    u16 cur;
    char padFE[10];
    int idx;
} Sub;

typedef struct {
    char pad0[0x11C8];
    Sub sub;
    char pad12D4[0x44B4 - 0x11C8 - sizeof(Sub)];
    u8 a;
    char pad44B5[2];
    u8 b;
    char pad44B8[12];
    int val;
    char pad44C8[2];
    u16 len;
} State;

void func_80071764(State *st)
{
    Sub *s = &st->sub;
    u16 d = s->cur - s->tbl->e[s->idx].t;
    f32 r = (f32)d / (f32)st->len;
    f32 f;

    r = 1.0f - r;
    f = (r * 0.9f + 0.1f) * 7680.0f;
    st->a = 0;
    st->b = 1;
    st->val = f;
}
