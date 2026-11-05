typedef struct {
    unsigned char pad[32];
    short offset;
    short pad2;
    void (*fn)(void *);
} VTable;

void func_800CEEC8(unsigned char *object, int *msg)
{
    if (msg[0] == 5) {
        VTable *vt = *(VTable **)(object + 180);
        vt->fn(object + vt->offset);
    }
    *(int *)(object + 16) = msg[1];
}
