typedef struct { short offset; short pad; void (*fn)(); } VEntry;
typedef struct { char pad[24]; VEntry update; char pad2[72 - 32]; VEntry draw; } VTable;
typedef struct Obj { char pad[176]; unsigned char active; char pad1[3]; VTable *vt; char pad2[220 - 184]; } Obj;

extern Obj D_801028B0[];
extern void func_800B35F0(Obj *);
extern void func_800ADC1C(Obj *);
extern void func_80017D64(int);

static __inline__ void obj_reset(Obj *o)
{
    o->vt->update.fn((char *)o + o->vt->update.offset);
    o->active = 0;
    func_800ADC1C(o);
}

void func_800D4B30(char *self)
{
    unsigned char i;
    Obj *o;

    for (i = 0; i < 10; i++) {
        o = &D_801028B0[i];
        func_800B35F0(o);
        o->vt->update.fn((char *)o + o->vt->update.offset);
        o->vt->draw.fn((char *)o + o->vt->draw.offset);
    }
    obj_reset((Obj *)(self + 2324));
    obj_reset((Obj *)(self + 2536));
    func_80017D64(0);
}
