extern float D_800897A0;

void func_800CB838(unsigned char *object, float amount)
{
    if (*(int *)(object + 0xC4) != 0) {
        unsigned char *state = object + 0x60;
        float initial = D_800897A0;

        *(int *)(state + 0x24) = 0;
        *(int *)(state + 0x20) = 0;
        *(int *)(state + 0x18) = 0;
        *(int *)(state + 0x10) = 0;
        *(int *)(state + 0x08) = 0;
        *(int *)(state + 0x04) = 0;
        *(int *)(state + 0x48) = 0;
        *(int *)(state + 0x44) = 0;
        *(int *)(state + 0x40) = 0;
        *(float *)(state + 0x28) = initial;
        *(float *)(state + 0x14) = initial;
        *(int *)(object + 0xAC) = 1;
        *(float *)(object + 0x60) = initial;
        *(int *)(object + 0xA0) = 0;
        *(float *)(object + 0xA4) = amount;
        *(int *)(object + 0xA8) = 0;
        *(int *)(object + 0xC0) |= 0x400000;
    }
}
