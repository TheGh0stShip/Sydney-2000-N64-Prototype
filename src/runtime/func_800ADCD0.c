void func_800ADCD0(unsigned char *object, unsigned char *state,
                   float first, float second, float *position)
{
    if (*(int *)(object + 0xD0) != 0) {
        float *copy;
        float zero = 0.0f;
        state[0x24] = 4;
        *(short *)(state + 0x26) = -1;
        *(float *)(state + 0x44) = first;
        *(float *)(state + 0x40) = second;
        *(float *)(state + 0x20) = zero;
        *(float *)(state + 0x1C) = zero;
        *(float *)(state + 0x18) = zero;
        *(float *)(state + 0x14) = zero;
        *(float *)(state + 0x10) = zero;
        *(float *)(state + 0x0C) = zero;
        *(float *)(state + 0x08) = zero;
        *(float *)(state + 0x04) = zero;
        *(float *)(state + 0x00) = zero;
        copy = (float *)(state + 0x34);
        copy[0] = position[0];
        copy[1] = position[1];
        copy[2] = position[2];
    }
}
