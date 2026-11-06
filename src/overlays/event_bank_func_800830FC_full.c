typedef unsigned char u8;
typedef struct { int pad[0x344]; int w0d10; } Glob;

extern void func_800EADB4(void *);
extern u8 func_80076B58(void *);
extern void func_80076680(void *, int, int);
extern void func_80076884(void *, float);
extern void func_80076814(void *);
extern void func_8007676C(void *, int, int, int);
extern void func_80099D70(void *, int, float);
extern void func_800CC294(void *, int, int, int);
extern void func_80099B70(void *);
extern void func_800A9BE8(void *, int);
extern u8 D_80077741;
extern Glob *D_800FC270;
extern int D_800F13F0;

#define W(o) (*(int *)(p + (o)))
#define BY(o) (*(u8 *)(p + (o)))

static __inline__ void setq(u8 *p, u8 v)
{
    u8 *q = p + 0x550;
    q[0xB9] = v;
    q[0xB8] = v;
    q[0xBA] = 0;
    q[0xBB] = 0;
}

void func_800830FC(u8 *p)
{
    u8 v;
    u8 *q;
    float f;
    u8 *r;
    int t;

    func_800EADB4(p + 0x54A4);
    W(0x5424) -= 0x100;
    if (W(0x5424) > 0) {
        return;
    }
    BY(0x60C) = func_80076B58(p);
    func_80076680(p, *(int *)(p + (BY(0x60C) << 2) + 0x4120), 1);
    v = BY(0x615);
    if (v == 2) {
        goto tail;
    }
    if (v == 5 || v == 1) {
        func_80076884(p, 65.5340f);
        v = BY(0x614);
        if (v != 1) {
            func_800A9BE8(p + 0x45C, 10);
            setq(p, 1);
        } else {
            func_800A9BE8(p + 0x45C, 7);
            setq(p, v);
        }
        goto tail;
    }
    if (v == 0) {
        func_80076814(p);
        if (D_80077741 != 0) {
            func_8007676C(p, 0x8F, 0, 0);
        }
    } else if (v == 4) {
        f = (float)D_800FC270->w0d10 / *(float *)0x80071058 * *(float *)0x8007105C;
        func_80099D70(p + 0x4140, 7, f);
    } else if (v == 3) {
        f = (float)*(int *)(p + 0x5430) / *(float *)0x80071060 * *(float *)0x80071064;
        func_80099D70(p + 0x4140, 7, f);
    }
    r = p + 0x4140;
    func_800CC294(p + 0x4B44, 0, 0x753000, 1);
    func_80099B70(r);
    func_800A9BE8(p + 0x45C, 4);
    q = p + 0x550;
    q[0xB9] = 1;
    q[0xB8] = 1;
    q[0xBA] = 0;
    q[0xBB] = 0;
tail:
    t = D_800F13F0;
    BY(0x60F) = 9;
    W(0x65C) = t;
}
