extern int D_800F2744;

void func_800BB788(unsigned char *object, unsigned char *input)
{
    if (*(int *)(input + 0x00) & 0x001) {
        float *source = (float *)(input + 0x04);
        float *destination = (float *)(object + 0x178);
        destination[0] = source[0];
        destination[1] = source[1];
        destination[2] = source[2];
    }
    if (*(int *)(input + 0x00) & 0x020) {
        if (*(int *)(input + 0x4C) == 0) {
            *(int *)(object + 0xBC) = 0;
        }
        *(int *)(object + 0xE8) = D_800F2744 + *(int *)(input + 0x4C);
    }
    if (*(int *)(input + 0x00) & 0x400) {
        *(unsigned short *)(object + 0xC4) = *(unsigned short *)(input + 0x64);
    }
    if (*(int *)(input + 0x00) & 0x800) {
        *(float *)(object + 0xFC) = *(float *)(input + 0x60);
    }
    if (*(int *)(input + 0x00) & 0x200) {
        *(float *)(object + 0xF4) = *(float *)(input + 0x5C);
    }
    if (*(int *)(input + 0x00) & 0x100) {
        *(float *)(object + 0xF8) = *(float *)(input + 0x58);
    }
}
