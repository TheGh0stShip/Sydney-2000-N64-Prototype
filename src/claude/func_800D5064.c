extern char D_800F2AD8[];
extern void func_800BBD14(void *a, void *b);
extern void func_800BBD78(void *a, int b, int c, void *d, int e);
extern void func_800BC180(void *a);

void func_800D5064(char *obj)
{
    if (*(int *)(obj + 0x284) == 1) {
        *(int *)(obj + 0x284) = 2;
        func_800BBD14(D_800F2AD8, obj + 0x80C);
        func_800BBD78(D_800F2AD8, 0xD, 1, obj, 0);
        func_800BBD78(D_800F2AD8, 0xC, 1, obj, 0);
        func_800BC180(D_800F2AD8);
        func_800BBD78(D_800F2AD8, 0xD, 0, obj, 3);
    }
}
