extern unsigned char D_800F2758[];
extern void func_800AA658(void *list, void *item);

void func_800A02C0(unsigned char *object)
{
    if (*(int *)(object + 196) != 0) {
        func_800AA658(D_800F2758, object + 196);
    }
    if (*(int *)(object + 204) != 0) {
        func_800AA658(D_800F2758, object + 204);
    }
}
