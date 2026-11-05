extern void func_800AB2A4(void *list, int a, int b, int c, int d, int e);
extern int D_800F2744;
extern unsigned char D_800F26E0[];

void func_800AE17C(unsigned char *object)
{
    if (*(int *)(object + 184) != 0 && *(int *)(object + 192) == 0) {
        if (*(int *)(object + 188) != 0) {
            func_800AB2A4(D_800F26E0, D_800F2744, 11, *(int *)(object + 184), 0, 3);
        }
    }
    *(int *)(object + 192) = 1;
}
