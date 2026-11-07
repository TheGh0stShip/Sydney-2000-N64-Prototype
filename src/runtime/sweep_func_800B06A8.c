typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef struct { u8 pad[4]; s32 flags; } Info;
typedef struct { u8 pad[192]; s32 flags; } Node;
typedef struct Obj {
    u8 pad0[8];
    struct Obj *child;
    struct Obj *next;
    u8 pad1[192 - 16];
    s32 flags192;
    s32 f196;
    u8 pad2[220 - 200];
    Info *info;
    u8 pad3[260 - 224];
    Node sub;
    s32 f456;
    u8 pad4[684 - 460];
    s32 col;
    u8 pad5[784 - 688];
    s32 f784;
    u8 pad6[796 - 788];
    u8 r;
    u8 g;
    u8 b;
    u8 c799;
    u8 c800;
    u8 c801;
    u8 pad7[2];
    s32 f804;
    s32 mode;
    u8 pad8[852 - 812];
    s32 f852;
} Obj;
void func_800191E0(void *p, u32 c);
void func_800C19DC(Obj *o);
void func_800C3D20(Obj *o);
static inline void clrf(Node *n, s32 m)
{
    n->flags &= ~m;
}
static inline void setf(Node *n, s32 m)
{
    n->flags |= m;
}
static inline s32 more(Obj *c)
{
    return c != 0;
}
void func_800B06A8(Obj *o, s32 on)
{
    s32 fl = o->info->flags;
    Obj *c;
    if (fl & 0x200000) {
        on = 1;
    }
    if (fl & 0x10000) {
        if (o->f196 == 0) {
            return;
        }
        if (on) {
            clrf(&o->sub, 4);
        } else if (o->f784 == 0) {
            setf(&o->sub, 4);
        }
        if (o->info->flags & 0x80000) {
            func_800191E0(&o->f456, 0xC8DC1414);
        } else {
            func_800191E0(&o->f456, 0xFFFFFF40);
        }
        return;
    }
    c = o->child;
    if (c == 0) {
        return;
    }
    if (on) {
        while (more(c)) {
            if (c->flags192 & 0x10000) {
                c->flags192 |= 0x80000;
            }
            c = c->next;
        }
        if (o->f852 & 2) {
            func_800C19DC(o);
        }
        if (o->f852 & 1) {
            if ((u32)(o->mode - 3) < 2) {
                o->g = 255;
                o->r = 255;
                o->b = 64;
                o->c799 = 220;
                o->c800 = 170;
                o->c801 = 70;
                o->f804 = 0;
                func_800191E0(&o->col, o->b | (o->g << 8) | (o->r << 16) | 0xFF000000);
                o->mode = 1;
            }
        }
    } else {
        if (o->f784 != 0) {
            return;
        }
        if (fl & 0x80000) {
            if (o->f852 & 2) {
                func_800C3D20(o);
            }
            return;
        }
        while (more(c)) {
            if (c->flags192 & 0x10000) {
                c->flags192 &= ~0x80000;
            }
            c = c->next;
        }
        if (o->f852 & 2) {
            func_800C3D20(o);
        }
        if (o->f852 & 1) {
            o->f456 = o->col;
        }
    }
}
