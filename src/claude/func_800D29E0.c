typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef struct VEntry {
    s16 delta;
    s16 pad;
    void (*fn)(void *);
} VEntry;
typedef char assert_ventry[(sizeof(VEntry) == 8) ? 1 : -1];

typedef struct Obj {
    u8 pad0[0xB0];
    u8 active;
    u8 padB1[3];
    VEntry *vtbl;
    u8 padB8[0xD4 - 0xB8];
} Obj;
typedef char assert_obj[(sizeof(Obj) == 0xD4) ? 1 : -1];

typedef struct Big {
    u8 pad0[0xAC];
    s32 state;
    u8 padB0[4];
    VEntry *vtbl;
    u8 padB8[0xC4 - 0xB8];
    s32 unkC4;
    u8 padC8[0xFC - 0xC8];
    Obj sub;
    u8 pad1D0[0x1FC - 0x1D0];
    void *res;
    void *bufs[4];
    Obj elems[4];
} Big;
typedef char assert_big[(sizeof(Big) == 0x560) ? 1 : -1];

extern void func_800D6EA0(Obj *);
extern void func_8001A248(void *);

static inline void deactivate(Obj *o)
{
    o->vtbl[3].fn((char *)o + o->vtbl[3].delta);
    o->active = 0;
}

void func_800D29E0(Big *self)
{
    Obj *sub;
    VEntry *vt;
    u8 i;

    self->vtbl[9].fn((char *)self + self->vtbl[9].delta);
    sub = &self->sub;
    func_800D6EA0(sub);
    deactivate(sub);
    i = 0;
loop:
    if (i < 4) {
        deactivate(&self->elems[i]);
        vt = (i + self->elems)->vtbl;
        vt[9].fn((char *)&self->elems[i] + vt[9].delta);
        i++;
        goto loop;
    }
    if (self->res != 0) {
        func_8001A248(&self->bufs[0]);
        func_8001A248(&self->bufs[1]);
        func_8001A248(&self->bufs[2]);
        func_8001A248(&self->bufs[3]);
        if (self->res != 0) {
            func_8001A248(&self->res);
            self->unkC4 = 0;
        }
    }
    self->state = 5;
}
