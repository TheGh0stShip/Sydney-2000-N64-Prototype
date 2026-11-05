extern void func_800BC274(void *obj);
extern void func_800AACB0(void *list, void *object, int mode);
extern void func_80099FE4(void *obj);
extern void func_80099728(void *obj);
extern void func_80074920(void *obj, unsigned char index);
extern volatile int D_800F2724;
extern volatile int D_800F2728;
extern unsigned char D_800F2AD8[];
extern unsigned char D_800F26E0[];

void func_80087CC4(unsigned char *object)
{
    unsigned char i;

    D_800F2724 = 0;
    D_800F2728 = 0;
    func_800BC274(D_800F2AD8);
    func_800AACB0(D_800F26E0, 0, 2);
    func_800AACB0(D_800F26E0, 0, 1);
    func_80099FE4(object + 16704);
    func_80099728(object + 16704);
    for (i = 0; i < 8; i++) {
        func_80074920(object, i);
    }
}
