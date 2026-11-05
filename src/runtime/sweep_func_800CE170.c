typedef struct {
    short offset;
    short pad;
    void (*fn)(void *);
} Method;

typedef struct {
    unsigned char data[180];
    unsigned char *vtable;
    unsigned char rest[28];
} Part;

void func_800CE170(Part *object)
{
    unsigned int i;

    for (i = 0; i < 8; i++) {
        Method *m = (Method *)(object[i + 1].vtable + 64);
        m->fn((unsigned char *)&object[i + 1] + m->offset);
    }
}
