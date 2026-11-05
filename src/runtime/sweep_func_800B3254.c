void func_800B3254(unsigned char *list, int mask)
{
    unsigned char *node = *(unsigned char **)(list + 8);
    unsigned char *next;
    int kind = 61;
loop:
    if (node == 0) {
        return;
    }
    next = *(unsigned char **)(node + 12);
    if (*(int *)node == kind) {
        *(int *)(node + 192) |= mask;
    }
    node = next;
    goto loop;
}
