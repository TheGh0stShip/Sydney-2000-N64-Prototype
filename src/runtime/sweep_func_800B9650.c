typedef struct {
    char pad[24];
    short count;
} Info;

extern char D_800F2758[];

int func_800AA804(void *heap, void *slot, int size, char *name);

int func_800B9650(char *obj)
{
    Info *info = *(Info **)(obj + 244);
    int i;

    if (func_800AA804(D_800F2758, obj + 344, info->count * 4, "MinBulge") != 0) {
        return 0;
    }
    if (func_800AA804(D_800F2758, obj + 348, info->count * 4, "MaxBulge") != 0) {
        return 0;
    }
    for (i = 0; i < info->count; i++) {
        (*(float **)(obj + 344))[i] = 1.0f;
        (*(int **)(obj + 348))[i] = 0;
        (*(int **)(obj + 340))[i] = 0;
    }
    *(int *)(obj + 332) = 1;
    return 1;
}
