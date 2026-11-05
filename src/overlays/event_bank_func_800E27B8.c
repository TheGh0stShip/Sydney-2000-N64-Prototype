extern void func_800BC274(void *);
extern void func_800AACB0(void *, int, int);
extern void func_80099FE4(void *);
extern void func_80099728(void *);
extern void func_80074E5C(char *, int);
extern volatile int D_800F2724;
extern volatile int D_800F2728;
extern char D_800F2AD8[];
extern char D_800F26E0[];

void func_800E27B8(char *obj)
{
    unsigned char i;

    D_800F2724 = 0;
    D_800F2728 = 0;
    func_800BC274(D_800F2AD8);
    func_800AACB0(D_800F26E0, 0, 2);
    func_800AACB0(D_800F26E0, 0, 1);
    func_80099FE4(obj + 20560);
    func_80099728(obj + 20560);
    for (i = 0; i < 8; i++) {
        func_80074E5C(obj, i);
    }
}
