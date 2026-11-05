extern char D_800898E0[];

int func_80019680(void *sprite, char *name);
void func_8001A1D8(void *sprite, float a, float b, float x, float y);
void func_8001A210(void *sprite, float a, float b, float sx, float sy, int flags);
void func_80019338(void *sprite, int r, int g, int b, int a);

void func_800CCD60(unsigned char *object)
{
    void *sprite = object + 196;
    float *vel;

    func_80019680(sprite, D_800898E0);
    func_8001A1D8(sprite, 0.0f, 0.0f, 48.0f, 26.0f);
    func_8001A210(sprite, 0.0f, 0.0f, 1.0f, 1.0f, 0);
    func_80019338(sprite, 255, 255, 255, 200);
    object[201] = 2;
    *(int *)(object + 192) |= 0x20000;
    object[176] = 1;
    *(int *)(object + 192) |= 2;
    vel = (float *)(object + 96);
    vel[16] = 0.0f;
    vel[17] = 0.0f;
    vel[18] = 0.0f;
    *(int *)(object + 192) |= 4;
}
