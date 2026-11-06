typedef struct {
    char pad[25012];
    signed char b[8];
    int a[8];
} Obj800DB474;

void func_800DB474(Obj800DB474 *obj)
{
    unsigned char i;

    for (i = 0; i < 8; i++) {
        obj->a[i] = 0;
        obj->b[i] = -1;
    }
}
