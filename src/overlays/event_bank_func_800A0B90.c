extern void func_800D2544(void *object, unsigned short value);

void func_800A0B90(unsigned char *object, unsigned short value)
{
    if ((*(unsigned char **)(object + 23712))[426] == 1 &&
        object[24041] != 5 && object[24041] != 2) {
        func_800D2544(object + 18068, value);
    }
}
