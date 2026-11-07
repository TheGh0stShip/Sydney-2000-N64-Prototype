typedef struct { short offset; short pad; void (*fn)(void *); } VEntry;
typedef struct { char pad[64]; VEntry update; } VTable;
typedef struct { char pad0[24]; int a; char pad1[32]; int b; char pad2[32]; int c; } Payload;
typedef struct {
    char pad0[176]; unsigned char ready; char pad1[3]; VTable *vt; char pad2[8]; int flags; int handle;
} Obj;
extern int func_800DAC08(unsigned char);
extern void func_800125DC(int, void *, int *, int);
extern void func_80017C4C(int, int, void **);
extern void func_800B3870(void *, void *, int);
extern void func_80017C3C(int);
extern void func_80017C20(int, int, int, void *);
extern int func_8000EB20(void *);
extern void func_80017CF4(int, int, unsigned short);
extern void func_800ADC54(Obj *, int);
extern char D_800F4880[];
extern char D_800F4884[];
extern Payload D_800F488C;
extern void *D_800F48F8[];
void func_800CB8AC(Obj *o, unsigned char kind, unsigned char sel)
{
    int *h = &o->handle;
    int v;
    void *buf;
    if (sel < 12) v = func_800DAC08(sel);
    else v = -1;
    buf = 0;
    D_800F488C.a = v;
    D_800F488C.b = v;
    D_800F488C.c = v;
    func_800125DC(1, D_800F4880, h, -1);
    func_80017C4C(*h, 0, &buf);
    func_800B3870(buf, &D_800F488C, 108);
    func_80017C3C(*h);
    func_80017C20(*h, 0, 1, D_800F4884);
    func_80017CF4(o->handle, 0, func_8000EB20(D_800F48F8[kind]));
    o->flags |= 2;
    func_800ADC54(o, 1);
    o->ready = 1;
    o->vt->update.fn((char *)o + o->vt->update.offset);
}
