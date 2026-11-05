extern int func_800B1968(void *);
extern void func_800B3870(void *, void *, int);
extern void func_800BBE18(void);
extern void func_800DAB98(void);
extern void func_800DA720(void);
extern void func_80007880(int, void *, int);
extern void func_800B18BC(void *, void *, int, int, int, int);
extern char *D_800FC270;
extern char D_800F6CFC[];
extern char D_800F6554[];

int func_800D6AF4(void *obj)
{
    switch (func_800B1968(obj)) {
    case 1:
        func_800B3870(D_800FC270 + 3404, D_800F6CFC, 1348);
        func_800BBE18();
        func_800DAB98();
        break;
    case 2:
        break;
    case 3:
        func_800DA720();
        func_80007880(0, D_800FC270, 4752);
        break;
    }
    func_800B18BC(obj, D_800F6554, 1, 3, 0, 0);
    return 9;
}
