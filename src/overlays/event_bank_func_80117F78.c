extern void func_800E56FC(void *object, int value, int flags);
extern void func_800AC37C(void *object, void *owner);
extern void func_800E55F8(void *object, int mode);
extern void func_800AB2A4(void *list, int value, int mode, void *object, int fourth, int fifth);
extern void func_800A6160(void *object, int arg, int flags);
extern char D_800F26E0[];
extern int D_800F2744;

void func_80117F78(unsigned char *object, int arg, int unused, int value)
{
    func_800E56FC(object + 196, value, 0);
    func_800AC37C(object + 196, object);
    func_800E55F8(object + 196, 3);
    func_800AB2A4(D_800F26E0, D_800F2744, 3, object + 736, 0, 0);
    func_800AC37C(object + 736, object);
    func_800A6160(object, arg, 1);
}
