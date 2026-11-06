typedef float f32;
typedef struct { f32 x, y, z; } Vec3;

extern int D_800F267C;
extern unsigned int D_800F2714;

extern void func_800AD434(void *mtx, f32 angle, int axis);
extern void func_800AD2A8(void *mtx, f32 *in, f32 *out, int flag);
extern void func_800AC9B8(f32 *pos, void *mtx, int arg);
extern void func_800AD9E8(void *obj);
extern void func_800B9FA4(void *obj, int anim, int a2, f32 speed, int a4, int a5);
extern void func_800B9E9C(void *obj, int anim, int a2, f32 speed, int a4);
extern void func_800B7578(void *obj, int a1, int a2, int a3, int a4, f32 a5, int a6, int a7);
extern void func_800B9DD0(void *obj, int a1, int a2);
extern void func_800B9CDC(void *obj, int a1, int a2);

static inline unsigned int ceremony_random(int range)
{
    D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
    return ((D_800F2714 >> 15) * range) >> 16;
}

static inline void vcopy(Vec3 *d, Vec3 *s)
{
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

void func_800714C4(char *self, int index)
{
    f32 mtx[20];
    Vec3 in;
    f32 pad;
    Vec3 out;
    f32 *m;
    char *obj;
    char **slot;
    Vec3 *p;
    Vec3 *q;
    f32 one;

    in.x = *(f32 *)0x800708B8;
    out.x = *(f32 *)0x800708B8;
    m = mtx;
    in.y = 0;
    in.z = 0;
    out.y = 0;
    out.z = 0;
    one = *(f32 *)0x800708C4;
    m[9] = 0;
    m[8] = 0;
    m[6] = 0;
    m[4] = 0;
    m[2] = 0;
    m[1] = 0;
    m[18] = 0;
    m[17] = 0;
    m[16] = 0;
    m[10] = one;
    m[5] = one;
    m[0] = one;
    func_800AD434(m, (f32)index * *(f32 *)0x800708BC * *(f32 *)0x800708C0, 3);
    func_800AD2A8(m, (f32 *)&in, (f32 *)&out, 0);
    slot = (char **)self + index;
    vcopy((Vec3 *)(slot[51] + 368), &out);
    vcopy((Vec3 *)(slot[51] + 392), (Vec3 *)(slot[51] + 368));
    func_800AC9B8((f32 *)&out, slot[51] + 20, D_800F267C);
    func_800AD434(slot[51] + 20, 3.1415922f, 3);
    {
        f32 *mt = (f32 *)(slot[51] + 20);
        Vec3 *p = (Vec3 *)(slot[51] + 368);
        mt[16] = p->x;
        mt[17] = p->y;
        mt[18] = p->z;
    }
    func_800AD9E8(slot[51]);
    func_800B9FA4(*(char **)((char *)slot + 204), ceremony_random(9), -1, one, 0, 1);
    func_800B9E9C(*(char **)((char *)slot + 204), ceremony_random(9), -1, one, 0);
    if (((signed char *)(self + index))[256] == 9) {
        func_800B7578(slot[51], 0, 33, 0, -1, one, 0, 1);
        func_800B9DD0(slot[51], 0, -33);
        func_800B9CDC(slot[51], 0, 4);
    }
}
