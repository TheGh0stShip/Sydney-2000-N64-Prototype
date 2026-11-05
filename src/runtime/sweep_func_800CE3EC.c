typedef struct {
    short offset;
    short pad;
    void (*fn)(void *);
} Method;

void func_800CE3EC(unsigned char *object, int *msg)
{
    Method *m;

    switch (msg[0]) {
    case 5:
        m = (Method *)(*(unsigned char **)(object + 180) + 32);
        m->fn(object + m->offset);
        break;
    case 7:
        m = (Method *)(*(unsigned char **)(object + 180) + 24);
        m->fn(object + m->offset);
        break;
    }
    *(int *)(object + 16) = msg[1];
}
