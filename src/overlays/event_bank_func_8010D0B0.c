extern int func_800DAC28(int id);
extern void func_800140A0(void *entry, int id, int flags);
extern void **D_8007AC70[];

void func_8010D0B0(int kind, int id)
{
    int arg = id;

    if (kind == 12) {
        arg = -1;
    }
    func_800140A0(D_8007AC70[kind][func_800DAC28(id)], arg, 0);
}
