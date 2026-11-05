extern void func_800ADE84(void *object, int mode);
extern void func_800E57A4(void *object, int mode);
extern void func_800A63CC(void *object, int flags);
extern char D_8007E368[];
extern char D_8008BE48[];

void func_80118BF8(unsigned char *object, int flags)
{
    unsigned char *sub;

    *(void **)(object + 180) = D_8007E368;
    sub = object + 736;
    *(void **)(sub + 180) = D_8008BE48;
    func_800ADE84(sub, 2);
    func_800E57A4(object + 196, 2);
    func_800A63CC(object, flags);
}
