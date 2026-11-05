extern int D_800F2770;
extern void func_8009FD40(void *object, int size);
extern void func_800A0BA8(void *object);

void func_800A0ECC(unsigned char *object)
{
    func_8009FD40(object + 244, 256);
    if (D_800F2770 != 0) {
        func_800A0BA8(object);
    }
}
