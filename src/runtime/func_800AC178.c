extern float D_80085E60;

int func_800AC178(void *unused0, void *unused1, unsigned char *state)
{
    float initial = D_80085E60;
    int result = 1;

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
    *(float *)(state + 0x00) = initial;
    return result;
}
