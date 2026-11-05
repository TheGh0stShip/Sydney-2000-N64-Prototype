extern unsigned short D_800FF410;
extern void func_800E6F38(void *object, void *entry);
extern void func_800E6D4C(void *object, void *entry);
extern void func_800E7534(void *object, void *entry);

void func_800E755C(void *object, unsigned char *entry)
{
    func_800E6F38(object, entry);
    func_800E6D4C(object, entry);
    func_800E7534(object, entry);
    D_800FF410 = *(unsigned short *)(entry + 24);
}
