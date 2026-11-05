extern unsigned char D_800F3BC0[];
extern void func_800C0110(void *object, int sound, int volume, int pitch);
extern void func_800CC418(void *object);

void func_800A08CC(unsigned char *object)
{
    int state = object[24041];

    if (state != 4 && state != 2 && state != 3) {
        func_800C0110(D_800F3BC0, 219, 0, 0);
        state = object[24041];
    }
    if (state != 5 && state != 1 && state != 2 &&
        (*(unsigned char **)(object + 23712))[426] == 1) {
        func_800CC418(object + 21524);
    }
}
