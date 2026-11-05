typedef struct {
    short x;
    short y;
    short z;
    short h;
    int value;
    unsigned char pad;
    unsigned char kind;
} Placement;

extern void func_800C0750(void *object, float x, float y, float z, float h,
                          int kind, int value);

void func_800C0AD4(unsigned char *object, int id, Placement *placement)
{
    float x;
    float y;
    float z;
    float h;

    *(int *)(object + 212) = id;
    *(int *)(object + 172) = 1;
    y = placement->y;
    h = placement->h;
    x = placement->x;
    z = placement->z;
    *(float *)(object + 224) = y + h;
    func_800C0750(object, x, y, z, h, placement->kind, placement->value);
}
