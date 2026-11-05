extern int D_800F2770;
extern void func_8009FD40(void *object, int size);
extern void func_80081238(void *object);

void func_80120930(unsigned char *object)
{
    func_8009FD40(object + 260, 256);
    if (D_800F2770 != 0) {
        func_80081238(object);
    }
}
