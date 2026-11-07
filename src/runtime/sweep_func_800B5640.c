typedef struct { int ticks; int pad[5]; int time; } Clock;
typedef struct {
    int flags; char pad0[36]; int model; char pad1[4]; char data[40];
    float f88; float f92; float f96; unsigned short h100;
} Desc;
typedef struct {
    char pad0[188]; int x188; char pad1[4]; unsigned short h196; char pad2[2];
    float f200; float f204; char pad3[16]; int t224; int t228; int t232; char pad4[8];
    float f244; float f248; float f252; char pad5[36]; char motion[4];
} Obj;
extern Clock D_800F272C;
extern void func_800B3870(void *, void *, int);
extern void func_800AEB68(void *, int);
extern void func_800AE9DC(void *, float, Obj *);
void func_800B5640(Obj *o, Desc *d)
{
    if (d->flags & 0x20) {
        func_800B3870(&o->f204, d->data, 32);
        if (!o->t232) o->x188 = 0;
        o->t232 += D_800F272C.time;
        o->t224 += D_800F272C.time;
        o->t228 += D_800F272C.time;
        o->f200 = o->f204;
    }
    if (d->flags & 8) {
        func_800AEB68(o->motion, d->model);
        func_800AE9DC(o->motion, 0.0f, o);
    }
    if (d->flags & 0x200) o->f244 = d->f92;
    if (d->flags & 0x400) o->h196 = d->h100;
    if (d->flags & 0x800) o->f252 = d->f96;
    if (d->flags & 0x100) o->f248 = d->f88;
}
