extern void func_800A9BE8(void *object, int id);
extern unsigned char D_80083BF0[][13];

void func_80126BB8(unsigned char *object, unsigned char index)
{
    if (object[426] != 4 && index < 13) {
        func_800A9BE8(object + 1048, D_80083BF0[*(int *)(object + 740)][index]);
    }
}
