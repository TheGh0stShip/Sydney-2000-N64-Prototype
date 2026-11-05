extern unsigned char *func_800EA114(void *object, int index);

void func_800ED7E0(unsigned char *object, int enabled)
{
    unsigned char *entry;
    if (enabled != 0) {
        entry = func_800EA114(object + 192, 0);
        *(int *)(entry + 4) = 1920;
        *(unsigned short *)(entry + 2) = 0;
        *(void **)(entry + 8) = 0;
        entry[0] = 1;
        entry[1] = 0;
    }
}
