extern unsigned char *func_800AB640(void *pool);

void func_800AB9B8(unsigned char *list, unsigned char *item)
{
    unsigned char *node;
    unsigned char *tail;
    if (*(int *)(item + 4) == 0) {
        node = func_800AB640(list);
        if (node != 0) {
            *(unsigned char **)(node + 0) = item;
            *(int *)(node + 4) = *(int *)(list + 20);
            *(int *)(node + 8) = 0;
            tail = *(unsigned char **)(list + 20);
            if (tail != 0) {
                *(unsigned char **)(tail + 8) = node;
            }
            *(unsigned char **)(list + 20) = node;
        }
    }
}
