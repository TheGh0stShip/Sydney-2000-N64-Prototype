extern unsigned char D_800F2758[];
extern void func_800AA658(void *list, void *item);

void func_8008DB60(unsigned char *object)
{
    if (*(int *)(object + 412) != 0) {
        func_800AA658(D_800F2758, object + 412);
    }
    if (*(int *)(object + 404) != 0) {
        func_800AA658(D_800F2758, object + 404);
    }
}
