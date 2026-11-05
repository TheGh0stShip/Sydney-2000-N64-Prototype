typedef struct {
    float x;
    float y;
    float z;
} Vec3;

extern int func_800B9BD4(void *self, int arg, void *a, void *b, void *c, int flag);
extern void func_800B9E9C(void *self, int target, int index, float scale, int flag);
extern void func_800B9964(void *self, void *a, void *b, void *c);
extern void func_800AD434(void *object, float angle, int mode);
extern void func_800B9480(void *self);
extern void func_800C8278(void *self);

void func_800C8574(unsigned char *self, int arg)
{
    Vec3 a;
    Vec3 c;
    float b[2];

    if (self[778] != 0) {
        if (func_800B9BD4(self, arg, &a, b, &c, 0) != 0) {
            func_800B9E9C(self, *(int *)(self + 752), -1, 1.0f, 0);
        }
        func_800B9964(self, &a, b, &c);
        if (*(int *)(self + 768) != 0) {
            func_800AD434(self + 20, 0.034906581f, 3);
        }
        func_800B9480(self);
    }
    if (--*(int *)(self + 756) == 0) {
        func_800C8278(self);
        *(int *)(self + 192) &= ~4;
    }
}
