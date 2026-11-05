extern void func_800B0F60(void *resource);

void func_800DCB88(unsigned char *object)
{
    if (*(int *)(object + 172) == 3) {
        unsigned char *entry = *(unsigned char **)(object + 444);
        if (entry != 0) {
            unsigned short identifier = *(unsigned short *)(entry + 14);
            if (identifier != object[475]) {
                *(unsigned short *)(entry + 434) = identifier + 224;
                func_800B0F60(*(void **)(entry + 416));
                object[475] = identifier;
            }
        }
    }
}
