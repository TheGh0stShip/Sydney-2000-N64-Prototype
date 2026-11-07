typedef struct { char p[212]; } A212;
typedef struct {
    char p0[0xD4];
    A212 a[2];
    char p1[8];
    A212 b[10];
    int h[8];
    char p2[0xCA4 - 0xAEC];
    char x3236[0xD80 - 0xCA4];
    char x3456[1];
} Obj;

extern void func_800D2328(Obj *);
extern void func_800D2760(Obj *);
extern void func_800AC334(void *);
extern void func_800CC47C(void *);
extern void func_800B35F0(void *);
extern void func_8001A248(int *);

void func_800D1E80(Obj *o)
{
    func_800D2328(o);
    func_800D2760(o);
    func_800AC334(o->x3456);
    func_800CC47C(o->x3456);
    func_800B35F0(o->x3236);
    func_800AC334(o->x3236);
    func_800AC334(&o->b[6]);
    func_800AC334(&o->b[5]);
    func_800AC334(&o->b[4]);
    func_800AC334(&o->b[9]);
    func_800AC334(&o->b[8]);
    func_800AC334(&o->b[7]);
    func_800AC334(&o->b[3]);
    func_800AC334(&o->b[2]);
    func_800AC334(&o->b[1]);
    func_800AC334(&o->a[1]);
    func_800AC334(&o->a[0]);
    func_800AC334(&o->b[0]);
    if (o->h[7] != 0) { func_8001A248(&o->h[7]); o->h[7] = 0; }
    if (o->h[6] != 0) { func_8001A248(&o->h[6]); o->h[6] = 0; }
    if (o->h[5] != 0) { func_8001A248(&o->h[5]); o->h[5] = 0; }
    if (o->h[4] != 0) { func_8001A248(&o->h[4]); o->h[4] = 0; }
    if (o->h[2] != 0) { func_8001A248(&o->h[2]); o->h[2] = 0; }
    if (o->h[1] != 0) { func_8001A248(&o->h[1]); o->h[1] = 0; }
    if (o->h[3] != 0) { func_8001A248(&o->h[3]); o->h[3] = 0; }
    if (o->h[0] != 0) { func_8001A248(&o->h[0]); o->h[0] = 0; }
}
