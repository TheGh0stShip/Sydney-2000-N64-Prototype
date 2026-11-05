typedef struct {
    char pad[24];
    short count;
} Info;

void func_800B972C(char *obj, float value, int index)
{
    Info *info;
    int i;

    if (value < 0.0f) {
        return;
    }
    if (1.0f < value) {
        return;
    }
    info = *(Info **)(obj + 244);
    if (index == -1) {
        for (i = 0; i < info->count; i++) {
            (*(float **)(obj + 340))[i] = 1.0f - value;
        }
    } else if (index >= 0 && index < info->count) {
        (*(float **)(obj + 340))[index] = 1.0f - value;
    }
}
