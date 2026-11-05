extern char D_800FE300[];
extern int D_800FE320;
extern void func_800E9290(void);
extern void func_800B18BC(void *object, void *table, int a, int b, int c, int d);

int func_800E5078(void *object)
{
    func_800E9290();
    D_800FE320 = 39;
    func_800B18BC(object, D_800FE300, 1, 1, 0, 0);
    return 39;
}
