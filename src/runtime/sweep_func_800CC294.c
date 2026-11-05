void func_800CC294(char *obj, int a, int b, int mode)
{
    *(int *)(obj + 1912) = a;
    *(int *)(obj + 1916) = b;
    if (*(int *)(obj + 1912) < *(int *)(obj + 1916)) {
        obj[1927] |= 0x10;
    } else {
        obj[1927] &= ~0x10;
    }
    if (mode == 1) {
        obj[1927] = (obj[1927] & ~0x20) | 0x01;
    } else if (mode == 0) {
        obj[1927] &= ~0x21;
    } else {
        obj[1927] = (obj[1927] & ~0x01) | 0x20;
    }
    obj[1927] &= ~0x04;
}
