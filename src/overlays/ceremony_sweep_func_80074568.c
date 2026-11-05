typedef struct {
    float x, y, z;
} Vec3f;

extern void func_800B97D4(void *, int, void *);
extern void func_800AC5CC(void *, void *, void *, int);
extern void func_800AD9E8(void *);

void func_80074568(char *self)
{
    char mtx[80];
    Vec3f v;
    Vec3f *src;
    Vec3f *src2;
    Vec3f *dst;

    func_800B97D4(self + 1956, 17, mtx);
    func_800AC5CC(mtx, self + 1976, src = (Vec3f *)(self + 3376), 1);
    v.x = src[1].y;
    v.y = src[1].z;
    v.z = src[2].x;
    v.x *= *(float *)0x80071688;
    v.y *= *(float *)0x80071688;
    v.z *= *(float *)0x80071688;
    dst = (Vec3f *)(self + 3440);
    dst->x = v.x + dst->x;
    dst->y = v.y + dst->y;
    dst->z = v.z + dst->z;

    func_800B97D4(self + 2360, 17, mtx);
    func_800AC5CC(mtx, self + 2380, src2 = (Vec3f *)(self + 3588), 1);
    v.x = src2[1].y;
    v.y = src2[1].z;
    v.z = src2[2].x;
    v.x *= *(float *)0x8007168C;
    v.y *= *(float *)0x8007168C;
    v.z *= *(float *)0x8007168C;
    dst = (Vec3f *)(self + 3652);
    dst->x = v.x + dst->x;
    dst->y = v.y + dst->y;
    dst->z = v.z + dst->z;

    func_800AD9E8(self + 3568);
    func_800AD9E8(self + 3356);
}
