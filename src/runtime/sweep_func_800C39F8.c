extern float D_800F4060[];

void func_800C39F8(unsigned char *self, unsigned int *index)
{
    if (*index >= 28) {
        *index = 0;
    }
    if (*(int *)(self + 852) & 2) {
        if (*(int *)(*(unsigned char **)(self + 220) + 4) == 27) {
            *(float *)(*(unsigned char **)(self + 716) + 160) -= D_800F4060[*index];
            *(float *)(*(unsigned char **)(self + 720) + 160) += D_800F4060[*index];
        } else {
            *(float *)(*(unsigned char **)(self + 712) + 160) -= D_800F4060[*index];
            *(float *)(*(unsigned char **)(self + 716) + 160) += D_800F4060[*index];
        }
    }
}
