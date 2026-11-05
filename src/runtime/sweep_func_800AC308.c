void func_800AC308(unsigned char *list)
{
    unsigned char *node = *(unsigned char **)(list + 8);
    unsigned char *next;
    *(int *)(list + 8) = 0;
loop:
    if (node == 0) {
        return;
    }
    next = *(unsigned char **)(node + 12);
    *(int *)(node + 4) = 0;
    *(int *)(node + 12) = 0;
    node = next;
    goto loop;
}
