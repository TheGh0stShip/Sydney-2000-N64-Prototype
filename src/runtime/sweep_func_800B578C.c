extern void func_800AE568(void *object);
extern void func_800B53A4(void *object);
extern unsigned char D_80086820[];

void *func_800B578C(unsigned char *object)
{
    func_800AE568(object);
    *(void **)(object + 180) = D_80086820;
    func_800B53A4(object);
    return object;
}
