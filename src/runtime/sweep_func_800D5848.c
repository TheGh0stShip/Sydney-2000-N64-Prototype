typedef struct {
    short offset;
    short pad;
    void (*fn)(void *);
} Method;

void func_800D5848(unsigned char *object, int *msg)
{
    if (msg[0] == 7) {
        unsigned char *child = *(unsigned char **)(object + 640);
        if (child != 0) {
            Method *m = (Method *)(*(unsigned char **)(child + 180) + 48);
            m->fn(child + m->offset);
        }
    }
    *(int *)(object + 16) = msg[1];
}
