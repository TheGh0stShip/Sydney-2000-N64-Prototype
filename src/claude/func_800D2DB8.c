typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct Obj {
    u8 pad0[0xC0];
    u32 flags;
    void *res;
    u8 padC8;
    u8 unkC9;
    u8 padCA[0xD4 - 0xCA];
} Obj;
typedef char assert_obj[(sizeof(Obj) == 0xD4) ? 1 : -1];

typedef struct Big {
    u8 pad0[0xC0];
    u32 flags;
    void *resC4;
    u8 padC8;
    u8 unkC9;
    u8 padCA[0xEC - 0xCA];
    s32 unkEC;
    u8 padF0[0xFA - 0xF0];
    s16 w;
    u8 padFC[0x1F4 - 0xFC];
    s32 saveEC;
    u8 pad1F8[0x1FB - 0x1F8];
    u8 unk1FB;
    void *res;
    void *bufs[4];
    Obj elems[4];
    f32 px;
    f32 py;
    f32 h;
    f32 wd;
    f32 pz;
    u16 flag;
    u16 sel;
} Big;
typedef char assert_big[(sizeof(Big) == 0x578) ? 1 : -1];

extern void func_8001A330(void *, s32);
extern void func_8001A1D8(void *, f32, f32, f32, f32);
extern void func_8001A210(void *, f32, f32, f32, f32, s32);
extern void func_800191E0(void *, u32);
extern void func_800D328C(Big *);

static inline void tint(Obj *o, u8 c)
{
    o->flags |= 0x20000;
    o->unkC9 = c;
}

static inline void enable(Obj *o)
{
    o->flags |= 2;
}

void func_800D2DB8(Big *self)
{
    u8 i;

    if (self->sel == 1) {
        self->h = 0.0f;
    } else {
        self->h = self->pz;
    }
    self->wd = (f32)self->w + 18.0f;
    self->saveEC = self->unkEC;
    func_8001A330(&self->res, 0xFFFF);
    func_8001A1D8(&self->res, 1.0f, 1.0f, self->wd - 1.0f, self->h - 1.0f);
    func_8001A210(&self->res, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&self->res, 0xC8002040);
    self->flags |= 0x20000;
    self->resC4 = self->res;
    self->flags |= 2;
    self->unkC9 = self->unk1FB;
    func_8001A330(&self->bufs[0], 0xFFFF);
    func_8001A330(&self->bufs[1], 0xFFFF);
    func_8001A330(&self->bufs[2], 0xFFFF);
    func_8001A330(&self->bufs[3], 0xFFFF);
    func_8001A210(&self->bufs[0], 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_8001A210(&self->bufs[1], 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_8001A210(&self->bufs[2], 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_8001A210(&self->bufs[3], 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_800191E0(&self->bufs[0], 0xFF000000);
    func_800191E0(&self->bufs[1], 0xFF000000);
    func_800191E0(&self->bufs[2], 0xFF000000);
    func_800191E0(&self->bufs[3], 0xFF000000);
    func_800D328C(self);
    i = 0;
    while (1) {
        if (i >= 4) {
            break;
        }
        tint(&self->elems[i], self->unk1FB);
        enable(&self->elems[i]);
        i++;
    }
    self->elems[0].res = self->bufs[0];
    self->elems[1].res = self->bufs[1];
    self->elems[2].res = self->bufs[2];
    self->elems[3].res = self->bufs[3];
}
