extern int D_80071704[];
extern unsigned char D_800F3BC0[];
extern signed char func_8009B670(int value);
extern void func_800C0110(void *object, int sound, int volume, int pitch);

void func_800A7B28(unsigned char *object)
{
    int sound;
    signed char index;
    unsigned char state;

    if (object[31919] != 3) {
        index = func_8009B670(*(int *)(object + 12212));
        sound = D_80071704[index];
        state = object[31919];
        if (state != 3 && state != 4) {
            func_800C0110(D_800F3BC0, sound, 7680, 0x12C00);
        }
        *(int *)(object + 31936) += 0xB400;
    }
}
