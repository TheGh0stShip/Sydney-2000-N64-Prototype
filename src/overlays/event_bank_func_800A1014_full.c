extern void *D_80071320[];
extern char D_800758EC[];
extern void func_800742C8(char *self);
extern void func_8009B80C(char *a, int b, int c, int d);
extern void func_800D33A0(char *a, char *b, int c, int d);
extern void func_80074CF4(char *self, int a, int b, int c);
extern void func_80074A5C(char *self);
extern void func_800A9BE8(char *a, int b);
extern void func_800177EC(void);

void func_800A1014(char *self)
{
    static void *const unused_tbl[] = { &&case0, &&case2, &&done };
    unsigned int state;

    state = self[0x5DE9];
    self[0x5E39] = 0;
    if (state >= 6) {
        goto done;
    }
    goto *D_80071320[state];
case0:
    if (*(int *)(self + 0x5E28) != 1) {
        goto done;
    }
    func_800742C8(self);
    func_8009B80C(self + 13020, 11, (signed char)self[0x5DE6], 2);
    goto done;
case2:
    func_800D33A0(self + 13020, D_800758EC, 1, -1);
    func_80074CF4(self, 28, 0, 0);
done:
    func_80074A5C(self);
    func_800A9BE8(self + 23728, (unsigned char)self[1757]);
    self[24039] = 1;
    *(int *)(self + 24072) = *(int *)(self + 1760);
    func_800177EC();
}
