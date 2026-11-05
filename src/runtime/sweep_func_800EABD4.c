extern void func_800EA638(void *);
extern void func_800EA520(void *);
extern unsigned short func_8000EB20(const char *);
extern void func_80015F98(void *, float, float, unsigned short);
extern void func_80013208(void *, float, float, unsigned short, int);
extern void func_800E9F2C(void *, int, int, void *);
extern char D_800FFD30[];

void func_800EABD4(char *obj)
{
    unsigned int i;

    func_800EA638(D_800FFD30);
    func_800EA520(obj);
    for (i = 0; i < 7; i++) {
        ((int *)(obj + 192))[i] = 0;
    }
    func_80015F98(obj + 192, 29.490301f, 29.490301f, func_8000EB20("SPLASH_3"));
    func_80013208(obj + 196, 39.3204f, 39.3204f, func_8000EB20("SPLASH_3"), 4);
    func_80015F98(obj + 200, 2.9490302f, 2.9490302f, func_8000EB20("BUBBLE_1"));
    func_80015F98(obj + 204, 2.29369f, 2.29369f, func_8000EB20("BUBBLE_1"));
    func_80013208(obj + 212, 39.3204f, 39.3204f, func_8000EB20("RIPPLE_1"), 4);
    func_80013208(obj + 216, 39.3204f, 39.3204f, func_8000EB20("RIPPLE_2"), 4);
    func_80013208(obj + 208, 39.3204f, 39.3204f, func_8000EB20("SPLASH_1"), 4);
    func_800E9F2C(obj + 220, 8, 256, obj);
    func_800E9F2C(obj + 248, 8, 128, obj);
    func_800E9F2C(obj + 276, 8, 128, obj);
    func_800E9F2C(obj + 304, 8, 256, obj);
    func_800E9F2C(obj + 332, 8, 80, obj);
}
