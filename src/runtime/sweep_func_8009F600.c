struct VTable {
    char pad[16];
    short offset2;
    short pad2;
    void (*func2)(void *object, int arg);
    short offset3;
    short pad3;
    void (*func3)(void *object);
};

void func_8009F600(unsigned char *object, int arg)
{
    struct VTable *vt;

    vt = *(struct VTable **)(object + 180);
    vt->func3(object + vt->offset3);
    vt = *(struct VTable **)(object + 180);
    vt->func2(object + vt->offset2, arg);
    *(int *)(object + 1160) = 1;
}
