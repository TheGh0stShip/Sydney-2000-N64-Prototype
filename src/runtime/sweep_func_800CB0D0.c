extern void func_8001A248(void *p);

typedef struct {
    short offset;
    short pad;
    void (*fn)(void *);
} Method;

void func_800CB0D0(unsigned char *object)
{
    unsigned char i;

    for (i = 0; i < 5; i++) {
        int off = i * 212;
        Method *m = (Method *)(*(unsigned char **)(object + 2064 + off) + 72);
        unsigned char *part = object + (off + 1884);

        m->fn(part + m->offset);
        func_8001A248(part + 196);
    }
}
