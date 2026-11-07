typedef struct { int v; int pad; } Tmp;
typedef struct {
    char p0[0x17C]; int a;
    char p1[0x250 - 0x180]; int b;
    char p2[0x324 - 0x254]; int c;
    char p3[0x4DC - 0x328]; char va[0x4F4 - 0x4DC]; char vb[0x50C - 0x4F4];
    char ma[0x5E8 - 0x50C]; char mb[0x6C4 - 0x5E8];
    unsigned int ra; unsigned int rb;
    char p4[0x6D4 - 0x6CC]; float fb; float fa;
} Obj;
extern void func_8001A1D8(Tmp *, float, float, float, float);
extern int func_800B31DC(void);
extern void func_800B31EC(int);
extern int func_800B31F8(void);
extern void func_800B3208(int);
extern void func_800B3254(void *, int);
extern void func_800B360C(void *, void *);

void func_800C76BC(Obj *o)
{
    Tmp t;
    float s, p;
    int m, l;
    if (o->a == 0) return;
    p = 0.0f;
    s = o->fa * 413.0f;
    t.v = o->a;
    func_8001A1D8(&t, p, p, s, 10.0f);
    m = func_800B31DC();
    l = func_800B31F8();
    func_800B31EC(1);
    func_800B3208(56);
    o->ra = o->fa * 100.0f;
    func_800B360C(o->ma, o->va);
    func_800B3254(o->ma, 0x80000);
    func_800B31EC(m);
    p = s;
    s = o->fb * 413.0f;
    t.v = o->b;
    func_8001A1D8(&t, p, 0.0f, s, 10.0f);
    m = func_800B31DC();
    func_800B31EC(1);
    func_800B3208(56);
    o->rb = o->fb * 100.0f;
    func_800B360C(o->mb, o->vb);
    func_800B3254(o->mb, 0x80000);
    func_800B31EC(m);
    func_800B3208((unsigned short)l);
    p = s;
    s = 413.0f;
    t.v = o->c;
    func_8001A1D8(&t, p, 0.0f, s, 10.0f);
}
