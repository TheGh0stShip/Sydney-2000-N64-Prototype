extern void func_800E9290(void *obj);
extern void func_800B18BC(void *obj, void *desc, int a, int b, int c, int d);
extern char D_800FDEF4[];

int func_800E5120(void *obj) {
    func_800E9290(obj);
    func_800B18BC(obj, D_800FDEF4, 1, 1, 0, 0);
    return 38;
}
