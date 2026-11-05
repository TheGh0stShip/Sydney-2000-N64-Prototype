extern void func_8001A248(void *p);

typedef struct {
    short offset;
    short pad;
    void (*fn)(void *);
} Method;

void func_800CB034(unsigned char *object)
{
    unsigned char i;

    for (i = 0; i < 3; i++) {
        int off = i * 212;

        if (*(int *)(object + off + 1020) != 0) {
            Method *m = (Method *)(*(unsigned char **)(object + off + 1004) + 72);
            unsigned char *part = object + (off + 824);

            m->fn(part + m->offset);
            func_8001A248(part + 196);
        }
    }
}
