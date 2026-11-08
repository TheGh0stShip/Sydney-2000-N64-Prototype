typedef struct { short offset; short pad; void (*fn)(void *); } VEntry;
typedef struct { char pad0[24]; VEntry halt; char pad1[40]; VEntry reset; } VTable;
typedef struct { char pad0[176]; unsigned char active; char pad1[3]; VTable *vt; } Unit;

extern void func_800CE594(void);
extern void func_8001A248(int *p);

static inline void unit_halt(Unit *u)
{
    u->vt->halt.fn((char *)u + u->vt->halt.offset);
    u->active = 0;
}

void func_800CFCCC(Unit *self)
{
    unsigned char i;

    self->vt->reset.fn((char *)self + self->vt->reset.offset);
    func_800CE594();
    i = 0;
    while (1) {
        if (i >= *((unsigned char *)self + 1922)) break;
        unit_halt((Unit *)((char *)self + i * 220 + 4344));
        unit_halt((Unit *)((char *)self + i * 212 + 5464));
        unit_halt((Unit *)((char *)self + i * 212 + 6524));
        unit_halt((Unit *)((char *)self + i * 212 + 7584));
        i++;
    }
    func_8001A248((int *)((char *)self + 5444));
    func_8001A248((int *)((char *)self + 5448));
    func_8001A248((int *)((char *)self + 5456));
    func_8001A248((int *)((char *)self + 5460));
    func_8001A248((int *)((char *)self + 5452));
}
