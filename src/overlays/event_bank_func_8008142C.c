extern unsigned char D_800F26E0[];
extern int D_800F2744;
extern void func_800AB2A4(void *list, int value, int count, void *object,
                          int fifth, int sixth);

void func_8008142C(unsigned char *object)
{
    object[0x8000 + 3224] = 0;
    object[0x8000 + 3225]++;
    func_800AB2A4(D_800F26E0, D_800F2744, 24, object, 0, 0);
}
