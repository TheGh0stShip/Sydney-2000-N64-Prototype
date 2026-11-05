extern void func_800C39F8(void *node, void *counter);

void func_800DCBEC(unsigned char *object)
{
    unsigned char *node;
    int kind = 63;

    *(int *)(object + 484) += 1;
    node = *(unsigned char **)(object + 8);
loop:
    if (node != 0) {
        if (*(int *)node == kind) {
            func_800C39F8(node, object + 484);
        }
        node = *(unsigned char **)(node + 12);
        goto loop;
    }
}
