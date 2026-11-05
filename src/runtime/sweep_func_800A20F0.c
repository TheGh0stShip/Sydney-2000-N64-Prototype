struct VEntry {
    short offset;
    short pad;
    void (*func)(void *object);
};
extern void func_800A18C4();

void func_800A20F0(unsigned char *object, int *message)
{
    struct VEntry *vt;

    switch (message[0]) {
    case 3:
        break;
    case 5:
        func_800A18C4();
        vt = *(struct VEntry **)(object + 180);
        vt[4].func(object + vt[4].offset);
        break;
    }
    *(int *)(object + 16) = message[1];
}
