typedef struct {
    unsigned char pad[64];
    float x;
    float y;
    int z;
} Body;

void func_800CC448(unsigned char *object, short x, short y)
{
    float fx = x;
    Body *b = (Body *)(object + 96);

    b->x = fx;
    b->y = y;
    b->z = 0;
}
