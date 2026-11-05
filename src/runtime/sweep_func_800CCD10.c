extern void func_800ADC54(void *object, int arg);

typedef struct {
    unsigned char pad[64];
    float x;
    float y;
    int z;
} Body;

void func_800CCD10(unsigned char *object, int a, int b, int arg)
{
    Body *body;

    func_800ADC54(object, arg);
    body = (Body *)(object + 96);
    body->x = 507.0f;
    body->y = 200.0f;
    body->z = 0;
    *(int *)(object + 212) = 3840;
}
