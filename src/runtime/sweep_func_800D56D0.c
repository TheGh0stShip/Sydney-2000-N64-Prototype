extern void func_800AB2A4(void *a, int b, int c, void *d, int e, int f);
extern unsigned char *func_800DCCF4(void *p);
extern unsigned char D_800F26E0[];
extern int D_800F2744;

void func_800D56D0(unsigned char *object, short value, unsigned short id)
{
    if (*(void **)(object + 2780) != 0) {
        func_800AB2A4(D_800F26E0, D_800F2744, 7, *(void **)(object + 2780), 0, id);
        *(short *)(func_800DCCF4(*(void **)(object + 2780)) + 18) = value;
    }
}
