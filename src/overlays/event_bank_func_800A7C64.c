extern unsigned char D_800F3BC0[];
extern void func_800C0110(void *object);

void func_800A7C64(unsigned char *object)
{
    unsigned char state = object[31919];

    if (state != 3 && state != 4) {
        func_800C0110(D_800F3BC0);
    }
}
