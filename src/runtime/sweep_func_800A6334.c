extern char D_800F2758[];
extern void func_800AC308(char *);
extern void func_800ADE84(char *, int);
extern void func_800AA658(void *, void *);
extern void func_80017860(int);
void func_800A6334(char *obj)
{
    char *info = *(char **)(obj + 184);
    unsigned int i;
    if (info != 0) {
        for (i = 0; i < *(unsigned int *)(*(char **)(obj + 184) + 8); i++) {
            func_800AC308(*(char **)(obj + 188) + i * 212);
            func_800ADE84(*(char **)(obj + 188) + i * 212, 2);
        }
        func_800AA658(D_800F2758, obj + 188);
        func_80017860(1);
    }
}
