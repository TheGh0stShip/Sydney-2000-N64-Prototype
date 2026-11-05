extern int D_800F2770;
extern void func_8009FD40(void *object, int size);
extern void func_800A27CC(void *object);

void func_800A2B3C(unsigned char *object)
{
    func_8009FD40(object + 240, 256);
    if (D_800F2770 != 0) {
        func_800A27CC(object);
    }
}
