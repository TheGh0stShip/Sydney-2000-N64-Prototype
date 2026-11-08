typedef struct { void *ptr; int type; int mask; } Bind;
typedef struct { char pad0[4]; int flags; char pad1[20]; Bind *bind; } Cfg;
typedef struct { char pad0[196]; int handle; char pad1[20]; Cfg *cfg; } Obj;
extern void func_800191E0(int *, unsigned int);
void func_800B0E3C(Obj *o)
{
    Bind *b = o->cfg->bind;
    int v = 0;
    switch (b->type) {
    case 0: v = *(int *)b->ptr; break;
    case 1: v = *(short *)b->ptr; break;
    case 2: v = *(signed char *)b->ptr; break;
    }
    if (v & b->mask) {
        if ((o->cfg->flags & 0x10000) && o->handle) func_800191E0(&o->handle, 0xC8FFFFFF);
        o->cfg->flags &= ~0x2000000;
    } else {
        if ((o->cfg->flags & 0x10000) && o->handle) func_800191E0(&o->handle, 0xC8808080);
        o->cfg->flags |= 0x2000000;
    }
}
