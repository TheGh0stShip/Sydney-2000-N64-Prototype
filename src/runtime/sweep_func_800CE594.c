extern void func_8001A248(void *p);
extern int D_800F4920[];

void func_800CE594(void)
{
    unsigned char i;

    for (i = 0; i < 8; i++) {
        int *p = &D_800F4920[i];
        if (*p != 0) {
            func_8001A248(p);
            *p = 0;
        }
    }
}
