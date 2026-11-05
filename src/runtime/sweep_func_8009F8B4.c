extern char D_80084B58[];
extern char D_80084BD8[];
extern void func_8009F84C(char *);
extern void func_800ADC1C(char *);
extern void func_800D3460(char *, int);
extern void func_800ADE84(char *, int);
void func_8009F8B4(char *obj, int mode)
{
    *(char **)(obj + 180) = D_80084B58;
    func_8009F84C(obj);
    func_800ADC1C(obj + 940);
    func_800D3460(obj + 1204, 2);
    func_800ADE84(obj + 940, 2);
    func_800ADE84(obj + 700, 2);
    func_800ADE84(obj + 476, 2);
    {
        char *sub = obj + 212;
        *(char **)(sub + 180) = D_80084BD8;
        func_800ADE84(sub, 2);
    }
    func_800ADE84(obj, mode);
}
