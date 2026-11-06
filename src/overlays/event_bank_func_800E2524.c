#define FIELD(obj, off, type) (*(type *)((char *)(obj) + (off)))

extern char *D_800FC270;
extern char D_800F3BC0[];
extern void func_800C0110(void *sound, int id, int a, int b);

void func_800E2524(void *obj, int id, int a, int b)
{
    if (FIELD(D_800FC270, 2564, int) != 0 &&
        FIELD(obj, 25320, int) == 1) {
        func_800C0110(D_800F3BC0, id, a, b);
    }
}
