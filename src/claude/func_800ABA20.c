extern char D_800F2758[];
extern void func_800AB708(void *obj, char *name, unsigned short arg);

void func_800ABA20(char *obj, unsigned short arg)
{
    func_800AB708(obj, D_800F2758, arg);
    *(int *)(obj + 0x18) = 0;
}
