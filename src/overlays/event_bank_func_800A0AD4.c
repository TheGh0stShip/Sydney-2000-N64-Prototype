extern unsigned char D_800F3BC0[];
extern void func_800C0110(void *object);

void func_800A0AD4(unsigned char *object)
{
    unsigned char state = object[24041];

    if (state != 4 && state != 2 && state != 3) {
        func_800C0110(D_800F3BC0);
    }
}
