extern char D_80085FC8[];
extern void func_800AC3D4(void *obj);
extern void func_800AED80(void *obj);
extern void func_800AE4FC(void *obj);

void *func_800AE568(char *obj)
{
    func_800AC3D4(obj);
    *(void **)(obj + 0xB4) = D_80085FC8;
    func_800AED80(obj + 0x124);
    func_800AE4FC(obj);
    return obj;
}
