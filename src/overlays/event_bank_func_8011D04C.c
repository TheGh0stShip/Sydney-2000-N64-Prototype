extern int func_80013E7C(void *name, int *out, int flags);
extern void func_800AED04(void *object);
extern char D_80080AA8[];
extern char D_80080ACC[];

void func_8011D04C(unsigned char *object)
{
    int out;

    out = 0;
    *(int *)(object + 292) = 0;
    *(int *)(object + 292) = func_80013E7C(D_80080AA8, &out, 0);
    *(int *)(object + 296) = 0;
    *(int *)(object + 296) = func_80013E7C(D_80080ACC, &out, 0);
    *(int *)(object + 196) = *(int *)(object + 292);
    func_800AED04(object + 212);
    *(int *)(object + 192) = (*(int *)(object + 192) | 0x604) & ~1;
}
