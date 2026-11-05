typedef struct {
    float x, y, z;
} Vec3f;

extern Vec3f D_800742E8;
extern Vec3f D_80074324;
extern void func_800B9FA4(void *, int, int, float, int, int);
extern void func_800B9E9C(void *, int, int, float, int);
extern void func_800AD434(void *, float, int);
extern void func_800AD9E8(void *);
extern void func_800A9BE8(void *, int);

void func_8007515C(char *self)
{
    float k;
    char *obj;
    Vec3f *pos;
    Vec3f *dst;
    char *m;

    k = *(float *)0x800716DC;
    *(unsigned char *)(self + 10336) = 8;
    *(int *)(self + 10340) = 0x12C00;
    func_800B9FA4(self + 2764, 3, -1, k, 0, 0);
    func_800B9E9C(self + 2764, 3, -1, k, 0);
    obj = self + 2784;
    ((Vec3f *)(obj + 64))->x = D_800742E8.x;
    ((Vec3f *)(obj + 64))->y = D_800742E8.y;
    ((Vec3f *)(obj + 64))->z = D_800742E8.z;
    pos = (Vec3f *)(self + 2848);
    pos->x += D_80074324.x;
    pos->y += D_80074324.y;
    pos->z += D_80074324.z;
    dst = (Vec3f *)(self + 3132);
    dst->x = ((Vec3f *)(obj + 64))->x;
    dst->y = ((Vec3f *)(obj + 64))->y;
    dst->z = ((Vec3f *)(obj + 64))->z;
    *(int *)(self + 4400) = *(int *)(self + 272);
    m = self + 4224;
    ((Vec3f *)(m + 64))->x = D_800742E8.x;
    ((Vec3f *)(m + 64))->y = D_800742E8.y;
    ((Vec3f *)(m + 64))->z = D_800742E8.z;
    func_800AD434(m, 3.1415923f, 3);
    func_800AD9E8(self + 4204);
    func_800A9BE8(self + 4660, 4);
}
