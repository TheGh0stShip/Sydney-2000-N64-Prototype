extern unsigned char *D_800FC270;
extern unsigned char D_800F40FC;
extern unsigned char D_800F4124[];
extern unsigned char D_800F4130[];
extern void func_800C4738(void *arg);

void func_800C6D74(void *arg)
{
    unsigned int i;

    D_800FC270[508] = 0;
    D_800F40FC = 0;
    for (i = 0; i < 12; i++) {
        D_800F4124[i] = 0;
        D_800F4130[i] = 0;
    }
    func_800C4738(arg);
}
