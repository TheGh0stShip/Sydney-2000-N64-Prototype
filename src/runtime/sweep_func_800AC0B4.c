extern int D_800F271C;
extern char D_800F3BC0[];
extern void func_800C013C(void *);
extern void func_8001DF58(int);
void func_800AC0B4(void)
{
    int id;
    func_800C013C(D_800F3BC0);
    switch (D_800F271C) {
    case 6: id = 192; break;
    case 2: id = 200; break;
    case 3: id = 202; break;
    case 4: id = 207; break;
    case 7: id = 208; break;
    case 5: id = 198; break;
    case 0: id = 223; break;
    default: id = 201; break;
    }
    func_8001DF58(id);
}
