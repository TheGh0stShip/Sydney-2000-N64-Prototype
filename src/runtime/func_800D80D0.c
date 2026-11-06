void func_800D80D0(unsigned char *list)
{
    int i = 0;

    for (;;) {
        unsigned int index = (unsigned char)i;
        unsigned char *slot;
        unsigned char *node;
        if (index >= 30) {
            break;
        }
        slot = list + index * 4;
        node = *(unsigned char **)(slot + 0xE8);
        if (node != 0) {
            unsigned char *child;
            *(unsigned int *)(node + 0xC0) =
                (*(unsigned int *)(node + 0xC0) & ~0x600) | 0x02000000;
            child = *(unsigned char **)(node + 0x1F4);
            if (child != 0) {
                *(unsigned int *)(child + 0xC0) =
                    (*(unsigned int *)(child + 0xC0) & ~0x600) | 0x02000000;
            }
            child = *(unsigned char **)(node + 0x1F8);
            if (child != 0) {
                *(unsigned int *)(child + 0xC0) =
                    (*(unsigned int *)(child + 0xC0) & ~0x600) | 0x02000000;
            }
            child = *(unsigned char **)(slot + 0xE8);
            *(unsigned int *)(child + 0xC0) =
                (*(unsigned int *)(child + 0xC0) & ~0x600) | 0x02000000;
        }
        i++;
    }
}
