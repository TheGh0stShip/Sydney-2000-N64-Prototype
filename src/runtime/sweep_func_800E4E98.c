extern unsigned char *D_800FC270;
extern unsigned char D_800F5900[];
extern unsigned char D_800F2AD8[];
extern void func_800D9990(void);
extern void func_800E9774(int value);
extern void func_800D53A0(void *data, int mode);
extern void func_800BC180(void *data);

void func_800E4E98(unsigned char *object, int unused, int value)
{
    unsigned int i;

    if (value != 0) {
        *(int *)(object + 184) = value;
        func_800D9990();
        for (i = 0; i < 8; i++) {
            *(signed char *)(D_800FC270 + i + 500) = -1;
        }
        *(short *)(D_800FC270 + 2524) = 0;
        func_800E9774(*(int *)(object + 184));
        func_800D53A0(D_800F5900, 22);
        func_800BC180(D_800F2AD8);
        *(int *)(object + 172) = 0;
    }
}
