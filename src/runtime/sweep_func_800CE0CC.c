void func_800CE0CC(unsigned char *object, unsigned char value)
{
    unsigned char *node = *(unsigned char **)(object + 8);
    unsigned char *next;
    int kind = 61;

loop:
    if (node != 0) {
        next = *(unsigned char **)(node + 12);
        if (*(int *)node == kind) {
            node[203] = value;
        }
        node = next;
        goto loop;
    }
}
