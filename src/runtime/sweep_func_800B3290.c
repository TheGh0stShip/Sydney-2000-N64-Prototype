void func_800B3290(unsigned char *list, unsigned char value)
{
    unsigned char *node = *(unsigned char **)(list + 8);
    unsigned char *next;
    int kind = 61;
    int bit = 0x20000;
loop:
    if (node == 0) {
        return;
    }
    next = *(unsigned char **)(node + 12);
    if (*(int *)node == kind) {
        node[201] = value;
        *(int *)(node + 192) |= bit;
    }
    node = next;
    goto loop;
}
