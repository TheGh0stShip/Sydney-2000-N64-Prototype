typedef struct { char pad[4]; int flags; } Cfg;
typedef struct {
    char pad0[8]; int enabled;
    char pad1[208]; Cfg *cfg;
    char pad2[232]; int handle;
    char pad3[224]; int alt;
    char pad4[108]; unsigned char r, g, b, cr, cg, cb;
    char pad5[2]; float timer; int phase;
    char pad6[40]; int mode;
} Obj;
extern void func_800191E0(int *, unsigned int);
extern int func_800B0A0C(Obj *);
void func_800B08E4(Obj *o)
{
    int h = 0;
    if (o->cfg->flags & 0x10000) h = o->handle;
    if (!o->enabled) return;
    if ((o->mode & 1) && o->alt) h = o->alt;
    if (!h) return;
    func_800191E0(&h, o->b | (o->g << 8) | (o->r << 16) | 0xFF000000);
    o->timer += 0.0333333351f;
    if (!func_800B0A0C(o)) return;
    {
    int ph = o->phase;
    Obj *p;
    switch (ph) {
    case 1:
        p = o;
        p->cr = 220; p->cg = 170; p->cb = 70;
        p->phase = 2;
        break;
    case 2:
        p = o;
        p->cr = 255; p->cg = 255; p->cb = 64;
        p->phase = 1;
        break;
    default:
        return;
    }
    p->timer = 0.0f;
    func_800B0A0C(p);
    }
}
