extern unsigned char *func_800EA114(void *object, int index);

void func_800ED820(unsigned char *object, const float *position, float strength)
{
    unsigned char *entry = func_800EA114(object + 248, -1);
    *(float *)(entry + 12) = position[0];
    *(float *)(entry + 16) = position[1];
    *(float *)(entry + 20) = position[2];
    *(int *)(entry + 4) = 1920;
    *(unsigned short *)(entry + 2) = 30;
    *(float *)(entry + 36) = strength;
    *(void **)(entry + 8) = 0;
    entry[0] = 1;
    entry[1] = 0;
}
