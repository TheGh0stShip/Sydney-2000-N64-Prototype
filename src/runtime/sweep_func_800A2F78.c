extern void func_8001E0FC(void *, int);
extern void func_8001D870(void *, int);
extern char D_800F1B84[];
extern char D_800F1AE0[];

void func_800A2F78(void)
{
    int index;

    func_8001E0FC(D_800F1B84, 2);
    index = 1;
    func_8001D870(&D_800F1AE0[index], 0);
}
