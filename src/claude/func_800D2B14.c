typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct VEntry {
    s16 delta;
    s16 pad;
    void (*fn)(void *, void *);
} VEntry;
typedef char assert_ventry[(sizeof(VEntry) == 8) ? 1 : -1];

typedef struct Pos {
    u8 pad0[0x40];
    f32 x;
    f32 y;
    s32 z;
} Pos;

typedef struct Obj {
    u8 pad0[0x60];
    Pos pos;
    u8 padAC[0xB0 - 0xAC];
    u8 active;
    u8 padB1[3];
    VEntry *vtbl;
    u8 padB8[0xD4 - 0xB8];
} Obj;
typedef char assert_obj[(sizeof(Obj) == 0xD4) ? 1 : -1];

typedef struct Sub {
    Obj o;
    s16 unkD4;
    s16 unkD6;
    s16 unkD8;
    u16 unkDA;
} Sub;

typedef struct Ctx {
    u8 pad0[0xD8];
    s32 bit;
} Ctx;

typedef struct Big {
    u8 pad0[0x60];
    Pos pos;
    s32 state;
    u8 padB0[0xD4 - 0xB0];
    s16 x;
    s16 y;
    u8 padD8[0xF0 - 0xD8];
    s32 unkF0;
    u8 padF4[0xF8 - 0xF4];
    u16 mode;
    s16 w;
    Sub sub;
    u8 pad1D8[0x1F4 - 0x1D8];
    s32 saveF0;
    u8 pad1F8[0x210 - 0x1F8];
    Obj elems[4];
    f32 px;
    f32 py;
    u8 pad568[0x570 - 0x568];
    f32 pz;
    u16 flag;
    u16 sel;
} Big;
typedef char assert_big[(sizeof(Big) == 0x578) ? 1 : -1];

extern Ctx *D_800F63F0;
extern void func_800D29E0(Big *);
extern void func_800D6ED0(Sub *, s16 *);
extern void func_800B32D4(Sub *, u8);
extern void func_800ADC54(void *, s32);
extern void func_800D2DB8(Big *);

static inline void activate(Obj *o)
{
    Ctx *c = D_800F63F0;
    o->vtbl[2].fn((char *)o + o->vtbl[2].delta, c);
    func_800ADC54(o, 1 << c->bit);
    o->active = 1;
}

static inline void setpos(Pos *p, f32 x, f32 y)
{
    p->x = x;
    p->y = y;
    p->z = 0;
}

static inline s16 getw(Sub *s)
{
    return s->unkDA;
}

void func_800D2B14(Big *self, s32 arg)
{
    Sub *sub;
    Pos *p;
    u16 t;
    u8 i;

    func_800D29E0(self);
    if (self->sel == 1) {
        self->flag = 0;
    } else {
        self->flag = 0xFF;
    }
    sub = &self->sub;
    sub->unkD8 = -1;
    self->saveF0 = self->unkF0;
    self->unkF0 = 0;
    func_800D6ED0(sub, &self->x);
    self->unkF0 = self->saveF0;
    func_800B32D4(sub, ((u8 *)&self->flag)[1]);
    activate(&sub->o);
    if (self->mode == 3) {
        if (self->w < 0) {
            t = -self->w;
            self->px = (f32)(self->x - ((s16)t >> 1)) - 9.0f;
            self->w = t;
        } else {
            self->px = (f32)(self->x - (getw(sub) >> 1)) - 9.0f;
            self->w = getw(sub);
        }
    } else {
        self->px = (f32)self->x - 9.0f;
    }
    self->py = (f32)self->y - 5.0f;
    setpos(&self->pos, self->px, self->py);
    i = 0;
    while (1) {
        if (i >= 4) {
            break;
        }
        setpos(&self->elems[i].pos, self->px, self->py);
        self->elems[i].active = 1;
        activate(&self->elems[i]);
        i++;
    }
    if ((s16)arg == -1) {
        self->pz = (f32)self->sub.unkD8 + 10.0f;
    } else {
        self->pz = (f32)(s16)arg + 10.0f;
    }
    func_800D2DB8(self);
    self->state = 0;
}
