extern unsigned char D_800F1AE0[];
extern unsigned char D_800F1B84[];
extern unsigned char D_800F2758[];
extern int D_800F3884;
extern char D_800C02B4[];
extern char D_80088130[];
extern void func_800A3028(void *bank, void *callback);
extern void func_8001DFF4(void *voice);
extern void func_8001E0F4(void *voice);
extern void func_8001E02C(void *voice);
extern void func_800AA658(void *list, void *node);

void func_800C0168(unsigned char *self)
{
    int enabled;
    unsigned char *list = D_800F2758;

    func_800A3028(D_800F1AE0, D_800C02B4);
    func_8001DFF4(D_800F1B84);
    func_8001E0F4(D_800F1B84);
    func_8001E02C(D_800F1B84);
    if (*(int *)(self + 184) != 0) {
        func_800AA658(list, self + 184);
    }
    self[207] = 0;
    self[208] = 0;
    self[209] = 0;
    self[206] = 0;
    enabled = D_800F3884;
    *(int *)(self + 184) = 0;
    *(int *)(self + 188) = 0;
    *(int *)(self + 192) = 0;
    *(int *)(self + 196) = 0;
    *(short *)(self + 200) = 0;
    *(short *)(self + 202) = 0;
    *(short *)(self + 204) = 0;
    *(int *)self = 54;
    if (enabled == 0) {
        enabled = 1;
    }
    *(int *)(self + 228) = enabled;
    *(void **)(self + 224) = D_80088130;
}
